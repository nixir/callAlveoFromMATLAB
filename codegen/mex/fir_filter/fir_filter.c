/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fir_filter.c
 *
 * Code generation for function 'fir_filter'
 *
 */

/* Include files */
// #include "fir_filter.h"
// #include "fir_filter_data.h"
// #include "rt_nonfinite.h"

// /* Variable Definitions */
// static emlrtMCInfo emlrtMCI = {
//     2,                                                                     /* lineNo */
//     1,                                                                     /* colNo */
//     "fir_filter",                                                          /* fName */
//     "/home/nijuiti/Repo/github.com/nixir/FIRIIRfilter/matlab/fir_filter.m" /* pName */
// };

// static emlrtBCInfo emlrtBCI = {
//     1,                                                                      /* iFirst */
//     4096,                                                                   /* iLast */
//     8,                                                                      /* lineNo */
//     52,                                                                     /* colNo */
//     "dataIn",                                                               /* aName */
//     "fir_filter",                                                           /* fName */
//     "/home/nijuiti/Repo/github.com/nixir/FIRIIRfilter/matlab/fir_filter.m", /* pName */
//     0                                                                       /* checkKind */
// };

// static emlrtBCInfo b_emlrtBCI = {
//     1,                                                                      /* iFirst */
//     4096,                                                                   /* iLast */
//     8,                                                                      /* lineNo */
//     77,                                                                     /* colNo */
//     "dataIn",                                                               /* aName */
//     "fir_filter",                                                           /* fName */
//     "/home/nijuiti/Repo/github.com/nixir/FIRIIRfilter/matlab/fir_filter.m", /* pName */
//     0                                                                       /* checkKind */
// };

// static emlrtBCInfo c_emlrtBCI = {
//     1,                                                                      /* iFirst */
//     4096,                                                                   /* iLast */
//     8,                                                                      /* lineNo */
//     102,                                                                    /* colNo */
//     "dataIn",                                                               /* aName */
//     "fir_filter",                                                           /* fName */
//     "/home/nijuiti/Repo/github.com/nixir/FIRIIRfilter/matlab/fir_filter.m", /* pName */
//     0                                                                       /* checkKind */
// };

// static emlrtRSInfo emlrtRSI = {
//     2,                                                                     /* lineNo */
//     "fir_filter",                                                          /* fcnName */
//     "/home/nijuiti/Repo/github.com/nixir/FIRIIRfilter/matlab/fir_filter.m" /* pathName */
// };

// /* Function Declarations */
// static void disp(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);

// /* Function Definitions */
// static void disp(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
// {
//   const mxArray *pArray;
//   pArray = b;
//   emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "disp", true, location);
// }

// void fir_filter(const emlrtStack *sp, const real_T dataIn[4096], const real_T b[4], real_T myFunc[4096])
void fir_filter(const double dataIn[4096], const double b[4096], double myFunc[4096])
{
  #pragma HLS INTERFACE m_axi port=dataIn  offset=slave bundle=gmem
  #pragma HLS INTERFACE m_axi port=b  offset=slave bundle=gmem
  #pragma HLS INTERFACE m_axi port=myFunc offset=slave bundle=gmem
  #pragma HLS INTERFACE s_axilite port=dataIn  bundle=control
  #pragma HLS INTERFACE s_axilite port=b  bundle=control
  #pragma HLS INTERFACE s_axilite port=myFunc bundle=control
  // #pragma HLS INTERFACE s_axilite port=size bundle=control
 #pragma HLS INTERFACE s_axilite port=return bundle=control

  // const mxArray *y;
  // const mxArray *m;
  // static const int32_T iv[2] = {1, 4};

  // real_T *pData;
  int b_index;
  int i;
  int i1;
  // emlrtStack st;
  // st.prev = sp;
  // st.tls = sp->tls;
  // y = NULL;
  // m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  // pData = emlrtMxGetPr(m);
  // pData[0] = b[0];
  // pData[1] = b[1];
  // pData[2] = b[2];
  // pData[3] = b[3];
  // emlrtAssign(&y, m);
  // st.site = &emlrtRSI;
  // disp(&st, y, &emlrtMCI);
  for (b_index = 0; b_index < 4096; b_index++)
  {
#pragma HLS PIPELINE II=1
    if (b_index + 1 < 4)
    {
      myFunc[b_index] = 0.0;
    }
    else
    {
      // if (b_index < 1)
      // {
      //   // emlrtDynamicBoundsCheckR2012b(0, 1, 4096, &emlrtBCI, sp);
      // }

      i = b_index - 1;
      // if (i < 1)
      // {
      //   // emlrtDynamicBoundsCheckR2012b(0, 1, 4096, &b_emlrtBCI, sp);
      // }

      i1 = b_index - 2;
      // if (i1 < 1)
      // {
      //   // emlrtDynamicBoundsCheckR2012b(i1, 1, 4096, &c_emlrtBCI, sp);
      // }

      myFunc[b_index] = ((b[0] * dataIn[b_index] + b[1] * dataIn[b_index - 1]) +
                         b[2] * dataIn[i - 1]) +
                        b[3] * dataIn[i1 - 1];

      /*      myFunc(index) = myFunc(index); */
    }

    // if (*emlrtBreakCheckR2012bFlagVar != 0)
    // {
    //   // emlrtBreakCheckR2012b(sp);
    // }
  }
}



/* End of code generation (fir_filter.c) */
