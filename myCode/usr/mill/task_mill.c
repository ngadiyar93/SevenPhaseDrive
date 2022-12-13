#ifdef APP_MILL

#include "usr/mill/task_mill.h"
#include "usr/user_config.h"
#include <math.h>
#include <stdint.h>
#include "drv/pwm.h"
#include "drv/encoder.h"
#include "sys/scheduler.h"
#include "drv/motherboard.h"
#include "usr/mill/autogen/PMSMController.h"
#include "usr/rlCC/task_rlCC.h"

// Scheduler TCB which holds task "context"
static task_control_block_t tcb;

// Example logging variables for testing
double LOG_Iu = 0;
double LOG_Iv = 0;
double LOG_Iw = 0;
double LOG_speed = 0;
int polePairs = 8;
double speedRad = 0;
double LOG_speed_ref = 0;
double LOG_Id_ref = 0;
double LOG_Id_meas = 0;
double LOG_Iq_meas = 0;
double LOG_theta_m = 0;

static double Fs = 60000.0; // [sec]

int task_mill_init(void)
{
	  if (scheduler_tcb_is_registered(&tcb)) {
	        return FAILURE;
	    }

	    // Fill TCB with parameters
	    scheduler_tcb_init(&tcb, task_mill_callback, NULL, "mill", TASK_MILL_INTERVAL_USEC);
	    pwm_disable();
	    pwm_set_switching_freq(Fs);
		pwm_set_all_duty_midscale();
		pwm_enable();


	    // initialize autogen step
		PMSMController_U.I_a = 0;
		PMSMController_U.I_b = 0;
		PMSMController_U.I_c = 0;
		PMSMController_U.V_dc = 50;
		PMSMController_U.Id_ref = 0;

		PMSMController_initialize();
		encoder_set_pulses_per_rev_bits(14);

	    // Register task with scheduler
	    return scheduler_tcb_register(&tcb);
}

//int task_mill_deinit(void)
//{
       // Unregister task with scheduler
//    return scheduler_tcb_unregister(&tcb);
//}


int read_cs(cabinet_cs_e cs, double *adc_volts_out)
{
    int err = FAILURE;
    int32_t out = 0;

    switch (cs) {
    case CABINET_CS_SUS_U:
        err = motherboard_get_data(MOTHERBOARD_1_BASE_ADDR, MB_IN1, &out);
        *adc_volts_out = 0.00125 * (double) out;
        break;

    case CABINET_CS_SUS_V:
        err = motherboard_get_data(MOTHERBOARD_1_BASE_ADDR, MB_IN3, &out);
        *adc_volts_out = 0.00125 * (double) out;
        break;

    case CABINET_CS_SUS_W:
        err = motherboard_get_data(MOTHERBOARD_1_BASE_ADDR, MB_IN2, &out);
        *adc_volts_out = 0.00125 * (double) out;
        break;

    case CABINET_CS_TOR_U:
		err = motherboard_get_data(MOTHERBOARD_1_BASE_ADDR, MB_IN4, &out);
		*adc_volts_out = 0.00125 * (double) out;
		break;

	case CABINET_CS_TOR_V:
		err = motherboard_get_data(MOTHERBOARD_1_BASE_ADDR, MB_IN5, &out);
		*adc_volts_out = 0.00125 * (double) out;
		break;

	case CABINET_CS_TOR_W:
		err = motherboard_get_data(MOTHERBOARD_1_BASE_ADDR, MB_IN6, &out);
		*adc_volts_out = 0.00125 * (double) out;
		break;

    default:
        err = FAILURE;
    }

    // Magic delta value to deal with odd analog design... :(
    // Specific to CurrentCard design, perhaps VoltageCard as well.
    //
    // ==> at 0A input, the CurrentCard ADC voltage input is mid-rail,
    //     about 2.4V, and -FS current is about 0.2V, +FS is ~4.8V.
    //
    //     The binary ADC codes for these are odd, they go from
    //     negative to positive weirdly. I haven't debugged if
    //     this is actually correct of not... So, this DELTA value
    //     shifts them around to get a nice linear output
    //     relative to the current input value.
    double DELTA = (double) 0xFFFF * 0.00125 / 2.0;
    if (*adc_volts_out > 0) {
        *adc_volts_out -= DELTA;
    } else {
        *adc_volts_out += DELTA;
    }

    return err;
}

double static encoder_get_theta(void){

	uint32_t pos;
	encoder_get_position(&pos);

	double theta = 0;

	if (pos != -1){
		uint32_t bits = 14;
		uint32_t PPR = 1 << bits;
		theta = PI2*((double)pos / (double)PPR);
	}

	return theta;
}


static double read_encoder(void)
{
	// Change the encoder output to match the sign with positive torque
	// The gain variable is configured from CLI and is expected to be -1, 0 or 1.

	double theta_m_enc = enc_theta_m_gain * encoder_get_theta();
	theta_m_enc = theta_m_enc + theta_m_enc_offset_rad;

	while (theta_m_enc >= PI2)
	{ theta_m_enc -= PI2;

	}

	while(theta_m_enc < 0){
		theta_m_enc += PI2;
	}
return theta_m_enc;

}


void task_mill_callback(void *arg)
{

	// call the current controller

	 // Update theta
		double VaDuty, VbDuty, VcDuty;

		// get currents
		double Ia;
	    double Ib;
		double Ic;

		read_cs(CABINET_CS_SUS_U, &Ia);
		read_cs(CABINET_CS_SUS_V, &Ib);
		read_cs(CABINET_CS_SUS_W, &Ic);

		// scale currents
		PMSMController_U.I_a = (double)PHASE_A_CURRENT_GAIN*(Ia) - PHASE_A_CURRENT_OFFSET;
		PMSMController_U.I_b = (double)PHASE_B_CURRENT_GAIN*(Ib) - PHASE_B_CURRENT_OFFSET;
		PMSMController_U.I_c = (double)PHASE_C_CURRENT_GAIN*(Ic) - PHASE_C_CURRENT_OFFSET;

		// Input voltage. Replace with sensed voltage
		PMSMController_U.V_dc = 50;

		// Encoder input
		PMSMController_U.theta_m = read_encoder();
		LOG_theta_m = (double)PMSMController_U.theta_m;

		// Update logging variables
		LOG_Iu = (double) (PMSMController_U.I_a);
		LOG_Iv = (double) (PMSMController_U.I_b);
		LOG_Iw = (double) (PMSMController_U.I_c);
		LOG_Id_ref = (double)(PMSMController_U.Id_ref);
		LOG_speed_ref = (double)PMSMController_U.omega_ref*60/(2*PI*polePairs);
		LOG_speed = (double)PMSMController_Y.omega_e*60/(2*PI*polePairs);
		LOG_Id_meas = (double)PMSMController_Y.Id;
		LOG_Iq_meas = (double)PMSMController_Y.Iq;

		// execute code
		PMSMController_step();

		// assign duty cycle
		VaDuty = PMSMController_Y.normalizedvoltages[0];
		VbDuty = PMSMController_Y.normalizedvoltages[1];
		VcDuty = PMSMController_Y.normalizedvoltages[2];

		pwm_set_duty(3, VaDuty);
		pwm_set_duty(4, VbDuty);
		pwm_set_duty(5, VcDuty);


		// Log

}

//void task_mill_stats_print(void)
//{
//    task_stats_print(&tcb.stats);
//}
//
//void task_mill_stats_reset(void)
//{
//    task_stats_reset(&tcb.stats);
//}

#endif // APP_MILL
