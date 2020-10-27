/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fir_filter_api.c
 *
 * Code generation for function '_coder_fir_filter_api'
 *
 */

/* Include files */
#include <iostream>
#include <chrono>
#include <math.h>
#include "_coder_fir_filter_api.h"
#include "fir_filter.h"
#include "fir_filter_data.h"
#include "rt_nonfinite.h"



/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const emlrtMsgIdentifier *parentId))[4096];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b, const char_T *identifier))[4];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const emlrtMsgIdentifier *parentId))[4];
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4096];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *dataIn,
                                 const char_T *identifier))[4096];
static const mxArray *emlrt_marshallOut(const real_T u[4096]);
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4];

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const emlrtMsgIdentifier *parentId))[4096]
{
  real_T(*y)[4096];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b,
                                   const char_T *identifier))[4]
{
  real_T(*y)[4];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(b), &thisId);
  emlrtDestroyArray(&b);
  return y;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const emlrtMsgIdentifier *parentId))[4]
{
  real_T(*y)[4];
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4096]
{
  real_T(*ret)[4096];
  static const int32_T dims[1] = {4096};

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T(*)[4096])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *dataIn,
                                 const char_T *identifier))[4096]
{
  real_T(*y)[4096];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(dataIn), &thisId);
  emlrtDestroyArray(&dataIn);
  return y;
}
static const mxArray *emlrt_marshallOut(const real_T u[4096])
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[1] = {0};

  static const int32_T iv1[1] = {4096};

  y = NULL;
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, iv1, 1);
  emlrtAssign(&y, m);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4]
{
  real_T(*ret)[4];
  static const int32_T dims[2] = {1, 4};

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T(*)[4])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

//////////////////////////////////////////////

cl_uint load_file_to_memory(const char *filename, char **result)
{
    cl_uint size = 0;
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        *result = NULL;
        return -1; // -1 means file opening fail
    }
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);
    *result = (char *)malloc(size+1);
    if (size != fread(*result, sizeof(char), size, f)) {
        free(*result);
        return -2; // -2 means file reading fail
    }
    fclose(f);
    (*result)[size] = 0;
    return size;
}

void fir_filter_dummy(const emlrtStack *sp, real_T dataIn_dummy[4096], real_T dataIn[4096], real_T b_dummy[4], real_T b[4])
{
  for (int i = 0; i < 4; i++)
  {
    b_dummy[i] = b[i];
  }

  for (int i = 0; i < 4096; i++)
  {
    dataIn_dummy[i] = dataIn[i];
  }
}


void fir_filter_api(const mxArray *const prhs[2], int32_T nlhs, const mxArray *plhs[1])
{
  real_T(*myFunc)[4096];
  real_T(*dataIn)[4096];
  real_T dataIn_ocl_tmp[4096];
  real_T(*b)[4];
  // real_T(*b_ocl_tmp)[4];
  real_T b_ocl_tmp[4];
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  myFunc = (real_T(*)[4096])mxMalloc(sizeof(real_T[4096]));

  /* Marshall function inputs */
  dataIn = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "dataIn");
  b = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "b");

  /* Invoke the target function */
  fir_filter_dummy(&st, dataIn_ocl_tmp, *dataIn, b_ocl_tmp, *b);

  //////////////////////////////////////////////////////////////////////////////////////////////

  /*******************************************************************************
** HOST Code
*******************************************************************************/

  cl_int err;
  cl_uint check_status = 0;
  const cl_uint DATA_SIZE = 4096;

  cl_platform_id platform_id;
  cl_device_id device_id;
  cl_context context;
  cl_command_queue commands;
  cl_program program;
  cl_kernel kernel_fir_filter;

  cl_mem buffer_in1;
  cl_mem buffer_in2;
  cl_mem buffer_output;
  cl_mem pt[2];
  //      cl_mem* buffer_in[2];

  real_T *dataIn_ocl;
  real_T *b_ocl;
  real_T *source_sw_results;
  char cl_platform_vendor[1001];

  const char *target_device_name = "xilinx_u250_xdma_201830_2";
  // const char *target_device_name = {'x','i','l','n','x','_','u','2','5','0','_','x','d','m','a','_','2','0','1','8','3','0','_','2'};
  cl_platform_id platforms[16];
  cl_uint platform_count;
  cl_uint platform_found = 0;

  cl_uint num_devices;
  cl_uint device_found = 0;
  cl_device_id devices[16];
  char cl_device_name[1001];

  dataIn_ocl = (real_T *)aligned_alloc(MEM_ALIGNMENT, MAX_LENGTH * sizeof(real_T *));
  b_ocl = (real_T *)aligned_alloc(4096, 4096 * sizeof(real_T *));
  // source_sw_results = (cl_uint *)aligned_alloc(MEM_ALIGNMENT, MAX_LENGTH * sizeof(cl_uint *));
source_sw_results = (real_T *)aligned_alloc(MEM_ALIGNMENT, MAX_LENGTH * sizeof(real_T *));
  real_T *source_hw_results = (real_T *)aligned_alloc(MEM_ALIGNMENT, MAX_LENGTH * sizeof(real_T *));

  for (cl_uint i = 0; i < MAX_LENGTH; i++)
  {
     dataIn_ocl[i] = (dataIn_ocl_tmp[i]);
    // dataIn_ocl[i] = round(dataIn_ocl_tmp[i]);
    // std::cout << "input " << dataIn_ocl[i] << std::endl;
    // b_ocl[i] = rand() % DATA_SIZE;
    // source_sw_results[i] = dataIn_ocl[i] + b_ocl[i];
    source_hw_results[i] = 0;
  }

  for (int i = 0; i < 4096; i++)
  {
    b_ocl[i] = (b_ocl_tmp[i%4]);
    // b_ocl[i] = round(b_ocl_tmp[i%4]);
    source_sw_results[i] = dataIn_ocl[i] + b_ocl[i];
  }

  // printf("Debug:Input Checking..");
  
  // for (int iter = 0; iter < 10; iter++){
  //   printf("dataIn1[%d] = %d\n",iter,dataIn_ocl[iter]);
  //   printf("dataIn2[%d] = %d\n",iter,b_ocl[iter]);
  //   printf("sw_result[%d] = %d\n",iter,source_sw_results[iter]);
  //   printf("rand: %d\n",rand() % DATA_SIZE);
  // }

  // ------------------------------------------------------------------------------------
  // Step 1: Get All PLATFORMS, then search for Target_Platform_Vendor (CL_PLATFORM_VENDOR)
  // ------------------------------------------------------------------------------------

  // Get the number of platforms
  // ..................................................

  err = clGetPlatformIDs(16, platforms, &platform_count);
  if (err != CL_SUCCESS)
  {
    printf("Error: Failed to find an OpenCL platform!\n");
    printf("Test failed\n");
    // //return EXIT_FAILURE;
  }

  printf("INFO: Found %d platforms\n", platform_count);

  // ....................................................................................
  // step 1:  Search for Platform (ex: Xilinx) using: CL_PLATFORM_VENDOR = Target_Platform_Vendor
  // Check if the current platform matches Target_Platform_Vendor
  // ....................................................................................

    for (cl_uint iplat=0; iplat<platform_count; iplat++) {
        err = clGetPlatformInfo(platforms[iplat], CL_PLATFORM_VENDOR, 1000, (void *)cl_platform_vendor,NULL);
        if (err != CL_SUCCESS) {
            printf("Error: clGetPlatformInfo(CL_PLATFORM_VENDOR) failed!\n");
            printf("Test failed\n");
            // return EXIT_FAILURE;
        }
        if (strcmp(cl_platform_vendor, "Xilinx") == 0) {
            printf("INFO: Selected platform %d from %s\n", iplat, cl_platform_vendor);
            platform_id = platforms[iplat];
            platform_found = 1;
        }
    }
    if (!platform_found) {
        printf("ERROR: Platform Xilinx not found. Exit.\n");
        // return EXIT_FAILURE;
    }
  // ------------------------------------------------------------------------------------
  // Step 1:  Get All Devices for selected platform Target_Platform_ID
  //            then search for Xilinx platform (CL_DEVICE_TYPE_ACCELERATOR = Target_Device_Name)
  // ------------------------------------------------------------------------------------

  err = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_ACCELERATOR, 16, devices, &num_devices);
  printf("INFO: Found %d devices\n", num_devices);
  if (err != CL_SUCCESS)
  {
    printf("ERROR: Failed to create a device group!\n");
    printf("ERROR: Test failed\n");
    // return -1;
  }
  // ------------------------------------------------------------------------------------
  // Step 1:  Search for CL_DEVICE_NAME = Target_Device_Name
  // ............................................................................

  for (cl_uint i = 0; i < num_devices; i++)
  {
    err = clGetDeviceInfo(devices[i], CL_DEVICE_NAME, 1024, cl_device_name, 0);
    if (err != CL_SUCCESS)
    {
      printf("Error: Failed to get device name for device %d!\n", i);
      printf("Test failed\n");
      //return EXIT_FAILURE;
    }
    printf("CL_DEVICE_NAME %s\n", cl_device_name);

    // ............................................................................
    // Step 1: Check if the current device matches Target_Device_Name
    // ............................................................................

    if (strcmp(cl_device_name, target_device_name) == 0)
    {
      device_id = devices[i];
      device_found = 1;
      printf("Selected %s as the target device\n", cl_device_name);
    }
  }
  // ------------------------------------------------------------------------------------
  // Step 1: Create Context
  // ------------------------------------------------------------------------------------
  printf("INFO: Make context\n");
  context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
  if (!context)
  {
    printf("Error: Failed to create a compute context!\n");
    printf("Test failed\n");
    //return EXIT_FAILURE;
  }else{
    printf("INFO: create a computer context\n");
  }

  // ------------------------------------------------------------------------------------
  // Step 1: Create Command Queue
  // ------------------------------------------------------------------------------------
  commands = clCreateCommandQueue(context, device_id, CL_QUEUE_PROFILING_ENABLE, &err);
  if (!commands)
  {
    printf("Error: Failed to create a command commands!\n");
    printf("Error: code %i\n", err);
    printf("Test failed\n");
    //return EXIT_FAILURE;
  }else{
    printf("INFO!create a command commands!\n");
  }

  cl_int status;

  unsigned char *kernelbinary;
  char *xclbin = "./fir_filter.xilinx_u250_xdma_201830_2.xclbin";
  // ------------------------------------------------------------------
  // Step 1: Load Binary File from a disk to Memory
  // ------------------------------------------------------------------

  printf("INFO: loading xclbin %s\n", xclbin);
  cl_uint n_i0 = load_file_to_memory(xclbin, (char **)&kernelbinary);
  if (n_i0 < 0)
  {
    printf("failed to load kernel from xclbin: %s\n", xclbin);
    printf("Test failed\n");
    //return EXIT_FAILURE;
  }else{
    printf("INFO:load kernel from xclbin!\n");
  }

  size_t n0 = n_i0;

  // ------------------------------------------------------------
  // Step 1: Create a program using a Binary File
  // ------------------------------------------------------------

  program = clCreateProgramWithBinary(context, 1, &device_id, &n0,
                                      (const unsigned char **)&kernelbinary, &status, &err);
  free(kernelbinary);

  // ============================================================================
  // Step 2: Create Program and Kernels
  // ============================================================================
  //   o) Build a Program from a Binary File
  //   o) Create Kernels
  // ============================================================================

  if ((!program) || (err != CL_SUCCESS))
  {
    printf("Error: Failed to create compute program from binary %d!\n", err);
    printf("Test failed\n");
    //return EXIT_FAILURE;
  }else{
    printf("INFO:create compute program from binary\n");
  }

  // -------------------------------------------------------------
  // Step 2: Build (compiles and links) a program executable from binary
  // -------------------------------------------------------------

  err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
  if (err != CL_SUCCESS)
  {
    size_t len;
    char buffer[2048];

    printf("Error: Failed to build program executable!\n");
    clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
    printf("%s\n", buffer);
    printf("Test failed\n");
    //return EXIT_FAILURE;
  }else{
    printf("INFO: build program executable!\n");
  }
  // -------------------------------------------------------------
  // Step 2: Create Kernels
  // -------------------------------------------------------------

  kernel_fir_filter = clCreateKernel(program, "fir_filter", &err);
  if (!kernel_fir_filter || err != CL_SUCCESS)
  {
    printf("Error: Failed to create compute kernel_fir_filter!\n");
    printf("Test failed\n");
    //return EXIT_FAILURE;
  }else{
    printf("INFO: create compute kernel_fir_filter!\n");
  }
  // ================================================================
  // Step 2: Setup Buffers and un Kernels
  // ================================================================
  //   o) Allocate Memory to store the results
  //   o) Create Buffers in Global Memory to store data
  // ================================================================

  // ------------------------------------------------------------------
  // Step 2: Create Buffers in Global Memory to store data
  //             o) buffer_in1 - stores dataIn_ocl
  //             o) buffer_in2 - stores b_ocl
  //             o) buffer_ouput - stores Results
  // ------------------------------------------------------------------

  // .......................................................
  // Allocate Global Memory for dataIn_ocl
  // .......................................................

  buffer_in1 = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, sizeof(real_T) * DATA_SIZE, dataIn_ocl, &err);
  if (err != CL_SUCCESS)
  {
    std::cout << "Return code for clCreateBuffer - in1" << err << std::endl;
  }
  // .......................................................
  // Allocate Global Memory for b_ocl
  // .......................................................

  buffer_in2 = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_USE_HOST_PTR, sizeof(real_T) * DATA_SIZE, b_ocl, &err);
  if (err != CL_SUCCESS)
  {
    std::cout << "Return code for clCreateBuffer -in2" << err << std::endl;
  }
  // .......................................................
  // Allocate Global Memory for source_hw_results
  // .......................................................

  buffer_output = clCreateBuffer(context, CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR, sizeof(real_T) * DATA_SIZE, source_hw_results, &err);
  if (err != CL_SUCCESS)
  {
    std::cout << "Return code for clCreateBuffer -ouput" << err << std::endl;
  }

  if (!(buffer_in1 && buffer_in2 && buffer_output))
  {
    printf("Error: Failed to allocate device memory!\n");
    printf("Test failed\n");
    //return EXIT_FAILURE;
  }
  // ------------------------------------------------------
  // Step 2: Copy Input data from Host to Global Memory
  // ------------------------------------------------------

  pt[0] = buffer_in1;
  pt[1] = buffer_in2;
  pt[2] = buffer_output;

  err = clEnqueueMigrateMemObjects(commands, (cl_uint)2, pt, 0, 0, NULL, NULL);

  // ============================================================================
  // Step 2: Set Kernel Arguments and Run the Application
  //         o) Set Kernel Arguments
  // 				----------------------------------------------------
  // 				 Kernel	Argument Nb    Description
  // 				----------------------------------------------------
  //				        in1   (input)     --> Input Vector1
  //					in2   (input)     --> Input Vector2
  //					out   (output)    --> Output Vector
  //					size  (input)     --> Size of Vector in Integer
  //         o) Copy Input Data from Host to Global Memory
  //         o) Submit Kernels for Execution
  //         o) Copy Results from Global Memory to Host
  // ============================================================================

  err = 0;
  cl_int size = DATA_SIZE;
  err |= clSetKernelArg(kernel_fir_filter, 0, sizeof(cl_mem), &buffer_in1);
  err |= clSetKernelArg(kernel_fir_filter, 1, sizeof(cl_mem), &buffer_in2);
  err |= clSetKernelArg(kernel_fir_filter, 2, sizeof(cl_mem), &buffer_output);
  // err |= clSetKernelArg(kernel_fir_filter, 3, sizeof(cl_int), &size);

  if (err != CL_SUCCESS)
  {
    printf("Error: Failed to set kernel_fir_filter arguments! %d\n", err);
    printf("Test failed\n");
  }

  // ----------------------------------------
  // Step 2: Submit Kernels for Execution
  // ----------------------------------------
  auto start = std::chrono::system_clock::now();
  err = clEnqueueTask(commands, kernel_fir_filter, 0, NULL, NULL);
  if (err)
  {
    printf("Error: Failed to execute kernel! %d\n", err);
    printf("Test failed\n");
    //return EXIT_FAILURE;
  }
    err = 0;


 auto end = std::chrono::system_clock::now();
     auto dur = end - start;
    auto nsec = std::chrono::duration_cast<std::chrono::nanoseconds>(dur).count();
    std::cout << "FPGA execution time is "<< nsec << " nano sec \n";

  // --------------------------------------------------
  // Step 2: Copy Results from Global Memory to Host
  // --------------------------------------------------

  //   err |= clEnqueueReadBuffer( commands,buffer_output, CL_TRUE, 0, sizeof(cl_uint) * DATA_SIZE, source_hw_results, 0, NULL, NULL );
  err |= clEnqueueMigrateMemObjects(commands, (cl_uint)1, &pt[2], CL_MIGRATE_MEM_OBJECT_HOST, 0, NULL, NULL);

  if (err != CL_SUCCESS)
  {
    printf("Error: Failed to write to source array: %d!\n", err);
    printf("Test failed\n");
    //return EXIT_FAILURE;
  }

  clFinish(commands);

  // ============================================================================
  // Step 2: Processing Output Results
  //       o) Check correctness of the output results
  // ============================================================================

/*  for (cl_uint i = 0; i < DATA_SIZE; i++)
  {
    if ((source_hw_results[i] != source_sw_results[i]))
    {
      printf("Iteration : %d",i);
      printf("\n Expected %d", source_hw_results[i]);
      printf("-----  Got %d\n", source_sw_results[i]);
      printf(" Error: Reuslt mismatch\n");
      check_status = 1;
      break;
    }
  }*/
  real_T tmp_hw_result[4096];
  
  for (int iter = 0;iter < 4096;iter++  ){
    tmp_hw_result[iter] = source_hw_results[iter];
  }
  // for (int iter = 0;iter < 10;iter++  ){
  //   printf("tmp_hw_result[%d] = %f \n",iter,tmp_hw_result[iter]);
  // }
  
  fir_filter_dummy(&st, *myFunc, tmp_hw_result, b_ocl_tmp, *b);

  // ============================================================================
  // Step 3: Release Allocated Resources
  // ============================================================================

  clReleaseMemObject(buffer_in1);
  clReleaseMemObject(buffer_in2);
  clReleaseMemObject(buffer_output);

  free(dataIn_ocl);
  free(b_ocl);
  // free(source_sw_results);
  free(source_hw_results);

  clReleaseProgram(program);
  clReleaseKernel(kernel_fir_filter);
  clReleaseCommandQueue(commands);
  clReleaseContext(context);

  //////////////////////////////////////////////////////////////////////////////////////////////

  // fir_filter(&st, dataIn_ocl_tmp, b_ocl_tmp, *myFunc);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*myFunc);
}

/* End of code generation (_coder_fir_filter_api.c) */
