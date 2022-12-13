#ifndef TASK_RLCC_H
#define TASK_RLCC_H

#include "sys/scheduler.h"
#include "drv/analog.h"

// Frequency that this task is called (in Hz)
#define TASK_RLCC_UPDATES_PER_SEC (10000)
#define TASK_RLCC_INTERVAL_USEC   (USEC_IN_SEC / TASK_RLCC_UPDATES_PER_SEC)

#define CC_PHASE_A_ADC (ANALOG_IN5)
#define CC_PHASE_B_ADC (ANALOG_IN3)
#define CC_PHASE_C_ADC (ANALOG_IN4)

// calibrate AMDS sampling
// calibrate AMDS sampling
#define PHASE_A_CURRENT_GAIN (5.921)
#define PHASE_B_CURRENT_GAIN (5.91)
#define PHASE_C_CURRENT_GAIN (5.902)

#define PHASE_A_CURRENT_OFFSET (26.97)
#define PHASE_B_CURRENT_OFFSET (27.26)
#define PHASE_C_CURRENT_OFFSET (27.44)

#define Vdc (50)  // [V]

typedef enum {
    CABINET_CS_SUS_U = 0,
    CABINET_CS_SUS_V,
    CABINET_CS_SUS_W,
    CABINET_CS_TOR_U,
    CABINET_CS_TOR_V,
    CABINET_CS_TOR_W,
} cabinet_cs_e;

int read_cs(cabinet_cs_e cs, double *adc_volts_out);

// Called in app init function to set up task (or via command)
int task_rlCC_init(void);

// Callback function which scheduler calls periodically
void task_rlCC_callback(void *arg);



#endif // TASK_RLCC_H
