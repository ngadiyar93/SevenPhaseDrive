/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSMController.h
 *
 * Code generated for Simulink model 'PMSMController'.
 *
 * Model version                  : 2.37
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Tue Apr  5 10:30:00 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PMSMController_h_
#define RTW_HEADER_PMSMController_h_
#include <math.h>
#ifndef PMSMController_COMMON_INCLUDES_
#define PMSMController_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* PMSMController_COMMON_INCLUDES_ */

#include "PMSMController_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S89>/Integrator' */
  real_T Delay_DSTATE;                 /* '<S5>/Delay' */
  real_T Delay1_DSTATE;                /* '<S5>/Delay1' */
  real_T Integrator_DSTATE_d;          /* '<S41>/Integrator' */
  real_T Integrator_DSTATE_dp;         /* '<S137>/Integrator' */
  real_T Delay2_DSTATE;                /* '<Root>/Delay2' */
} DW_PMSMController_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T I_a;                          /* '<Root>/I_a' */
  real_T I_b;                          /* '<Root>/I_b' */
  real_T I_c;                          /* '<Root>/I_c' */
  real_T Id_ref;                       /* '<Root>/Id_ref' */
  real_T omega_ref;                    /* '<Root>/omega_ref' */
  real_T theta_m;                      /* '<Root>/theta_m' */
  real_T V_dc;                         /* '<Root>/V_dc' */
} ExtU_PMSMController_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T normalizedvoltages[3];        /* '<Root>/normalized voltages' */
  real_T T_ref;                        /* '<Root>/T_ref' */
  real_T omega_e;                      /* '<Root>/omega_e' */
  real_T Id;                           /* '<Root>/Id' */
  real_T Iq;                           /* '<Root>/Iq' */
} ExtY_PMSMController_T;

/* Real-time Model Data Structure */
struct tag_RTM_PMSMController_T {
  const char_T *errorStatus;
};

/* Block states (default storage) */
extern DW_PMSMController_T PMSMController_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_PMSMController_T PMSMController_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_PMSMController_T PMSMController_Y;

/* Model entry point functions */
extern void PMSMController_initialize(void);
extern void PMSMController_step(void);
extern void PMSMController_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PMSMController_T *const PMSMController_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Gain' : Unused code path elimination
 * Block '<S6>/Sum' : Unused code path elimination
 * Block '<S157>/Gain' : Eliminated nontunable gain of 1
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
 * '<Root>' : 'PMSMController'
 * '<S1>'   : 'PMSMController/Discrete PID Controller'
 * '<S2>'   : 'PMSMController/Discrete PID Controller1'
 * '<S3>'   : 'PMSMController/Discrete PID Controller2'
 * '<S4>'   : 'PMSMController/FeedForward Compensation '
 * '<S5>'   : 'PMSMController/Subsystem'
 * '<S6>'   : 'PMSMController/abc to DQ'
 * '<S7>'   : 'PMSMController/dq to abc'
 * '<S8>'   : 'PMSMController/speed_calc'
 * '<S9>'   : 'PMSMController/wrap2pi'
 * '<S10>'  : 'PMSMController/Discrete PID Controller/Anti-windup'
 * '<S11>'  : 'PMSMController/Discrete PID Controller/D Gain'
 * '<S12>'  : 'PMSMController/Discrete PID Controller/Filter'
 * '<S13>'  : 'PMSMController/Discrete PID Controller/Filter ICs'
 * '<S14>'  : 'PMSMController/Discrete PID Controller/I Gain'
 * '<S15>'  : 'PMSMController/Discrete PID Controller/Ideal P Gain'
 * '<S16>'  : 'PMSMController/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S17>'  : 'PMSMController/Discrete PID Controller/Integrator'
 * '<S18>'  : 'PMSMController/Discrete PID Controller/Integrator ICs'
 * '<S19>'  : 'PMSMController/Discrete PID Controller/N Copy'
 * '<S20>'  : 'PMSMController/Discrete PID Controller/N Gain'
 * '<S21>'  : 'PMSMController/Discrete PID Controller/P Copy'
 * '<S22>'  : 'PMSMController/Discrete PID Controller/Parallel P Gain'
 * '<S23>'  : 'PMSMController/Discrete PID Controller/Reset Signal'
 * '<S24>'  : 'PMSMController/Discrete PID Controller/Saturation'
 * '<S25>'  : 'PMSMController/Discrete PID Controller/Saturation Fdbk'
 * '<S26>'  : 'PMSMController/Discrete PID Controller/Sum'
 * '<S27>'  : 'PMSMController/Discrete PID Controller/Sum Fdbk'
 * '<S28>'  : 'PMSMController/Discrete PID Controller/Tracking Mode'
 * '<S29>'  : 'PMSMController/Discrete PID Controller/Tracking Mode Sum'
 * '<S30>'  : 'PMSMController/Discrete PID Controller/Tsamp - Integral'
 * '<S31>'  : 'PMSMController/Discrete PID Controller/Tsamp - Ngain'
 * '<S32>'  : 'PMSMController/Discrete PID Controller/postSat Signal'
 * '<S33>'  : 'PMSMController/Discrete PID Controller/preSat Signal'
 * '<S34>'  : 'PMSMController/Discrete PID Controller/Anti-windup/Back Calculation'
 * '<S35>'  : 'PMSMController/Discrete PID Controller/D Gain/Disabled'
 * '<S36>'  : 'PMSMController/Discrete PID Controller/Filter/Disabled'
 * '<S37>'  : 'PMSMController/Discrete PID Controller/Filter ICs/Disabled'
 * '<S38>'  : 'PMSMController/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S39>'  : 'PMSMController/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S40>'  : 'PMSMController/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S41>'  : 'PMSMController/Discrete PID Controller/Integrator/Discrete'
 * '<S42>'  : 'PMSMController/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S43>'  : 'PMSMController/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S44>'  : 'PMSMController/Discrete PID Controller/N Gain/Disabled'
 * '<S45>'  : 'PMSMController/Discrete PID Controller/P Copy/Disabled'
 * '<S46>'  : 'PMSMController/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S47>'  : 'PMSMController/Discrete PID Controller/Reset Signal/Disabled'
 * '<S48>'  : 'PMSMController/Discrete PID Controller/Saturation/Enabled'
 * '<S49>'  : 'PMSMController/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S50>'  : 'PMSMController/Discrete PID Controller/Sum/Sum_PI'
 * '<S51>'  : 'PMSMController/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S52>'  : 'PMSMController/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S53>'  : 'PMSMController/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S54>'  : 'PMSMController/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S55>'  : 'PMSMController/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S56>'  : 'PMSMController/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S57>'  : 'PMSMController/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S58>'  : 'PMSMController/Discrete PID Controller1/Anti-windup'
 * '<S59>'  : 'PMSMController/Discrete PID Controller1/D Gain'
 * '<S60>'  : 'PMSMController/Discrete PID Controller1/Filter'
 * '<S61>'  : 'PMSMController/Discrete PID Controller1/Filter ICs'
 * '<S62>'  : 'PMSMController/Discrete PID Controller1/I Gain'
 * '<S63>'  : 'PMSMController/Discrete PID Controller1/Ideal P Gain'
 * '<S64>'  : 'PMSMController/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S65>'  : 'PMSMController/Discrete PID Controller1/Integrator'
 * '<S66>'  : 'PMSMController/Discrete PID Controller1/Integrator ICs'
 * '<S67>'  : 'PMSMController/Discrete PID Controller1/N Copy'
 * '<S68>'  : 'PMSMController/Discrete PID Controller1/N Gain'
 * '<S69>'  : 'PMSMController/Discrete PID Controller1/P Copy'
 * '<S70>'  : 'PMSMController/Discrete PID Controller1/Parallel P Gain'
 * '<S71>'  : 'PMSMController/Discrete PID Controller1/Reset Signal'
 * '<S72>'  : 'PMSMController/Discrete PID Controller1/Saturation'
 * '<S73>'  : 'PMSMController/Discrete PID Controller1/Saturation Fdbk'
 * '<S74>'  : 'PMSMController/Discrete PID Controller1/Sum'
 * '<S75>'  : 'PMSMController/Discrete PID Controller1/Sum Fdbk'
 * '<S76>'  : 'PMSMController/Discrete PID Controller1/Tracking Mode'
 * '<S77>'  : 'PMSMController/Discrete PID Controller1/Tracking Mode Sum'
 * '<S78>'  : 'PMSMController/Discrete PID Controller1/Tsamp - Integral'
 * '<S79>'  : 'PMSMController/Discrete PID Controller1/Tsamp - Ngain'
 * '<S80>'  : 'PMSMController/Discrete PID Controller1/postSat Signal'
 * '<S81>'  : 'PMSMController/Discrete PID Controller1/preSat Signal'
 * '<S82>'  : 'PMSMController/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S83>'  : 'PMSMController/Discrete PID Controller1/D Gain/Disabled'
 * '<S84>'  : 'PMSMController/Discrete PID Controller1/Filter/Disabled'
 * '<S85>'  : 'PMSMController/Discrete PID Controller1/Filter ICs/Disabled'
 * '<S86>'  : 'PMSMController/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S87>'  : 'PMSMController/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S88>'  : 'PMSMController/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S89>'  : 'PMSMController/Discrete PID Controller1/Integrator/Discrete'
 * '<S90>'  : 'PMSMController/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S91>'  : 'PMSMController/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S92>'  : 'PMSMController/Discrete PID Controller1/N Gain/Disabled'
 * '<S93>'  : 'PMSMController/Discrete PID Controller1/P Copy/Disabled'
 * '<S94>'  : 'PMSMController/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S95>'  : 'PMSMController/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S96>'  : 'PMSMController/Discrete PID Controller1/Saturation/Passthrough'
 * '<S97>'  : 'PMSMController/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S98>'  : 'PMSMController/Discrete PID Controller1/Sum/Sum_PI'
 * '<S99>'  : 'PMSMController/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S100>' : 'PMSMController/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S101>' : 'PMSMController/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S102>' : 'PMSMController/Discrete PID Controller1/Tsamp - Integral/Passthrough'
 * '<S103>' : 'PMSMController/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S104>' : 'PMSMController/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S105>' : 'PMSMController/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S106>' : 'PMSMController/Discrete PID Controller2/Anti-windup'
 * '<S107>' : 'PMSMController/Discrete PID Controller2/D Gain'
 * '<S108>' : 'PMSMController/Discrete PID Controller2/Filter'
 * '<S109>' : 'PMSMController/Discrete PID Controller2/Filter ICs'
 * '<S110>' : 'PMSMController/Discrete PID Controller2/I Gain'
 * '<S111>' : 'PMSMController/Discrete PID Controller2/Ideal P Gain'
 * '<S112>' : 'PMSMController/Discrete PID Controller2/Ideal P Gain Fdbk'
 * '<S113>' : 'PMSMController/Discrete PID Controller2/Integrator'
 * '<S114>' : 'PMSMController/Discrete PID Controller2/Integrator ICs'
 * '<S115>' : 'PMSMController/Discrete PID Controller2/N Copy'
 * '<S116>' : 'PMSMController/Discrete PID Controller2/N Gain'
 * '<S117>' : 'PMSMController/Discrete PID Controller2/P Copy'
 * '<S118>' : 'PMSMController/Discrete PID Controller2/Parallel P Gain'
 * '<S119>' : 'PMSMController/Discrete PID Controller2/Reset Signal'
 * '<S120>' : 'PMSMController/Discrete PID Controller2/Saturation'
 * '<S121>' : 'PMSMController/Discrete PID Controller2/Saturation Fdbk'
 * '<S122>' : 'PMSMController/Discrete PID Controller2/Sum'
 * '<S123>' : 'PMSMController/Discrete PID Controller2/Sum Fdbk'
 * '<S124>' : 'PMSMController/Discrete PID Controller2/Tracking Mode'
 * '<S125>' : 'PMSMController/Discrete PID Controller2/Tracking Mode Sum'
 * '<S126>' : 'PMSMController/Discrete PID Controller2/Tsamp - Integral'
 * '<S127>' : 'PMSMController/Discrete PID Controller2/Tsamp - Ngain'
 * '<S128>' : 'PMSMController/Discrete PID Controller2/postSat Signal'
 * '<S129>' : 'PMSMController/Discrete PID Controller2/preSat Signal'
 * '<S130>' : 'PMSMController/Discrete PID Controller2/Anti-windup/Passthrough'
 * '<S131>' : 'PMSMController/Discrete PID Controller2/D Gain/Disabled'
 * '<S132>' : 'PMSMController/Discrete PID Controller2/Filter/Disabled'
 * '<S133>' : 'PMSMController/Discrete PID Controller2/Filter ICs/Disabled'
 * '<S134>' : 'PMSMController/Discrete PID Controller2/I Gain/Internal Parameters'
 * '<S135>' : 'PMSMController/Discrete PID Controller2/Ideal P Gain/Passthrough'
 * '<S136>' : 'PMSMController/Discrete PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S137>' : 'PMSMController/Discrete PID Controller2/Integrator/Discrete'
 * '<S138>' : 'PMSMController/Discrete PID Controller2/Integrator ICs/Internal IC'
 * '<S139>' : 'PMSMController/Discrete PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S140>' : 'PMSMController/Discrete PID Controller2/N Gain/Disabled'
 * '<S141>' : 'PMSMController/Discrete PID Controller2/P Copy/Disabled'
 * '<S142>' : 'PMSMController/Discrete PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S143>' : 'PMSMController/Discrete PID Controller2/Reset Signal/Disabled'
 * '<S144>' : 'PMSMController/Discrete PID Controller2/Saturation/Passthrough'
 * '<S145>' : 'PMSMController/Discrete PID Controller2/Saturation Fdbk/Disabled'
 * '<S146>' : 'PMSMController/Discrete PID Controller2/Sum/Sum_PI'
 * '<S147>' : 'PMSMController/Discrete PID Controller2/Sum Fdbk/Disabled'
 * '<S148>' : 'PMSMController/Discrete PID Controller2/Tracking Mode/Disabled'
 * '<S149>' : 'PMSMController/Discrete PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S150>' : 'PMSMController/Discrete PID Controller2/Tsamp - Integral/Passthrough'
 * '<S151>' : 'PMSMController/Discrete PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S152>' : 'PMSMController/Discrete PID Controller2/postSat Signal/Forward_Path'
 * '<S153>' : 'PMSMController/Discrete PID Controller2/preSat Signal/Forward_Path'
 * '<S154>' : 'PMSMController/abc to DQ/Subsystem1'
 * '<S155>' : 'PMSMController/abc to DQ/Subsystem2'
 * '<S156>' : 'PMSMController/dq to abc/Subsystem'
 * '<S157>' : 'PMSMController/dq to abc/Subsystem3'
 */
#endif                                 /* RTW_HEADER_PMSMController_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
