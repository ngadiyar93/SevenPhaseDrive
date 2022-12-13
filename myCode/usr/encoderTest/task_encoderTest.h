#ifndef TASK_ENCODERTEST_H
#define TASK_ENCODERTEST_H

#include "sys/scheduler.h"

// Frequency that this task is called (in Hz)
//
// Must be less than or equal to scheduler updates per second
// This value is defined in sys/scheduler.h and defaults to 10kHz.
// Note that it can be overridden via usr/user_config.h
#define TASK_ENCODERTEST_UPDATES_PER_SEC (10000)

// Microseconds interval between when task is called
//
// This is what scheduler actually uses to run task,
// but is generated via define above
#define TASK_ENCODERTEST_INTERVAL_USEC (USEC_IN_SEC / TASK_ENCODERTEST_UPDATES_PER_SEC)

// Called in app init function to set up task (or via command)
int task_encoderTest_init(void);
int task_encoderTest_deinit(void);

// Callback function which scheduler calls periodically
void task_encoderTest_callback(void *arg);

double read_encoder(void);

// Print the statistics gathered by the scheduler
void task_encoderTest_stats_print(void);

// Reset the statistics gathered by the scheduler
void task_encoderTest_stats_reset(void);

//Encoder variables
//double enc_offset_rad = 0;
//double enc_gain = 1;


#endif // TASK_ENCODERTEST_H
