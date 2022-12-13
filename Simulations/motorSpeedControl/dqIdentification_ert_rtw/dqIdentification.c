/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: dqIdentification.c
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

#include "dqIdentification.h"
#include "dqIdentification_private.h"

/* Block states (default storage) */
DW_dqIdentification_T dqIdentification_DW;

/* External inputs (root inport signals with default storage) */
ExtU_dqIdentification_T dqIdentification_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_dqIdentification_T dqIdentification_Y;

/* Real-time model */
static RT_MODEL_dqIdentification_T dqIdentification_M_;
RT_MODEL_dqIdentification_T *const dqIdentification_M = &dqIdentification_M_;

/* Model step function */
void dqIdentification_step(void)
{
  real_T rtb_Integrator_h;
  real_T rtb_Sum4;
  real_T rtb_Sum7;
  real_T rtb_Sum8;
  real_T rtb_Sum_p;
  real_T rtb_TrigonometricFunction;
  real_T rtb_y;

  /* Gain: '<S104>/Gain' incorporates:
   *  Gain: '<S104>/Gain2'
   *  Gain: '<S104>/Gain4'
   *  Inport: '<Root>/I_a'
   *  Inport: '<Root>/I_b'
   *  Inport: '<Root>/I_c'
   *  Sum: '<S104>/Sum'
   */
  rtb_TrigonometricFunction = ((-0.5 * dqIdentification_U.I_b +
    dqIdentification_U.I_a) + -0.5 * dqIdentification_U.I_c) *
    0.66666666666666663;

  /* MATLAB Function: '<Root>/wrap2pi' incorporates:
   *  Gain: '<Root>/Gain8'
   *  Inport: '<Root>/theta_m'
   */
  for (rtb_y = 8.0 * dqIdentification_U.theta_m; rtb_y > 6.2831853071795862;
       rtb_y -= 6.2831853071795862) {
  }

  while (rtb_y < 0.0) {
    rtb_y += 6.2831853071795862;
  }

  /* End of MATLAB Function: '<Root>/wrap2pi' */

  /* Trigonometry: '<S103>/Trigonometric Function1' incorporates:
   *  Gain: '<S103>/Gain'
   */
  rtb_Sum8 = cos(-rtb_y);

  /* Gain: '<S104>/Gain1' incorporates:
   *  Gain: '<S104>/Gain3'
   *  Gain: '<S104>/Gain5'
   *  Inport: '<Root>/I_b'
   *  Inport: '<Root>/I_c'
   *  Sum: '<S104>/Sum1'
   */
  rtb_Sum4 = (0.8660254037844386 * dqIdentification_U.I_b + -0.8660254037844386 *
              dqIdentification_U.I_c) * 0.66666666666666663;

  /* Trigonometry: '<S103>/Trigonometric Function' incorporates:
   *  Gain: '<S103>/Gain'
   */
  rtb_Integrator_h = sin(-rtb_y);

  /* Sum: '<S103>/Sum' incorporates:
   *  Product: '<S103>/Product'
   *  Product: '<S103>/Product1'
   */
  rtb_Sum7 = rtb_TrigonometricFunction * rtb_Sum8 - rtb_Sum4 * rtb_Integrator_h;

  /* Sum: '<Root>/Sum8' incorporates:
   *  Inport: '<Root>/Iq_ref'
   *  Product: '<S103>/Product2'
   *  Product: '<S103>/Product3'
   *  Sum: '<S103>/Sum1'
   */
  rtb_Sum8 = dqIdentification_U.Iq_ref - (rtb_TrigonometricFunction *
    rtb_Integrator_h + rtb_Sum4 * rtb_Sum8);

  /* Sum: '<Root>/Sum5' incorporates:
   *  DiscreteIntegrator: '<S86>/Integrator'
   *  Gain: '<S91>/Proportional Gain'
   *  Sum: '<S95>/Sum'
   */
  rtb_Integrator_h = 0.24928537706235007 * rtb_Sum8 +
    dqIdentification_DW.Integrator_DSTATE;

  /* Trigonometry: '<S105>/Trigonometric Function' */
  rtb_TrigonometricFunction = sin(rtb_y);

  /* Sum: '<Root>/Sum7' incorporates:
   *  Inport: '<Root>/Id_ref'
   */
  rtb_Sum7 = dqIdentification_U.Id_ref - rtb_Sum7;

  /* Sum: '<Root>/Sum4' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   *  Gain: '<S43>/Proportional Gain'
   *  Sum: '<S47>/Sum'
   */
  rtb_Sum4 = 0.24928537706235007 * rtb_Sum7 +
    dqIdentification_DW.Integrator_DSTATE_e;

  /* Trigonometry: '<S105>/Trigonometric Function1' */
  rtb_y = cos(rtb_y);

  /* Sum: '<S105>/Sum' incorporates:
   *  Product: '<S105>/Product'
   *  Product: '<S105>/Product1'
   */
  rtb_Sum_p = rtb_Sum4 * rtb_y - rtb_Integrator_h * rtb_TrigonometricFunction;

  /* Sum: '<S105>/Sum1' incorporates:
   *  Product: '<S105>/Product2'
   *  Product: '<S105>/Product3'
   */
  rtb_y = rtb_Sum4 * rtb_TrigonometricFunction + rtb_Integrator_h * rtb_y;

  /* Outport: '<Root>/normalized voltages' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain3'
   *  Gain: '<Root>/Gain4'
   *  Gain: '<S106>/Gain1'
   *  Gain: '<S106>/Gain2'
   *  Gain: '<S106>/Gain4'
   *  Gain: '<S106>/Gain5'
   *  Inport: '<Root>/V_dc'
   *  Product: '<Root>/Divide'
   *  Product: '<Root>/Divide1'
   *  Product: '<Root>/Divide2'
   *  Sum: '<Root>/Sum'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<Root>/Sum3'
   *  Sum: '<S106>/Sum'
   *  Sum: '<S106>/Sum1'
   */
  dqIdentification_Y.normalizedvoltages[0] = rtb_Sum_p / (0.5 *
    dqIdentification_U.V_dc) + 0.5;
  dqIdentification_Y.normalizedvoltages[1] = (0.8660254037844386 * rtb_y - 0.5 *
    rtb_Sum_p) / (0.5 * dqIdentification_U.V_dc) + 0.5;
  dqIdentification_Y.normalizedvoltages[2] = ((0.0 - 0.5 * rtb_Sum_p) -
    0.8660254037844386 * rtb_y) / (0.5 * dqIdentification_U.V_dc) + 0.5;

  /* Update for DiscreteIntegrator: '<S86>/Integrator' incorporates:
   *  Gain: '<S83>/Integral Gain'
   */
  dqIdentification_DW.Integrator_DSTATE += 212.05750411731103 * rtb_Sum8 *
    0.0001;

  /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
   *  Gain: '<S35>/Integral Gain'
   */
  dqIdentification_DW.Integrator_DSTATE_e += 212.05750411731103 * rtb_Sum7 *
    0.0001;
}

/* Model initialize function */
void dqIdentification_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void dqIdentification_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
