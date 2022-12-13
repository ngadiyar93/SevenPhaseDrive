#ifdef APP_ENCODERTEST

#include "usr/encoderTest/task_encoderTest.h"
#include "usr/encoderTest/autogen/encoderSpeeedTest.h"
#include "drv/led.h"
#include "drv/encoder.h"
#include "sys/scheduler.h"
#include <stdint.h>

// Hold LED animation state
static uint8_t led_pos = 0;
static uint8_t led_color_idx = 0;
#define NUM_LED_COLORS (7)
double theta_enc = 0;
double LOG_theta_Encoder = 0;
double LOG_theta_e_Enc = 0;
double LOG_omega_Enc = 0;
double LOG_omega_e_Enc = 0;

// Scheduler TCB which holds task "context"
static task_control_block_t tcb;

int task_encoderTest_init(void)
{
    if (scheduler_tcb_is_registered(&tcb)) {
        return FAILURE;
    }

    // Fill TCB with parameters
    scheduler_tcb_init(&tcb, task_encoderTest_callback, NULL, "encoderTest", TASK_ENCODERTEST_INTERVAL_USEC);

    // Register task with scheduler
    return scheduler_tcb_register(&tcb);

    encoder_set_pulses_per_rev_bits(14);
}

int task_encoderTest_deinit(void)
{
    // Turn off all LEDs
    for (uint8_t i = 0; i < NUM_LEDS; i++) {
        led_set_color(i, LED_COLOR_BLACK);
    }

    // Reset state
    led_pos = 0;
    led_color_idx = 0;

    // Unregister task with scheduler
    return scheduler_tcb_unregister(&tcb);
}


double static encoder_get_theta(void)
{
	uint32_t pos;
	encoder_get_position(&pos);

	double theta = 0;

	if (pos!= -1){
		uint32_t bits = 14;
		uint32_t PPR = 1<<bits;
		theta = 2*PI*((double)pos/(double)PPR);
		return theta;
	}
}

 double read_encoder(void)
{
	double enc_gain = 1;
	double enc_offset_rad = 0;
	double theta_m_enc = enc_gain*encoder_get_theta();
	theta_m_enc += enc_offset_rad;

	while(theta_m_enc >= 2*PI) {
		theta_m_enc -= 2*PI;
	}

	while (theta_m_enc < 0){
		theta_m_enc += 2*PI;
	}

	return theta_m_enc;
}

void task_encoderTest_callback(void *arg)
{
	theta_enc = read_encoder();
	encoderSpeeedTest_U.theta_m = theta_enc;
	encoderSpeeedTest_step();
	LOG_theta_Encoder = theta_enc;
	LOG_theta_e_Enc = encoderSpeeedTest_Y.theta_e;
	LOG_omega_Enc = (30/PI)*encoderSpeeedTest_Y.omega_m;
	LOG_omega_e_Enc = encoderSpeeedTest_Y.omega_e;

}

void task_encoderTest_stats_print(void)
{
    task_stats_print(&tcb.stats);
}

void task_encoderTest_stats_reset(void)
{
    task_stats_reset(&tcb.stats);
}

#endif // APP_ENCODERTEST
