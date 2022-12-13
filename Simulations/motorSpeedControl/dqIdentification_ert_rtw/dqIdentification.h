/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: dqIdentification.h
 *
 * Code generated for Simulink model 'dqIdentification'.
 *
 * Model version                  : 2.39
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Mar 30 11:05:52 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_dqIdentification_h_
#define RTW_HEADER_dqIdentification_h_
#include <math.h>
#ifndef dqIdentification_COMMON_INCLUDES_
#define dqIdentification_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* dqIdentification_COMMON_INCLUDES_ */

#include "dqIdentification_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S86>/Integrator' */
  real_T Integrator_DSTATE_e;          /* '<S38>/Integrator' */
} DW_dqIdentification_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T I_a;                          /* '<Root>/I_a' */
  real_T I_b;                          /* '<Root>/I_b' */
  real_T I_c;                          /* '<Root>/I_c' */
  real_T Id_ref;                       /* '<Root>/Id_ref' */
  real_T theta_m;                      /* '<Root>/theta_m' */
  real_T V_dc;                         /* '<Root>/V_dc' */
  real_T Iq_ref;                       /* '<Root>/Iq_ref' */
} ExtU_dqIdentification_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T normalizedvoltages[3];        /* '<Root>/normalized voltages' */
} ExtY_dqIdentification_T;

/* Real-time Model Data Structure */
struct tag_RTM_dqIdentification_T {
  const char_T *errorStatus;
};

/* Block states (default storage) */
extern DW_dqIdentification_T dqIdentification_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_dqIdentification_T dqIdentification_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_dqIdentification_T dqIdentification_Y;

/* Model entry point functions */
extern void dqIdentification_initialize(void);
extern void dqIdentification_step(void);
extern void dqIdentification_terminate(void);

/* Real-time Model object */
extern RT_MODEL_dqIdentification_T *const dqIdentification_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Gain' : Unused code path elimination
 * Block '<S4>/Sum' : Unused code path elimination
 * Block '<S106>/Gain' : Eliminated nontunable gain of 1
 */

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
 * '<Root>' : 'dqIdentification'
 * '<S1>'   : 'dqIdentification/Discrete PID Controller1'
 * '<S2>'   : 'dqIdentification/Discrete PID Controller2'
 * '<S3>'   : 'dqIdentification/FeedForward Compensation '
 * '<S4>'   : 'dqIdentification/abc to DQ'
 * '<S5>'   : 'dqIdentification/dq to abc'
 * '<S6>'   : 'dqIdentification/wrap2pi'
 * '<S7>'   : 'dqIdentification/Discrete PID Controller1/Anti-windup'
 * '<S8>'   : 'dqIdentification/Discrete PID Controller1/D Gain'
 * '<S9>'   : 'dqIdentification/Discrete PID Controller1/Filter'
 * '<S10>'  : 'dqIdentification/Discrete PID Controller1/Filter ICs'
 * '<S11>'  : 'dqIdentification/Discrete PID Controller1/I Gain'
 * '<S12>'  : 'dqIdentification/Discrete PID Controller1/Ideal P Gain'
 * '<S13>'  : 'dqIdentification/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S14>'  : 'dqIdentification/Discrete PID Controller1/Integrator'
 * '<S15>'  : 'dqIdentification/Discrete PID Controller1/Integrator ICs'
 * '<S16>'  : 'dqIdentification/Discrete PID Controller1/N Copy'
 * '<S17>'  : 'dqIdentification/Discrete PID Controller1/N Gain'
 * '<S18>'  : 'dqIdentification/Discrete PID Controller1/P Copy'
 * '<S19>'  : 'dqIdentification/Discrete PID Controller1/Parallel P Gain'
 * '<S20>'  : 'dqIdentification/Discrete PID Controller1/Reset Signal'
 * '<S21>'  : 'dqIdentification/Discrete PID Controller1/Saturation'
 * '<S22>'  : 'dqIdentification/Discrete PID Controller1/Saturation Fdbk'
 * '<S23>'  : 'dqIdentification/Discrete PID Controller1/Sum'
 * '<S24>'  : 'dqIdentification/Discrete PID Controller1/Sum Fdbk'
 * '<S25>'  : 'dqIdentification/Discrete PID Controller1/Tracking Mode'
 * '<S26>'  : 'dqIdentification/Discrete PID Controller1/Tracking Mode Sum'
 * '<S27>'  : 'dqIdentification/Discrete PID Controller1/Tsamp - Integral'
 * '<S28>'  : 'dqIdentification/Discrete PID Controller1/Tsamp - Ngain'
 * '<S29>'  : 'dqIdentification/Discrete PID Controller1/postSat Signal'
 * '<S30>'  : 'dqIdentification/Discrete PID Controller1/preSat Signal'
 * '<S31>'  : 'dqIdentification/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S32>'  : 'dqIdentification/Discrete PID Controller1/D Gain/Disabled'
 * '<S33>'  : 'dqIdentification/Discrete PID Controller1/Filter/Disabled'
 * '<S34>'  : 'dqIdentification/Discrete PID Controller1/Filter ICs/Disabled'
 * '<S35>'  : 'dqIdentification/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S36>'  : 'dqIdentification/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S37>'  : 'dqIdentification/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S38>'  : 'dqIdentification/Discrete PID Controller1/Integrator/Discrete'
 * '<S39>'  : 'dqIdentification/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S40>'  : 'dqIdentification/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S41>'  : 'dqIdentification/Discrete PID Controller1/N Gain/Disabled'
 * '<S42>'  : 'dqIdentification/Discrete PID Controller1/P Copy/Disabled'
 * '<S43>'  : 'dqIdentification/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S44>'  : 'dqIdentification/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S45>'  : 'dqIdentification/Discrete PID Controller1/Saturation/Passthrough'
 * '<S46>'  : 'dqIdentification/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S47>'  : 'dqIdentification/Discrete PID Controller1/Sum/Sum_PI'
 * '<S48>'  : 'dqIdentification/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S49>'  : 'dqIdentification/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S50>'  : 'dqIdentification/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S51>'  : 'dqIdentification/Discrete PID Controller1/Tsamp - Integral/Passthrough'
 * '<S52>'  : 'dqIdentification/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S53>'  : 'dqIdentification/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S54>'  : 'dqIdentification/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S55>'  : 'dqIdentification/Discrete PID Controller2/Anti-windup'
 * '<S56>'  : 'dqIdentification/Discrete PID Controller2/D Gain'
 * '<S57>'  : 'dqIdentification/Discrete PID Controller2/Filter'
 * '<S58>'  : 'dqIdentification/Discrete PID Controller2/Filter ICs'
 * '<S59>'  : 'dqIdentification/Discrete PID Controller2/I Gain'
 * '<S60>'  : 'dqIdentification/Discrete PID Controller2/Ideal P Gain'
 * '<S61>'  : 'dqIdentification/Discrete PID Controller2/Ideal P Gain Fdbk'
 * '<S62>'  : 'dqIdentification/Discrete PID Controller2/Integrator'
 * '<S63>'  : 'dqIdentification/Discrete PID Controller2/Integrator ICs'
 * '<S64>'  : 'dqIdentification/Discrete PID Controller2/N Copy'
 * '<S65>'  : 'dqIdentification/Discrete PID Controller2/N Gain'
 * '<S66>'  : 'dqIdentification/Discrete PID Controller2/P Copy'
 * '<S67>'  : 'dqIdentification/Discrete PID Controller2/Parallel P Gain'
 * '<S68>'  : 'dqIdentification/Discrete PID Controller2/Reset Signal'
 * '<S69>'  : 'dqIdentification/Discrete PID Controller2/Saturation'
 * '<S70>'  : 'dqIdentification/Discrete PID Controller2/Saturation Fdbk'
 * '<S71>'  : 'dqIdentification/Discrete PID Controller2/Sum'
 * '<S72>'  : 'dqIdentification/Discrete PID Controller2/Sum Fdbk'
 * '<S73>'  : 'dqIdentification/Discrete PID Controller2/Tracking Mode'
 * '<S74>'  : 'dqIdentification/Discrete PID Controller2/Tracking Mode Sum'
 * '<S75>'  : 'dqIdentification/Discrete PID Controller2/Tsamp - Integral'
 * '<S76>'  : 'dqIdentification/Discrete PID Controller2/Tsamp - Ngain'
 * '<S77>'  : 'dqIdentification/Discrete PID Controller2/postSat Signal'
 * '<S78>'  : 'dqIdentification/Discrete PID Controller2/preSat Signal'
 * '<S79>'  : 'dqIdentification/Discrete PID Controller2/Anti-windup/Passthrough'
 * '<S80>'  : 'dqIdentification/Discrete PID Controller2/D Gain/Disabled'
 * '<S81>'  : 'dqIdentification/Discrete PID Controller2/Filter/Disabled'
 * '<S82>'  : 'dqIdentification/Discrete PID Controller2/Filter ICs/Disabled'
 * '<S83>'  : 'dqIdentification/Discrete PID Controller2/I Gain/Internal Parameters'
 * '<S84>'  : 'dqIdentification/Discrete PID Controller2/Ideal P Gain/Passthrough'
 * '<S85>'  : 'dqIdentification/Discrete PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S86>'  : 'dqIdentification/Discrete PID Controller2/Integrator/Discrete'
 * '<S87>'  : 'dqIdentification/Discrete PID Controller2/Integrator ICs/Internal IC'
 * '<S88>'  : 'dqIdentification/Discrete PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S89>'  : 'dqIdentification/Discrete PID Controller2/N Gain/Disabled'
 * '<S90>'  : 'dqIdentification/Discrete PID Controller2/P Copy/Disabled'
 * '<S91>'  : 'dqIdentification/Discrete PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S92>'  : 'dqIdentification/Discrete PID Controller2/Reset Signal/Disabled'
 * '<S93>'  : 'dqIdentification/Discrete PID Controller2/Saturation/Passthrough'
 * '<S94>'  : 'dqIdentification/Discrete PID Controller2/Saturation Fdbk/Disabled'
 * '<S95>'  : 'dqIdentification/Discrete PID Controller2/Sum/Sum_PI'
 * '<S96>'  : 'dqIdentification/Discrete PID Controller2/Sum Fdbk/Disabled'
 * '<S97>'  : 'dqIdentification/Discrete PID Controller2/Tracking Mode/Disabled'
 * '<S98>'  : 'dqIdentification/Discrete PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S99>'  : 'dqIdentification/Discrete PID Controller2/Tsamp - Integral/Passthrough'
 * '<S100>' : 'dqIdentification/Discrete PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S101>' : 'dqIdentification/Discrete PID Controller2/postSat Signal/Forward_Path'
 * '<S102>' : 'dqIdentification/Discrete PID Controller2/preSat Signal/Forward_Path'
 * '<S103>' : 'dqIdentification/abc to DQ/Subsystem1'
 * '<S104>' : 'dqIdentification/abc to DQ/Subsystem2'
 * '<S105>' : 'dqIdentification/dq to abc/Subsystem'
 * '<S106>' : 'dqIdentification/dq to abc/Subsystem3'
 */
#endif                                 /* RTW_HEADER_dqIdentification_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
