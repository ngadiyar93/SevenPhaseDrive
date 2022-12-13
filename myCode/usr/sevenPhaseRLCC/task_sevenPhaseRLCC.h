#ifndef TASK_SEVENPHASERLCC_H
#define TASK_SEVENPHASERLCC_H

#include "sys/scheduler.h"
#include "drv/analog.h"

// Frequency that this task is called (in Hz)
#define TASK_SEVENPHASERLCC_UPDATES_PER_SEC (25000)
#define TASK_SEVENPHASERLCC_INTERVAL_USEC   (USEC_IN_SEC / TASK_SEVENPHASERLCC_UPDATES_PER_SEC)

#define CC_PHASE_A_ADC (ANALOG_IN5)
#define CC_PHASE_B_ADC (ANALOG_IN3)
#define CC_PHASE_C_ADC (ANALOG_IN4)

// calibrate AMDS sampling
#define PHASE_U_CURRENT_GAIN (20.42)
#define PHASE_V_CURRENT_GAIN (20.35)
#define PHASE_W_CURRENT_GAIN (5.89)
#define PHASE_X_CURRENT_GAIN (5.91)
#define PHASE_Y_CURRENT_GAIN (5.91)
#define PHASE_Z_CURRENT_GAIN (20.31)
#define PHASE_A_CURRENT_GAIN (20.36)

#define PHASE_U_CURRENT_OFFSET (96.05)
#define PHASE_V_CURRENT_OFFSET (92.18)
#define PHASE_W_CURRENT_OFFSET (26.61)
#define PHASE_X_CURRENT_OFFSET (27.76)
#define PHASE_Y_CURRENT_OFFSET (27.35)
#define PHASE_Z_CURRENT_OFFSET (92.83)
#define PHASE_A_CURRENT_OFFSET (93.78)


#define Vdc (50)  // [V]

typedef enum {
    CABINET_CS_PH_U = 0,
    CABINET_CS_PH_V,
    CABINET_CS_PH_W,
    CABINET_CS_PH_X,
    CABINET_CS_PH_Y,
    CABINET_CS_PH_Z,
	CABINET_CS_PH_A,
} cabinet_cs_e;

int read_cs(cabinet_cs_e cs, double *adc_volts_out);

// Called in app init function to set up task (or via command)
int task_sevenPhaseRLCC_init(void);

// Callback function which scheduler calls periodically
void task_sevenPhaseRLCC_callback(void *arg);



#endif // TASK_SEVENPHASERLCC_H
