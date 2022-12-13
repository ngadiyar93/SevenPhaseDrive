/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: CurrentControl.h
 *
 * Code generated for Simulink model 'CurrentControl'.
 *
 * Model version                  : 2.23
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Dec 11 18:11:06 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CurrentControl_h_
#define RTW_HEADER_CurrentControl_h_
#ifndef CurrentControl_COMMON_INCLUDES_
#define CurrentControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* CurrentControl_COMMON_INCLUDES_ */

#include "CurrentControl_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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
  real_T Delay_DSTATE_g;               /* '<S9>/Delay' */
  real_T Delay_DSTATE_d;               /* '<S10>/Delay' */
  real_T Delay_DSTATE_c;               /* '<S11>/Delay' */
  real_T Delay_DSTATE_gq;              /* '<S13>/Delay' */
  real_T Delay_DSTATE_i;               /* '<S12>/Delay' */
  real_T Delay_DSTATE_m;               /* '<S14>/Delay' */
} DW_CurrentControl_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T i1;                           /* '<Root>/i1' */
  real_T i2;                           /* '<Root>/i2' */
  real_T i3;                           /* '<Root>/i3' */
  real_T i4;                           /* '<Root>/i4' */
  real_T i5;                           /* '<Root>/i5' */
  real_T i6;                           /* '<Root>/i6' */
  real_T i7;                           /* '<Root>/i7' */
  real_T id_ref;                       /* '<Root>/id_ref' */
  real_T iq_ref;                       /* '<Root>/iq_ref' */
  real_T id3_ref;                      /* '<Root>/id3_ref' */
  real_T iq3_ref;                      /* '<Root>/iq3_ref' */
  real_T id5_ref;                      /* '<Root>/id5_ref' */
  real_T iq5_ref;                      /* '<Root>/iq5_ref' */
  real_T we;                           /* '<Root>/we' */
  real_T V_dc;                         /* '<Root>/V_dc' */
} ExtU_CurrentControl_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T NormalizedVoltages1[7];       /* '<Root>/Normalized Voltages1' */
  real_T LOG1_i_ph_i1;                 /* '<Root>/LOG1_i_ph_i1' */
  real_T LOG1_i_ph_i2;                 /* '<Root>/LOG1_i_ph_i2' */
  real_T LOG1_i_ph_i3;                 /* '<Root>/LOG1_i_ph_i3' */
  real_T LOG1_i_ph_i4;                 /* '<Root>/LOG1_i_ph_i4' */
  real_T LOG1_i_ph_i5;                 /* '<Root>/LOG1_i_ph_i5' */
  real_T LOG1_i_ph_i6;                 /* '<Root>/LOG1_i_ph_i6' */
  real_T LOG1_i_ph_i7;                 /* '<Root>/LOG1_i_ph_i7' */
  real_T LOG1_i_sv_id1_ref;            /* '<Root>/LOG1_i_sv_id1_ref' */
  real_T LOG1_i_sv_iq1_ref;            /* '<Root>/LOG1_i_sv_iq1_ref' */
  real_T LOG1_i_sv_id3_ref;            /* '<Root>/LOG1_i_sv_id3_ref' */
  real_T LOG1_i_sv_iq3_ref;            /* '<Root>/LOG1_i_sv_iq3_ref' */
  real_T LOG1_i_sv_id5_ref;            /* '<Root>/LOG1_i_sv_id5_ref' */
  real_T LOG1_i_sv_iq5_ref;            /* '<Root>/LOG1_i_sv_iq5_ref' */
  real_T LOG1_i_sv_id1;                /* '<Root>/LOG1_i_sv_id1' */
  real_T LOG1_i_sv_iq1;                /* '<Root>/LOG1_i_sv_iq1' */
  real_T LOG1_i_sv_id3;                /* '<Root>/LOG1_i_sv_id3' */
  real_T LOG1_i_sv_iq3;                /* '<Root>/LOG1_i_sv_iq3' */
  real_T LOG1_i_sv_id5;                /* '<Root>/LOG1_i_sv_id5' */
  real_T LOG1_i_sv_iq5;                /* '<Root>/LOG1_i_sv_iq5' */
  real_T LOG1_v_ph_v1;                 /* '<Root>/LOG1_v_ph_v1' */
  real_T LOG1_v_ph_v2;                 /* '<Root>/LOG1_v_ph_v2' */
  real_T LOG1_v_ph_v3;                 /* '<Root>/LOG1_v_ph_v3' */
  real_T LOG1_v_ph_v4;                 /* '<Root>/LOG1_v_ph_v4' */
  real_T LOG1_v_ph_v5;                 /* '<Root>/LOG1_v_ph_v5' */
  real_T LOG1_v_ph_v6;                 /* '<Root>/LOG1_v_ph_v6' */
  real_T LOG1_v_ph_v7;                 /* '<Root>/LOG1_v_ph_v7' */
  real_T LOG1_v_sv_vd_ref;             /* '<Root>/LOG1_v_sv_vd_ref' */
  real_T LOG1_v_sv_vq_ref;             /* '<Root>/LOG1_v_sv_vq_ref' */
  real_T LOG1_v_sv_vd3_ref;            /* '<Root>/LOG1_v_sv_vd3_ref' */
  real_T LOG1_v_sv_vq3_ref;            /* '<Root>/LOG1_v_sv_vq3_ref' */
  real_T LOG1_v_sv_vd5_ref;            /* '<Root>/LOG1_v_sv_vd5_ref' */
  real_T LOG1_v_sv_vq5_ref;            /* '<Root>/LOG1_v_sv_vq5_ref' */
  real_T LOG1_pos_we;                  /* '<Root>/LOG1_pos_we' */
  real_T LOG1_pos_theta;               /* '<Root>/LOG1_pos_theta' */
} ExtY_CurrentControl_T;

/* Real-time Model Data Structure */
struct tag_RTM_CurrentControl_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_CurrentControl_T CurrentControl_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_CurrentControl_T CurrentControl_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_CurrentControl_T CurrentControl_Y;

/* Model entry point functions */
extern void CurrentControl_initialize(void);
extern void CurrentControl_step(void);
extern void CurrentControl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_CurrentControl_T *const CurrentControl_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Gain10' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain11' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain12' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain13' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain14' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain15' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain16' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain19' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain4' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain5' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain6' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain7' : Eliminated nontunable gain of 1
 * Block '<Root>/Gain8' : Eliminated nontunable gain of 1
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
 * '<Root>' : 'CurrentControl'
 * '<S1>'   : 'CurrentControl/Clarke Transformation'
 * '<S2>'   : 'CurrentControl/Inverse Clarke Transformation'
 * '<S3>'   : 'CurrentControl/Inverse Park Transformation dq'
 * '<S4>'   : 'CurrentControl/Inverse Park Transformation xy'
 * '<S5>'   : 'CurrentControl/Inverse Park Transformation xy1'
 * '<S6>'   : 'CurrentControl/Park Transformation dq'
 * '<S7>'   : 'CurrentControl/Park Transformation xy'
 * '<S8>'   : 'CurrentControl/Park Transformation xy1'
 * '<S9>'   : 'CurrentControl/d-axis PI'
 * '<S10>'  : 'CurrentControl/q-axis PI'
 * '<S11>'  : 'CurrentControl/x-axis PI'
 * '<S12>'  : 'CurrentControl/x-axis PI1'
 * '<S13>'  : 'CurrentControl/y-axis PI'
 * '<S14>'  : 'CurrentControl/y-axis PI1'
 */
#endif                                 /* RTW_HEADER_CurrentControl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
