/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fir_filter_mex.c
 *
 * Code generation for function '_coder_fir_filter_mex'
 *
 */

/* Include files */
#include "_coder_fir_filter_mex.h"
#include "_coder_fir_filter_api.h"
#include "fir_filter.h"
#include "fir_filter_data.h"
#include "fir_filter_initialize.h"
#include "fir_filter_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void fir_filter_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[2]);

/* Function Definitions */
void fir_filter_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const
  mxArray *prhs[2])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        10, "fir_filter");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "fir_filter");
  }

  /* Call the function. */
  fir_filter_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&fir_filter_atexit);

  /* Module initialization. */
  fir_filter_initialize();

  /* Dispatch the entry-point. */
  fir_filter_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  fir_filter_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_fir_filter_mex.c) */
