#ifdef APP_BLINK

#include "usr/blink/task_vsi.h"
#include "drv/led.h"
#include "sys/scheduler.h"
#include <math.h>
#include "drv/pwm.h"
#include <stdint.h>
#include "usr/rlCC/task_rlCC.h"
#include "drv/motherboard.h"


// Scheduler TCB which holds task "context"
static task_control_block_t tcb;

// Example logging variables for testing
int LOG_task_vsi_runs = 0;
double LOG_vsi_a = 0;
double LOG_vsi_b = 0;
double LOG_vsi_c = 0;
double LOG_vsi_d = 0;
double LOG_vsi_e = 0;
double LOG_vsi_f = 0;
double LOG_aa = 0;
double LOG_bb = 0;
double LOG_cc = 0;

static double Ts = 1.0 / TASK_VSI_UPDATES_PER_SEC; // [sec]
static double theta = 0.0;        // [rad]
static double omega = 2*3.14*20;       // [rad/s]
static double Do = 0.4;          // [--]

void task_vsi_init(void)
{
    if (scheduler_tcb_is_registered(&tcb)) {
        return;
    }

    // Fill TCB with parameters
    scheduler_tcb_init(&tcb, task_vsi_callback, NULL, "vsi", TASK_VSI_INTERVAL_USEC);

    // Register task with scheduler
    scheduler_tcb_register(&tcb);
}

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


void task_vsi_callback(void *arg)
{
    LOG_task_vsi_runs += 1;

    // Update theta
    theta += (Ts * omega);
    theta = fmod(theta, 2.0 * M_PI); // Wrap to 2*pi

    // Calculate desired duty ratios
    double vsi_a = 0.5 + Do * cos(theta);
    double vsi_b = 0.5 + Do * cos(theta + 2.0 * M_PI / 3.0);
    double vsi_c = 0.5 + Do * cos(theta + 4.0 * M_PI / 3.0);

    pwm_set_duty(3, vsi_a);
    pwm_set_duty(4, vsi_b);
    pwm_set_duty(5, vsi_c);

	double Ia=0;
    double Ib=0;
	double Ic=0;
	double Id=0;
    double Ie=0;
	double If=0;

	read_cs(CABINET_CS_SUS_U, &Ia);
	read_cs(CABINET_CS_SUS_V, &Ib);
	read_cs(CABINET_CS_SUS_W, &Ic);


	LOG_vsi_a = (double)(PHASE_A_CURRENT_GAIN)*(Ia - PHASE_A_CURRENT_OFFSET);
	LOG_vsi_b = (double)(PHASE_B_CURRENT_GAIN)*(Ib - PHASE_B_CURRENT_OFFSET);
	LOG_vsi_c = (double)(PHASE_C_CURRENT_GAIN)*(Ic - PHASE_C_CURRENT_OFFSET);
	LOG_vsi_d = (double)(PHASE_A_CURRENT_GAIN)*(Id - PHASE_A_CURRENT_OFFSET);
	LOG_vsi_e = (double)(PHASE_B_CURRENT_GAIN)*(Ie - PHASE_B_CURRENT_OFFSET);
	LOG_vsi_f = (double)(PHASE_C_CURRENT_GAIN)*(If - PHASE_C_CURRENT_OFFSET);
	LOG_aa = Ia;
	LOG_bb = Ib;
	LOG_cc = Ic;

}

#endif // APP_BLINK
