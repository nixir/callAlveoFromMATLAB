/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fir_filter.h
 *
 * Code generation for function 'fir_filter'
 *
 */

#pragma once

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "fir_filter_types.h"

/* Function Declarations */
// void fir_filter(const emlrtStack *sp, const real_T dataIn[4096], const real_T b[4], real_T myFunc[4096]);
void fir_filter(const real_T dataIn[4096], const real_T b[4], real_T myFunc[4096]);
/* End of code generation (fir_filter.h) */
