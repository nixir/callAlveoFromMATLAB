clear;
clc;
close all;
%% MatlabFunc
% FIR hamming 3
ham = ham3;

load('hamZ.mat');

dataIn= rand(4096,1);

matlabfir = filter(ham,dataIn);
figure
freqz(dataIn,matlabfir,'whole')
title('MATLABのfilter関数を用いたフィルタリング');

%% myFunc
tic
myFunc = fir_filter(dataIn,b);
toc
%
% figure(4)
% freqz(b,a,'whole')
figure
freqz(dataIn,myFunc,'whole')
title('自身で畳み込んだフィルタリング');

%% codegen
% cfg = coder.config('mex');
% cfg.TargetLang = 'C';
% % cfg.DynamicMemoryAllocation = 'Off';
% cfg.InitFltsAndDblsToZero = false;
% cfg.EnableMemcpy = false;
% cfg.SaturateOnIntegerOverflow = false;
% codegen -config cfg 'fir_filter' -args {dataIn, b}

% setenv('XCL_EMULATION_MODE','sw_emu')
% setenv('LD_LIBRARY_PATH','/opt/xilinx/xrt/lib:/tools/Xilinx/Vitis/2019.2/lib/lnx64.o/Ubuntu/18:/tools/Xilinx/Vitis/2019.2/lib/lnx64.o/Ubuntu:/tools/Xilinx/Vitis/2019.2/lib/lnx64.o:/tools/Xilinx/Vitis/2019.2/runtime/lib/x86_64:/opt/xilinx/xrt/lib:/tools/Xilinx/Vitis/2019.2/lib/lnx64.o/Ubuntu/18:/tools/Xilinx/Vitis/2019.2/lib/lnx64.o/Ubuntu:/tools/Xilinx/Vitis/2019.2/lib/lnx64.o:/tools/Xilinx/Vitis/2019.2/runtime/lib/x86_64:/tools/Xilinx/Vivado/2019.2/lnx64/tools/opencv/opencv_gcc/:/tools/Xilinx/Vivado/2019.2/lnx64/tools/opencv/opencv_gcc/:/usr/local/MATLAB/R2019b/sys/opengl/lib/glnxa64:/usr/local/MATLAB/R2019b/sys/os/glnxa64:/usr/local/MATLAB/R2019b/bin/glnxa64:/usr/local/MATLAB/R2019b/extern/lib/glnxa64:/usr/local/MATLAB/R2019b/sys/java/jre/glnxa64/jre/lib/amd64/native_threads:/usr/local/MATLAB/R2019b/sys/java/jre/glnxa64/jre/lib/amd64/server')
tic
!echo $LD_LIBRARY_PATH
!echo $XCL_EMULATION_MODE
% !ldd ./host
% !./host
myFunc_codegen = fir_filter_mex(dataIn,b);

toc
%
% % figure(4)
% % freqz(b,a,'whole')
% figure
% freqz(dataIn,myFunc_codegen,'whole')
% title('codegen');

min(myFunc==myFunc_codegen,[],'all')

% code = host()