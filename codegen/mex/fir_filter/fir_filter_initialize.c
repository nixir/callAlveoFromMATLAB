/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fir_filter_initialize.c
 *
 * Code generation for function 'fir_filter_initialize'
 *
 */

/* Include files */
#include "fir_filter_initialize.h"
#include "_coder_fir_filter_mex.h"
#include "fir_filter.h"
#include "fir_filter_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void fir_filter_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (fir_filter_initialize.c) */
