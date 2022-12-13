#ifndef TASK_MILL_H
#define TASK_MILL_H

#include "sys/scheduler.h"
#include "drv/analog.h"

// Frequency that this task is called (in Hz)
#define TASK_MILL_UPDATES_PER_SEC (10000)
#define TASK_MILL_INTERVAL_USEC   (USEC_IN_SEC / TASK_MILL_UPDATES_PER_SEC)

#define CC_PHASE_A_ADC (ANALOG_IN5)
#define CC_PHASE_B_ADC (ANALOG_IN3)
#define CC_PHASE_C_ADC (ANALOG_IN4)

// calibrate AMDS sampling
#define PHASE_A_CURRENT_GAIN (5.921)
#define PHASE_B_CURRENT_GAIN (5.91)
#define PHASE_C_CURRENT_GAIN (5.902)

#define PHASE_A_CURRENT_OFFSET (26.97)
#define PHASE_B_CURRENT_OFFSET (27.26)
#define PHASE_C_CURRENT_OFFSET (27.44)

//// Encoder
#define enc_theta_m_gain (-1)
#define theta_m_enc_offset_rad (5.08)

// Called in app init function to set up task (or via command)
int task_mill_init(void);

// Callback function which scheduler calls periodically
void task_mill_callback(void *arg);



#endif // TASK_MILL_H
