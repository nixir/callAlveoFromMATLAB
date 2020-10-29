# call Alveo (accelerator card) from MATLAB example

An example of how to execute an operation in Xilinx Alveo accelerator card from MATLAB.

This README.md is under CC BY 4.0 license , although whole this repository is not free to use because the license of the referd repository is unknown.
## How to execute
There are some limitations in the MEX execution of MATLAB, so it is not likely to be possible to run acceleration in Alveo as it is.

 - The MEX executable does not accept standard input.
	 - We need to write the path to the xclbin file directly to the source code or to pass path via mex API.
 - MATLAB overwrites the LD_PRELOAD environment variable.
	 - In the dynamic linking of the library, an error occurs when executing it because different versions of the library are linked depending on the environment.

Please see 
 - https://github.com/nixir/callAlveoFromMATLAB/blob/main/run.fish
 - https://github.com/nixir/callAlveoFromMATLAB/blob/main/codegen/mex/fir_filter/interface/_coder_fir_filter_api.c

## Build

 1. Move ./codegen/mex/fir_filter
 2. Set your card name at design.cfg
 3. Build with ninja (Maybe need some uncomment. Please see build.ninja)
 4. Copy mex file and xclbin to top directory

## Outputs
```
kodama@XXXXXXX ~/R/callAlveoFromMATLAB> fish run.fish
MATLAB is selecting SOFTWARE OPENGL rendering.

                 < M A T L A B (R) >
       Copyright 1984-2019 The MathWorks, Inc.
   R2019b Update 1 (9.7.0.1216025) 64-bit (glnxa64)
                  September 26, 2019


To get started, type doc.
For product information, visit www.mathworks.com.

>> FIRfilter
    0.0065    0.4935    0.4935    0.0065

Elapsed time is 0.004253 seconds.
/usr/local/MATLAB/R2019b/sys/opengl/lib/glnxa64:/usr/local/MATLAB/R2019b/sys/os/glnxa64:/usr/local/MATLAB/R2019b/bin/glnxa64:/usr/local/MATLAB/R2019b/extern/lib/glnxa64:/usr/local/MATLAB/R2019b/sys/java/jre/glnxa64/jre/lib/amd64/native_threads:/usr/local/MATLAB/R2019b/sys/java/jre/glnxa64/jre/lib/amd64/server:/opt/xilinx/xrt/lib:/tools/Xilinx/Vitis/2019.2/lib/lnx64.o/Ubuntu/18:/tools/Xilinx/Vitis/2019.2/lib/lnx64.o/Ubuntu:/tools/Xilinx/Vitis/2019.2/lib/lnx64.o:/tools/Xilinx/Vitis/2019.2/runtime/lib/x86_64:/opt/xilinx/xrt/lib:/tools/Xilinx/Vitis/2019.2/lib/lnx64.o/Ubuntu/18:/tools/Xilinx/Vitis/2019.2/lib/lnx64.o/Ubuntu:/tools/Xilinx/Vitis/2019.2/lib/lnx64.o:/tools/Xilinx/Vitis/2019.2/runtime/lib/x86_64:/tools/Xilinx/Vivado/2019.2/lnx64/tools/opencv/opencv_gcc/:/tools/Xilinx/Vivado/2019.2/lnx64/tools/opencv/opencv_gcc/

INFO: Found 2 platforms
INFO: Selected platform 1 from Xilinx
INFO: Found 1 devices
CL_DEVICE_NAME xilinx_u250_xdma_201830_2
Selected xilinx_u250_xdma_201830_2 as the target device
INFO: Make context
INFO: create a computer context
INFO!create a command commands!
INFO: loading xclbin ./fir_filter.xilinx_u250_xdma_201830_2.xclbin
INFO:load kernel from xclbin!
INFO:create compute program from binary
INFO: build program executable!
INFO: create compute kernel_fir_filter!
FPGA execution time is 38671 nano sec
Elapsed time is 0.617696 seconds.

ans =

  logical

   1

>>
```

## Reference 
 - Vitis-Tutorial https://github.com/Xilinx/Vitis-Tutorials/blob/master/docs/my-first-program/reference-files/src/host.c
	- (Above file added this file https://github.com/nixir/callAlveoFromMATLAB/blob/main/codegen/mex/fir_filter/interface/_coder_fir_filter_api.c)

 - And These codes generated by MATLAB Coder (Academic License)

