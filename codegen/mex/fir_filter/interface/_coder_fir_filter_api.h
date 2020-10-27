/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fir_filter_api.h
 *
 * Code generation for function '_coder_fir_filter_api'
 *
 */

#pragma once

#define CL_HPP_CL_1_2_DEFAULT_BUILD
#define CL_HPP_TARGET_OPENCL_VERSION 120
#define CL_HPP_MINIMUM_OPENCL_VERSION 120
#define CL_HPP_ENABLE_PROGRAM_CONSTRUCTION_FROM_ARRAY_COMPATIBILITY 1
#define CL_USE_DEPRECATED_OPENCL_1_2_APIS

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "fir_filter_types.h"


#include <fcntl.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <CL/opencl.h>
#include <CL/cl_ext.h>


/* End of code generation (_coder_fir_filter_api.h) */
/*******************************************************************************
** HOST Code HEADER FILE
*******************************************************************************/




#define MAX_LENGTH 4096
#define MEM_ALIGNMENT 4096

/* Function Declarations */
void fir_filter_api(const mxArray * const prhs[2], int32_T nlhs, const mxArray
                    *plhs[1]);
 
void fir_filter_dummy(const emlrtStack *sp, real_T dataIn_dummy[4096], real_T dataIn[4096],real_T b_dummy[4096] ,real_T b[4096]);

