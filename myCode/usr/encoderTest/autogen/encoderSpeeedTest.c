/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: encoderSpeeedTest.c
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

#include "encoderSpeeedTest.h"
#include "encoderSpeeedTest_private.h"

/* Block states (default storage) */
DW_encoderSpeeedTest_T encoderSpeeedTest_DW;

/* External inputs (root inport signals with default storage) */
ExtU_encoderSpeeedTest_T encoderSpeeedTest_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_encoderSpeeedTest_T encoderSpeeedTest_Y;

/* Real-time model */
static RT_MODEL_encoderSpeeedTest_T encoderSpeeedTest_M_;
RT_MODEL_encoderSpeeedTest_T *const encoderSpeeedTest_M = &encoderSpeeedTest_M_;

/* Model step function */
void encoderSpeeedTest_step(void)
{
  real_T rtb_del_theta;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Delay: '<S1>/Delay'
   *  Delay: '<S1>/Delay1'
   *  Gain: '<S1>/Gain1'
   */
  encoderSpeeedTest_Y.omega_m = 0.030927573695189392 *
    encoderSpeeedTest_DW.Delay_DSTATE + encoderSpeeedTest_DW.Delay1_DSTATE;

  /* Outport: '<Root>/omega_e' incorporates:
   *  Gain: '<Root>/Gain11'
   */
  encoderSpeeedTest_Y.omega_e = 8.0 * encoderSpeeedTest_Y.omega_m;

  /* Gain: '<S1>/Gain2' incorporates:
   *  Delay: '<S1>/Delay1'
   */
  encoderSpeeedTest_DW.Delay1_DSTATE = 0.96907242630481061 *
    encoderSpeeedTest_Y.omega_m;

  /* MATLAB Function: '<Root>/wrap2pi' incorporates:
   *  Gain: '<Root>/Gain8'
   *  Inport: '<Root>/theta_m'
   */
  encoderSpeeedTest_Y.theta_e = 8.0 * encoderSpeeedTest_U.theta_m;
  while (encoderSpeeedTest_Y.theta_e > 6.2831853071795862) {
    encoderSpeeedTest_Y.theta_e -= 6.2831853071795862;
  }

  while (encoderSpeeedTest_Y.theta_e < 0.0) {
    encoderSpeeedTest_Y.theta_e += 6.2831853071795862;
  }

  /* End of MATLAB Function: '<Root>/wrap2pi' */

  /* MATLAB Function: '<Root>/speed_calc' incorporates:
   *  Delay: '<Root>/Delay2'
   *  Inport: '<Root>/theta_m'
   */
  for (rtb_del_theta = encoderSpeeedTest_U.theta_m -
       encoderSpeeedTest_DW.Delay2_DSTATE; rtb_del_theta > 3.1415926535897931;
       rtb_del_theta -= 6.2831853071795862) {
  }

  while (rtb_del_theta < -3.1415926535897931) {
    rtb_del_theta += 6.2831853071795862;
  }

  /* End of MATLAB Function: '<Root>/speed_calc' */

  /* Gain: '<Root>/Gain9' incorporates:
   *  Delay: '<S1>/Delay'
   */
  encoderSpeeedTest_DW.Delay_DSTATE = 10000.0 * rtb_del_theta;

  /* Update for Delay: '<Root>/Delay2' incorporates:
   *  Inport: '<Root>/theta_m'
   */
  encoderSpeeedTest_DW.Delay2_DSTATE = encoderSpeeedTest_U.theta_m;
}

/* Model initialize function */
void encoderSpeeedTest_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void encoderSpeeedTest_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
