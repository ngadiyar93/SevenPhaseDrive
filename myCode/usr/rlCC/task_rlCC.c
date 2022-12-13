#ifdef APP_RLCC

#include "usr/rlCC/task_rlCC.h"
#include "usr/user_config.h"
#include <math.h>
#include <stdint.h>
#include "drv/pwm.h"
#include "sys/scheduler.h"
#include "drv/motherboard.h"
#include "usr/rlCC/autogen/currentRegulator.h"
#include "drv/encoder.h"
#include "usr/encoderTest/task_encoderTest.h"


// Scheduler TCB which holds task "context"
static task_control_block_t tcb;

// Example logging variables for testing
double LOG_Ia = 0;
double LOG_Ib = 0;
double LOG_Ic = 0;
double LOG_Iq = 0;
double LOG_Id = 0;
double LOG_Iqref = 0;
double LOG_Idref = 0;
double LOG_theta_enc = 0;

static double f_sw = 60000.0; // [sec]
static double omega = 2*3.14*50;       // [rad/s]rlCC freq 50


int task_rlCC_init(void)
{
	  if (scheduler_tcb_is_registered(&tcb)) {
	        return FAILURE;
	    }

	    // Fill TCB with parameters
	    scheduler_tcb_init(&tcb, task_rlCC_callback, NULL, "rlCC", TASK_RLCC_INTERVAL_USEC);
	    pwm_disable();
	    pwm_set_switching_freq(f_sw);
		pwm_set_all_duty_midscale();
		pwm_enable();


	    // initialize autogen step
		currentRegulator_U.omega_e = omega;
		currentRegulator_U.I_a = 0;
		currentRegulator_U.I_b = 0;
		currentRegulator_U.I_c = 0;
		currentRegulator_U.V_dc = Vdc;
		currentRegulator_U.Id_ref = 0;
		currentRegulator_U.Iq_ref = 0;

		currentRegulator_initialize();
		encoder_set_pulses_per_rev_bits(14);

	    // Register task with scheduler
	    return scheduler_tcb_register(&tcb);
}

//int task_rlCC_deinit(void)
//{
       // Unregister task with scheduler
//    return scheduler_tcb_unregister(&tcb);
//}


//int read_cs(cabinet_cs_e cs, double *adc_volts_out)
//{
//    int err = FAILURE;
//    int32_t out = 0;
//
//    switch (cs) {
//    case CABINET_CS_SUS_U:
//        err = motherboard_get_data(MOTHERBOARD_1_BASE_ADDR, MB_IN1, &out);
//        *adc_volts_out = 0.00125 * (double) out;
//        break;
//
//    case CABINET_CS_SUS_V:
//        err = motherboard_get_data(MOTHERBOARD_1_BASE_ADDR, MB_IN3, &out);
//        *adc_volts_out = 0.00125 * (double) out;
//        break;
//
//    case CABINET_CS_SUS_W:
//        err = motherboard_get_data(MOTHERBOARD_1_BASE_ADDR, MB_IN2, &out);
//        *adc_volts_out = 0.00125 * (double) out;
//        break;
//
//    case CABINET_CS_TOR_U:
//		err = motherboard_get_data(MOTHERBOARD_1_BASE_ADDR, MB_IN4, &out);
//		*adc_volts_out = 0.00125 * (double) out;
//		break;
//
//	case CABINET_CS_TOR_V:
//		err = motherboard_get_data(MOTHERBOARD_1_BASE_ADDR, MB_IN5, &out);
//		*adc_volts_out = 0.00125 * (double) out;
//		break;
//
//	case CABINET_CS_TOR_W:
//		err = motherboard_get_data(MOTHERBOARD_1_BASE_ADDR, MB_IN6, &out);
//		*adc_volts_out = 0.00125 * (double) out;
//		break;
//
//    default:
//        err = FAILURE;
//    }
//
//    // Magic delta value to deal with odd analog design... :(
//    // Specific to CurrentCard design, perhaps VoltageCard as well.
//    //
//    // ==> at 0A input, the CurrentCard ADC voltage input is mid-rail,
//    //     about 2.4V, and -FS current is about 0.2V, +FS is ~4.8V.
//    //
//    //     The binary ADC codes for these are odd, they go from
//    //     negative to positive weirdly. I haven't debugged if
//    //     this is actually correct of not... So, this DELTA value
//    //     shifts them around to get a nice linear output
//    //     relative to the current input value.
//    double DELTA = (double) 0xFFFF * 0.00125 / 2.0;
//    if (*adc_volts_out > 0) {
//        *adc_volts_out -= DELTA;
//    } else {
//        *adc_volts_out += DELTA;
//    }
//
//    return err;
//}

void task_rlCC_callback(void *arg)
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
		currentRegulator_U.I_a = (double)PHASE_A_CURRENT_GAIN*(Ia) - PHASE_A_CURRENT_OFFSET;
		currentRegulator_U.I_b = (double)PHASE_B_CURRENT_GAIN*(Ib) - PHASE_B_CURRENT_OFFSET;
		currentRegulator_U.I_c = (double)PHASE_C_CURRENT_GAIN*(Ic) - PHASE_C_CURRENT_OFFSET;

		// Input voltage. Replace with sensed voltage
		currentRegulator_U.V_dc = Vdc;

		// Update logging variables
		LOG_Ia = (float) (currentRegulator_U.I_a);
		LOG_Ib = (float) (currentRegulator_U.I_b);
		LOG_Ic = (float) (currentRegulator_U.I_c);
		LOG_Id =(float)(currentRegulator_Y.Id);
		LOG_Iq = (float)(currentRegulator_Y.Iq);
		LOG_Iqref = (float)(currentRegulator_U.Iq_ref);
		LOG_Idref = (float)(currentRegulator_U.Id_ref);
		// execute code
		currentRegulator_step();

		// assign duty cycle
		VaDuty = currentRegulator_Y.normalizedvoltages[0];
		VbDuty = currentRegulator_Y.normalizedvoltages[1];
		VcDuty = currentRegulator_Y.normalizedvoltages[2];

		pwm_set_duty(3, VaDuty);
		pwm_set_duty(4, VbDuty);
		pwm_set_duty(5, VcDuty);
		LOG_theta_enc = read_encoder();

}

//void task_rlCC_stats_print(void)
//{
//    task_stats_print(&tcb.stats);
//}
//
//void task_rlCC_stats_reset(void)
//{
//    task_stats_reset(&tcb.stats);
//}

#endif // APP_RLCC
