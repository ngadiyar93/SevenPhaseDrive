/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: currentRegulator.h
 *
 * Code generated for Simulink model 'currentRegulator'.
 *
 * Model version                  : 2.21
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun Apr  3 14:02:39 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_currentRegulator_h_
#define RTW_HEADER_currentRegulator_h_
#include <float.h>
#include <math.h>
#ifndef currentRegulator_COMMON_INCLUDES_
#define currentRegulator_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* currentRegulator_COMMON_INCLUDES_ */

#include "currentRegulator_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T Integrator_DSTATE;            /* '<S37>/Integrator' */
  real_T Integrator_DSTATE_m;          /* '<S85>/Integrator' */
} DW_currentRegulator_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T I_a;                          /* '<Root>/I_a' */
  real_T I_b;                          /* '<Root>/I_b' */
  real_T I_c;                          /* '<Root>/I_c' */
  real_T Id_ref;                       /* '<Root>/Id_ref' */
  real_T Iq_ref;                       /* '<Root>/Iq_ref' */
  real_T omega_e;                      /* '<Root>/omega_e' */
  real_T V_dc;                         /* '<Root>/V_dc' */
} ExtU_currentRegulator_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T normalizedvoltages[3];        /* '<Root>/normalized voltages' */
  real_T Id;                           /* '<Root>/Id' */
  real_T Iq;                           /* '<Root>/Iq' */
} ExtY_currentRegulator_T;

/* Real-time Model Data Structure */
struct tag_RTM_currentRegulator_T {
  const char_T *errorStatus;
};

/* Block states (default storage) */
extern DW_currentRegulator_T currentRegulator_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_currentRegulator_T currentRegulator_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_currentRegulator_T currentRegulator_Y;

/* Model entry point functions */
extern void currentRegulator_initialize(void);
extern void currentRegulator_step(void);
extern void currentRegulator_terminate(void);

/* Real-time Model object */
extern RT_MODEL_currentRegulator_T *const currentRegulator_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Gain' : Unused code path elimination
 * Block '<S4>/Sum' : Unused code path elimination
 * Block '<S105>/Gain' : Eliminated nontunable gain of 1
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
 * '<Root>' : 'currentRegulator'
 * '<S1>'   : 'currentRegulator/FeedForward Compensation '
 * '<S2>'   : 'currentRegulator/PID Controller'
 * '<S3>'   : 'currentRegulator/PID Controller1'
 * '<S4>'   : 'currentRegulator/abc to DQ'
 * '<S5>'   : 'currentRegulator/dq to abc'
 * '<S6>'   : 'currentRegulator/PID Controller/Anti-windup'
 * '<S7>'   : 'currentRegulator/PID Controller/D Gain'
 * '<S8>'   : 'currentRegulator/PID Controller/Filter'
 * '<S9>'   : 'currentRegulator/PID Controller/Filter ICs'
 * '<S10>'  : 'currentRegulator/PID Controller/I Gain'
 * '<S11>'  : 'currentRegulator/PID Controller/Ideal P Gain'
 * '<S12>'  : 'currentRegulator/PID Controller/Ideal P Gain Fdbk'
 * '<S13>'  : 'currentRegulator/PID Controller/Integrator'
 * '<S14>'  : 'currentRegulator/PID Controller/Integrator ICs'
 * '<S15>'  : 'currentRegulator/PID Controller/N Copy'
 * '<S16>'  : 'currentRegulator/PID Controller/N Gain'
 * '<S17>'  : 'currentRegulator/PID Controller/P Copy'
 * '<S18>'  : 'currentRegulator/PID Controller/Parallel P Gain'
 * '<S19>'  : 'currentRegulator/PID Controller/Reset Signal'
 * '<S20>'  : 'currentRegulator/PID Controller/Saturation'
 * '<S21>'  : 'currentRegulator/PID Controller/Saturation Fdbk'
 * '<S22>'  : 'currentRegulator/PID Controller/Sum'
 * '<S23>'  : 'currentRegulator/PID Controller/Sum Fdbk'
 * '<S24>'  : 'currentRegulator/PID Controller/Tracking Mode'
 * '<S25>'  : 'currentRegulator/PID Controller/Tracking Mode Sum'
 * '<S26>'  : 'currentRegulator/PID Controller/Tsamp - Integral'
 * '<S27>'  : 'currentRegulator/PID Controller/Tsamp - Ngain'
 * '<S28>'  : 'currentRegulator/PID Controller/postSat Signal'
 * '<S29>'  : 'currentRegulator/PID Controller/preSat Signal'
 * '<S30>'  : 'currentRegulator/PID Controller/Anti-windup/Passthrough'
 * '<S31>'  : 'currentRegulator/PID Controller/D Gain/Disabled'
 * '<S32>'  : 'currentRegulator/PID Controller/Filter/Disabled'
 * '<S33>'  : 'currentRegulator/PID Controller/Filter ICs/Disabled'
 * '<S34>'  : 'currentRegulator/PID Controller/I Gain/Internal Parameters'
 * '<S35>'  : 'currentRegulator/PID Controller/Ideal P Gain/Passthrough'
 * '<S36>'  : 'currentRegulator/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S37>'  : 'currentRegulator/PID Controller/Integrator/Discrete'
 * '<S38>'  : 'currentRegulator/PID Controller/Integrator ICs/Internal IC'
 * '<S39>'  : 'currentRegulator/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S40>'  : 'currentRegulator/PID Controller/N Gain/Disabled'
 * '<S41>'  : 'currentRegulator/PID Controller/P Copy/Disabled'
 * '<S42>'  : 'currentRegulator/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'currentRegulator/PID Controller/Reset Signal/Disabled'
 * '<S44>'  : 'currentRegulator/PID Controller/Saturation/Passthrough'
 * '<S45>'  : 'currentRegulator/PID Controller/Saturation Fdbk/Disabled'
 * '<S46>'  : 'currentRegulator/PID Controller/Sum/Sum_PI'
 * '<S47>'  : 'currentRegulator/PID Controller/Sum Fdbk/Disabled'
 * '<S48>'  : 'currentRegulator/PID Controller/Tracking Mode/Disabled'
 * '<S49>'  : 'currentRegulator/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'currentRegulator/PID Controller/Tsamp - Integral/Passthrough'
 * '<S51>'  : 'currentRegulator/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S52>'  : 'currentRegulator/PID Controller/postSat Signal/Forward_Path'
 * '<S53>'  : 'currentRegulator/PID Controller/preSat Signal/Forward_Path'
 * '<S54>'  : 'currentRegulator/PID Controller1/Anti-windup'
 * '<S55>'  : 'currentRegulator/PID Controller1/D Gain'
 * '<S56>'  : 'currentRegulator/PID Controller1/Filter'
 * '<S57>'  : 'currentRegulator/PID Controller1/Filter ICs'
 * '<S58>'  : 'currentRegulator/PID Controller1/I Gain'
 * '<S59>'  : 'currentRegulator/PID Controller1/Ideal P Gain'
 * '<S60>'  : 'currentRegulator/PID Controller1/Ideal P Gain Fdbk'
 * '<S61>'  : 'currentRegulator/PID Controller1/Integrator'
 * '<S62>'  : 'currentRegulator/PID Controller1/Integrator ICs'
 * '<S63>'  : 'currentRegulator/PID Controller1/N Copy'
 * '<S64>'  : 'currentRegulator/PID Controller1/N Gain'
 * '<S65>'  : 'currentRegulator/PID Controller1/P Copy'
 * '<S66>'  : 'currentRegulator/PID Controller1/Parallel P Gain'
 * '<S67>'  : 'currentRegulator/PID Controller1/Reset Signal'
 * '<S68>'  : 'currentRegulator/PID Controller1/Saturation'
 * '<S69>'  : 'currentRegulator/PID Controller1/Saturation Fdbk'
 * '<S70>'  : 'currentRegulator/PID Controller1/Sum'
 * '<S71>'  : 'currentRegulator/PID Controller1/Sum Fdbk'
 * '<S72>'  : 'currentRegulator/PID Controller1/Tracking Mode'
 * '<S73>'  : 'currentRegulator/PID Controller1/Tracking Mode Sum'
 * '<S74>'  : 'currentRegulator/PID Controller1/Tsamp - Integral'
 * '<S75>'  : 'currentRegulator/PID Controller1/Tsamp - Ngain'
 * '<S76>'  : 'currentRegulator/PID Controller1/postSat Signal'
 * '<S77>'  : 'currentRegulator/PID Controller1/preSat Signal'
 * '<S78>'  : 'currentRegulator/PID Controller1/Anti-windup/Passthrough'
 * '<S79>'  : 'currentRegulator/PID Controller1/D Gain/Disabled'
 * '<S80>'  : 'currentRegulator/PID Controller1/Filter/Disabled'
 * '<S81>'  : 'currentRegulator/PID Controller1/Filter ICs/Disabled'
 * '<S82>'  : 'currentRegulator/PID Controller1/I Gain/Internal Parameters'
 * '<S83>'  : 'currentRegulator/PID Controller1/Ideal P Gain/Passthrough'
 * '<S84>'  : 'currentRegulator/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S85>'  : 'currentRegulator/PID Controller1/Integrator/Discrete'
 * '<S86>'  : 'currentRegulator/PID Controller1/Integrator ICs/Internal IC'
 * '<S87>'  : 'currentRegulator/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S88>'  : 'currentRegulator/PID Controller1/N Gain/Disabled'
 * '<S89>'  : 'currentRegulator/PID Controller1/P Copy/Disabled'
 * '<S90>'  : 'currentRegulator/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S91>'  : 'currentRegulator/PID Controller1/Reset Signal/Disabled'
 * '<S92>'  : 'currentRegulator/PID Controller1/Saturation/Passthrough'
 * '<S93>'  : 'currentRegulator/PID Controller1/Saturation Fdbk/Disabled'
 * '<S94>'  : 'currentRegulator/PID Controller1/Sum/Sum_PI'
 * '<S95>'  : 'currentRegulator/PID Controller1/Sum Fdbk/Disabled'
 * '<S96>'  : 'currentRegulator/PID Controller1/Tracking Mode/Disabled'
 * '<S97>'  : 'currentRegulator/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S98>'  : 'currentRegulator/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S99>'  : 'currentRegulator/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S100>' : 'currentRegulator/PID Controller1/postSat Signal/Forward_Path'
 * '<S101>' : 'currentRegulator/PID Controller1/preSat Signal/Forward_Path'
 * '<S102>' : 'currentRegulator/abc to DQ/Subsystem1'
 * '<S103>' : 'currentRegulator/abc to DQ/Subsystem2'
 * '<S104>' : 'currentRegulator/dq to abc/Subsystem'
 * '<S105>' : 'currentRegulator/dq to abc/Subsystem3'
 */
#endif                                 /* RTW_HEADER_currentRegulator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
