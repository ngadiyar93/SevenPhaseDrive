/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: encoderSpeeedTest.h
 *
 * Code generated for Simulink model 'encoderSpeeedTest'.
 *
 * Model version                  : 2.37
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun Apr  3 15:16:35 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_encoderSpeeedTest_h_
#define RTW_HEADER_encoderSpeeedTest_h_
#ifndef encoderSpeeedTest_COMMON_INCLUDES_
#define encoderSpeeedTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* encoderSpeeedTest_COMMON_INCLUDES_ */

#include "encoderSpeeedTest_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S1>/Delay' */
  real_T Delay1_DSTATE;                /* '<S1>/Delay1' */
  real_T Delay2_DSTATE;                /* '<Root>/Delay2' */
} DW_encoderSpeeedTest_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T theta_m;                      /* '<Root>/theta_m' */
} ExtU_encoderSpeeedTest_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T omega_e;                      /* '<Root>/omega_e' */
  real_T omega_m;                      /* '<Root>/omega_m' */
  real_T theta_e;                      /* '<Root>/theta_e' */
} ExtY_encoderSpeeedTest_T;

/* Real-time Model Data Structure */
struct tag_RTM_encoderSpeeedTest_T {
  const char_T *errorStatus;
};

/* Block states (default storage) */
extern DW_encoderSpeeedTest_T encoderSpeeedTest_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_encoderSpeeedTest_T encoderSpeeedTest_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_encoderSpeeedTest_T encoderSpeeedTest_Y;

/* Model entry point functions */
extern void encoderSpeeedTest_initialize(void);
extern void encoderSpeeedTest_step(void);
extern void encoderSpeeedTest_terminate(void);

/* Real-time Model object */
extern RT_MODEL_encoderSpeeedTest_T *const encoderSpeeedTest_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'encoderSpeeedTest'
 * '<S1>'   : 'encoderSpeeedTest/Subsystem'
 * '<S2>'   : 'encoderSpeeedTest/speed_calc'
 * '<S3>'   : 'encoderSpeeedTest/wrap2pi'
 */
#endif                                 /* RTW_HEADER_encoderSpeeedTest_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
