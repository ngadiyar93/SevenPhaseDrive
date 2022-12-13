/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: currentRegulator.c
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

#include "currentRegulator.h"
#include "currentRegulator_private.h"

/* Block states (default storage) */
DW_currentRegulator_T currentRegulator_DW;

/* External inputs (root inport signals with default storage) */
ExtU_currentRegulator_T currentRegulator_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_currentRegulator_T currentRegulator_Y;

/* Real-time model */
static RT_MODEL_currentRegulator_T currentRegulator_M_;
RT_MODEL_currentRegulator_T *const currentRegulator_M = &currentRegulator_M_;
real_T rt_modd(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q);
    }

    if (yEq) {
      y = 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void currentRegulator_step(void)
{
  real_T rtb_Fbeta;
  real_T rtb_Sum1_j;
  real_T rtb_Sum4;
  real_T rtb_Sum5;
  real_T rtb_Sum_p;
  real_T rtb_TrigonometricFunction;
  real_T rtb_TrigonometricFunction1;

  /* Gain: '<S103>/Gain' incorporates:
   *  Gain: '<S103>/Gain2'
   *  Gain: '<S103>/Gain4'
   *  Inport: '<Root>/I_a'
   *  Inport: '<Root>/I_b'
   *  Inport: '<Root>/I_c'
   *  Sum: '<S103>/Sum'
   */
  rtb_Sum5 = ((-0.5 * currentRegulator_U.I_b + currentRegulator_U.I_a) + -0.5 *
              currentRegulator_U.I_c) * 0.66666666666666663;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Delay: '<Root>/Delay'
   *  Inport: '<Root>/omega_e'
   */
  currentRegulator_DW.Delay_DSTATE += currentRegulator_U.omega_e;

  /* Math: '<Root>/Math Function1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Delay: '<Root>/Delay'
   *  Gain: '<Root>/Gain2'
   */
  rtb_TrigonometricFunction = rt_modd(0.0001 * currentRegulator_DW.Delay_DSTATE,
    6.2831853071795862);

  /* Trigonometry: '<S102>/Trigonometric Function1' incorporates:
   *  Gain: '<S102>/Gain'
   */
  rtb_Sum1_j = cos(-rtb_TrigonometricFunction);

  /* Sum: '<S102>/Sum1' incorporates:
   *  Gain: '<S103>/Gain1'
   *  Gain: '<S103>/Gain3'
   *  Gain: '<S103>/Gain5'
   *  Inport: '<Root>/I_b'
   *  Inport: '<Root>/I_c'
   *  Sum: '<S103>/Sum1'
   */
  currentRegulator_Y.Iq = (0.8660254037844386 * currentRegulator_U.I_b +
    -0.8660254037844386 * currentRegulator_U.I_c) * 0.66666666666666663;

  /* Trigonometry: '<S102>/Trigonometric Function' incorporates:
   *  Gain: '<S102>/Gain'
   */
  rtb_TrigonometricFunction1 = sin(-rtb_TrigonometricFunction);

  /* Sum: '<S102>/Sum' incorporates:
   *  Product: '<S102>/Product'
   *  Product: '<S102>/Product1'
   */
  currentRegulator_Y.Id = rtb_Sum5 * rtb_Sum1_j - currentRegulator_Y.Iq *
    rtb_TrigonometricFunction1;

  /* Sum: '<Root>/Sum4' incorporates:
   *  Inport: '<Root>/Id_ref'
   */
  rtb_Sum4 = currentRegulator_U.Id_ref - currentRegulator_Y.Id;

  /* Sum: '<S102>/Sum1' incorporates:
   *  Product: '<S102>/Product2'
   *  Product: '<S102>/Product3'
   */
  currentRegulator_Y.Iq = rtb_Sum5 * rtb_TrigonometricFunction1 +
    currentRegulator_Y.Iq * rtb_Sum1_j;

  /* Sum: '<Root>/Sum7' incorporates:
   *  DiscreteIntegrator: '<S37>/Integrator'
   *  Fcn: '<S1>/Fcn'
   *  Gain: '<S42>/Proportional Gain'
   *  Inport: '<Root>/omega_e'
   *  Sum: '<S46>/Sum'
   */
  rtb_Sum1_j = (0.13703627154958675 * rtb_Sum4 +
                currentRegulator_DW.Integrator_DSTATE) +
    -currentRegulator_U.omega_e * 4.3040000000000008e-5 * currentRegulator_Y.Iq;

  /* Trigonometry: '<S104>/Trigonometric Function1' */
  rtb_TrigonometricFunction1 = cos(rtb_TrigonometricFunction);

  /* Sum: '<Root>/Sum5' incorporates:
   *  Inport: '<Root>/Iq_ref'
   */
  rtb_Sum5 = currentRegulator_U.Iq_ref - currentRegulator_Y.Iq;

  /* Sum: '<Root>/Sum6' incorporates:
   *  DiscreteIntegrator: '<S85>/Integrator'
   *  Fcn: '<S1>/Fcn1'
   *  Gain: '<S90>/Proportional Gain'
   *  Inport: '<Root>/omega_e'
   *  Sum: '<S94>/Sum'
   */
  rtb_Fbeta = (0.13521414781050473 * rtb_Sum5 +
               currentRegulator_DW.Integrator_DSTATE_m) + 4.362e-5 *
    currentRegulator_Y.Id * currentRegulator_U.omega_e;

  /* Trigonometry: '<S104>/Trigonometric Function' */
  rtb_TrigonometricFunction = sin(rtb_TrigonometricFunction);

  /* Sum: '<S104>/Sum' incorporates:
   *  Product: '<S104>/Product'
   *  Product: '<S104>/Product1'
   */
  rtb_Sum_p = rtb_Sum1_j * rtb_TrigonometricFunction1 - rtb_Fbeta *
    rtb_TrigonometricFunction;

  /* Sum: '<S104>/Sum1' incorporates:
   *  Product: '<S104>/Product2'
   *  Product: '<S104>/Product3'
   */
  rtb_Fbeta = rtb_Sum1_j * rtb_TrigonometricFunction + rtb_Fbeta *
    rtb_TrigonometricFunction1;

  /* Outport: '<Root>/normalized voltages' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Constant: '<Root>/Constant6'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain3'
   *  Gain: '<Root>/Gain4'
   *  Gain: '<S105>/Gain1'
   *  Gain: '<S105>/Gain2'
   *  Gain: '<S105>/Gain4'
   *  Gain: '<S105>/Gain5'
   *  Inport: '<Root>/V_dc'
   *  Product: '<Root>/Divide'
   *  Product: '<Root>/Divide1'
   *  Product: '<Root>/Divide2'
   *  Sum: '<Root>/Sum'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<Root>/Sum3'
   *  Sum: '<S105>/Sum'
   *  Sum: '<S105>/Sum1'
   */
  currentRegulator_Y.normalizedvoltages[0] = rtb_Sum_p / (0.5 *
    currentRegulator_U.V_dc) + 0.5;
  currentRegulator_Y.normalizedvoltages[1] = (0.8660254037844386 * rtb_Fbeta -
    0.5 * rtb_Sum_p) / (0.5 * currentRegulator_U.V_dc) + 0.5;
  currentRegulator_Y.normalizedvoltages[2] = ((0.0 - 0.5 * rtb_Sum_p) -
    0.8660254037844386 * rtb_Fbeta) / (0.5 * currentRegulator_U.V_dc) + 0.5;

  /* Update for DiscreteIntegrator: '<S37>/Integrator' incorporates:
   *  Gain: '<S34>/Integral Gain'
   */
  currentRegulator_DW.Integrator_DSTATE += 143.57078426905352 * rtb_Sum4 *
    0.0001;

  /* Update for DiscreteIntegrator: '<S85>/Integrator' incorporates:
   *  Gain: '<S82>/Integral Gain'
   */
  currentRegulator_DW.Integrator_DSTATE_m += 143.57078426905352 * rtb_Sum5 *
    0.0001;
}

/* Model initialize function */
void currentRegulator_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void currentRegulator_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
