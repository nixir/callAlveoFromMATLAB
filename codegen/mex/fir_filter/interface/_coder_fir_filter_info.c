/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fir_filter_info.c
 *
 * Code generation for function '_coder_fir_filter_info'
 *
 */

/* Include files */
#include "_coder_fir_filter_info.h"
#include "emlrt.h"
#include "rt_nonfinite.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[5] = {
    "789ced55dd4ec23018ed0c1a13a3e285be04094524a8175ea01159047f064194181d5b61d57625a39879e523f81a3e828fe2e3b81f06acc91c112431fa254b77"
    "7aba9ed3efdbbe0149ae48008035e73a7801e0630578b1ea0f203918174038445e12d649e1e560112442cf4903bdd701d698c991cd7d60aa140d9fd419c5a66a",
    "f2da7317010bf5187942bac7b43141354c51751c9cb98816c7a8217029f7fec840da63b54f8165f4460ec938f0f2e1c65bc4791313e6e324221f49816f1edf42"
    "8351044dfcd0c71c43057519ec606ef45b698d5167dec6162cca8a2c2bce5939b2205539515bb08dad3b7f264d87beefa7f49d10f0c8b7cfe8b8d775c759e92d",
    "45eaf98ccefa2d82665797a348bd30df941b9543a13469c23495c04aa1562e1c42259bc96654c819232d66074521aad9816e929c9ab81197a7f5097d8be368fd"
    "7208ffebfd8c9e1db1dfa4efdd56845e52e0b94c0c626bd59bed5c9e6252caef5d5e5c97463e2e6274e27c80083caffd7f6b5f9db6fe9b31be035e63baa38b9d",
    "9fa265aa244d90d9e10698bedf8a11e5238840effd9b7ac1fe4a8c5ec037e572432cd997fd1651e25d292f633015a40cfa291bb4dfb9f58be78df3c63cf582f8"
    "2b7af3fafe6ae5facd3ed51b56e12ab76b6fefd469e6ec14fcfefefb095184bf5e", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 3056U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * epFieldName[6] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs", "FullPath", "TimeStamp" };

  mxArray *xInputs;
  const char * propFieldName[4] = { "Version", "ResolvedFunctions",
    "EntryPoints", "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 6, epFieldName);
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("fir_filter"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/nijuiti/Repo/github.com/nixir/FIRIIRfilter/matlab/fir_filter.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737972.44098379626));
  xResult = emlrtCreateStructMatrix(1, 1, 4, propFieldName);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.8.0.1359463 (R2020a) Update 1"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_fir_filter_info.c) */
