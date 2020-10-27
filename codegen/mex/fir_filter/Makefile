.PHONY: help

help::
	@echo  " Makefile Usage:"
	@echo  ""
	@echo  "  make build TARGET=<sw_emu/hw_emu/hw> STEP=<baseline_fpga/localbuf/multicu/multiddr>"
	@echo  "  Command to generate the design for specified target and step"
	@echo  ""
	@echo  "  make run TARGET=<sw_emu/hw_emu/hw> STEP=<baseline_fpga/localbuf/multicu/multiddr> "
	@echo  "  Command to generate,run and verifiy the design for specified target and step"
	@echo  ""
	@echo  "  make clean TARGET=<sw_emu/hw_emu/hw> STEP=<baseline_fpga/localbuf/multicu/multiddr>"
	@echo  "  Command to remove the generated files for specified target and step."
	@echo  ""
	@echo  "  make view_report TARGET=<sw_emu/hw_emu/hw> STEP=<baseline_fpga/localbuf/multicu/multiddr>"
	@echo  "  Command to view profile summary and timeline trace report in Vitis Analyzer"
	@echo  ""


# platform selection
# Several supported platforms are liste here. You may choose the one you want and comment out the others
# Or you can add other platfom and set PLATFORM variable to it
#PLATFORM := xilinx_vcu1525_dynamic_5_1
PLATFORM := xilinx_u250_xdma_201830_2
#$PLATFORM := xilinx_u200_qdma_201910_1

# TARGET can be set as:
# sw_emu: software emulation
# hw_emu: hardware Emulation
# hw: hardware run
TARGET := sw_emu

# Below are the names for host executable and xclbin.
# Please keep it unchanged.
HOST_EXE := host
XO_NAME := runOnfpga_$(TARGET)
XCLBIN := runOnfpga_$(TARGET).xclbin



# Source file repository selection
# Step1           - baseline  (The baseline version design)
# Step2           - localbuf  (Use local buffer to store the data for processing)
# Step3           - dataflow  (Use dataflow to send the data in streams)
# Step4           - multicu (Adopt different optimizations on host code side, such as out-of-order command queue and multiple compute units)
# Step5           - multiddr (Use multiple ddr banks by modifying host code)

# BUILD_DIR are used for the generated files, including .exe, .xclbin, and the reports/logs. BUILD_DIR selection should be matched to SRC_REPO for better structure.
PROJECT_DIR := .

# Below listed the different steps of the design.
# The descriptions are in 'HowToRunTutorial.md'.
# YOu can change the STEP here or specify it when launching makefile.

STEP  := baseline_fpga


SRC_REPO := $(PROJECT_DIR)


BUILD_DIR := $(PROJECT_DIR)/build/


# Kernel Parameters

NUM_DOCS:= 100

# Host Application files repository

HOST_SRC_CPP := $(SRC_REPO)/interface/_coder_fir_filter_api.c
HOST_SRC_CPP += $(SRC_REPO)/interface/_coder_fir_filter_info.c
HOST_SRC_CPP += $(SRC_REPO)/interface/_coder_fir_filter_mex.c
HOST_SRC_CPP += $(SRC_REPO)/fir_filter_data.c
HOST_SRC_CPP += $(SRC_REPO)/fir_filter_initialize.c
HOST_SRC_CPP += $(SRC_REPO)/fir_filter_terminate.c

HOST_SRC_H := $(SRC_REPO)/interface/_coder_fir_filter_api.h


HOST_SRC_H += $(SRC_REPO)/fir_filter_types.h
HOST_SRC_H += $(SRC_REPO)/fir_filter_data.h
HOST_SRC_H += $(SRC_REPO)/fir_filter_initialize.h
HOST_SRC_H += $(SRC_REPO)/fir_filter_terminate.h


HOST_SRC_H += $(SRC_REPO)/interface/_coder_fir_filter_info.h
HOST_SRC_H += $(SRC_REPO)/interface/_coder_fir_filter_mex.h

HOST_SRC_H += $(SRC_REPO)/interface/

# Kernel Source Files repository

KERNEL_SRC_CPP := $(SRC_REPO)/rt_nonfinite.c
#KERNEL_SRC_CPP := $(SRC_REPO)/fir_filter_data.c   
#KERNEL_SRC_CPP := $(SRC_REPO)/fir_filter_initialize.c  
#KERNEL_SRC_CPP := $(SRC_REPO)/fir_filter_terminate.c   
KERNEL_SRC_CPP := $(SRC_REPO)/fir_filter.c   

KERNEL_SRC_H += $(SRC_REPO)/coder_array.h 
KERNEL_SRC_H += $(SRC_REPO)/rtwtypes.h
KERNEL_SRC_H += $(SRC_REPO)/fir_filter.h


KERNEL_SRC_H_DIR := $(SRC_REPO)


#Host Compiler Global Settings and Include Libraries

#MATLAB
root = .
builddir = $(root)/build/
matlabdir =/usr/local/MATLAB/R2019b
startdir = ../../

#CXXFLAGS :=
CXXFLAGS += -D__USE_XOPEN2K8
CXXFLAGS += -D__USE_XOPEN2K8
CXXFLAGS += -I$(XILINX_XRT)/include/
CXXFLAGS += -I$(XILINX_VIVADO)/include/
CXXFLAGS += -I$(SRC_REPO)
CXXFLAGS += -O0 -g -Wall -fmessage-length=0 -std=c++14
CXXFLAGS += -fexceptions -fPIC -fno-omit-frame-pointer
CXXFLAGS += -D_GNU_SOURCE -DMATLAB_MEX_FILE -DNDEBUG
CXXFLAGS += -I "$startdir" -I "$(SRC_REPO)/interface" -I "$(matlabdir)/extern/include"
CXXFLAGS += -I "." -DMODEL=fir_filter_mex -DMW_NEEDS_VERSION_H



CXXLDFLAGS := -L$(XILINX_XRT)/lib/
CXXLDFLAGS += -lxilinxopencl -lpthread -lrt
CXXLDFLAGS += -pthread -Wl,--no-undefined  -shared
CXXLDFLAGS += -Wl,--as-needed -Wl,-rpath-link,$(matlabdir)/bin/glnxa64
CXXLDFLAGS += -L"$(matlabdir)/bin/glnxa64" -Wl,-rpath-link,$(matlabdir)/extern/bin/glnxa64
CXXLDFLAGS += -L"$(matlabdir)/extern/bin/glnxa64" -lMatlabDataArray -lmx -lmex -lmat -lm
CXXLDFLAGS += -lstdc++  -o fir_filter_mex.mexa64 -lemlrt -lcovrt -lut -lmwmathutil


## Kernel Compiler and Linker Flags

VITISFLAGS := -g -t $(TARGET)
VITISFLAGS += --platform $(PLATFORM) -R 1
VITISFLAGS += -I$(KERNEL_SRC_H_DIR)
VITISFLAGS += --temp_dir $(BUILD_DIR)
VITISFLAGS += --log_dir $(BUILD_DIR)
VITISFLAGS += --profile_kernel data:all:all:all:all

## Host Executable File Generation

$(BUILD_DIR)/$(HOST_EXE): $(HOST_SRC_CPP) $(HOST_SRC_H)
#	cp $(PROJECT_DIR)/interface/_coder_*.h ./
	mkdir -p $(BUILD_DIR)
	xcpp $(CXXFLAGS) $(HOST_SRC_CPP) $(CXXLDFLAGS) -o $@
#	rm $(PROJECT_DIR)/_coder_*.h

## Kernel XO and Xclbin File Generation

$(BUILD_DIR)/$(XO_NAME).xo: $(KERNEL_SRC_CPP) $(KERNEL_SRC_H)
	mkdir -p $(BUILD_DIR)
	v++ $(VITISFLAGS) -c -k runOnfpga $(KERNEL_SRC_CPP) -o $@

$(BUILD_DIR)/$(XCLBIN): $(BUILD_DIR)/$(XO_NAME).xo
	mkdir -p $(BUILD_DIR)
	cp xrt.ini $(BUILD_DIR);
	v++ $(VITISFLAGS) -l -o $@ $(BUILD_DIR)/$(XO_NAME).xo

## Emulation Files Generation

EMCONFIG_FILE = emconfig.json

$(BUILD_DIR)/$(EMCONFIG_FILE):
	emconfigutil --nd 1  --platform $(PLATFORM) --od $(BUILD_DIR)


#
# primary build targets
#

.PHONY: all clean

## build the design without running host application

build: $(BUILD_DIR)/$(HOST_EXE) $(BUILD_DIR)/$(XO_NAME).xo $(BUILD_DIR)/$(XCLBIN) $(BUILD_DIR)/$(EMCONFIG_FILE)


## build the design and then run host application
## run with 100 documents for hardware emulation and 100000 for hardware

run: build
	
ifeq ($(TARGET), hw)
	cd $(BUILD_DIR) && unset XCL_EMULATION_MODE; ./$(HOST_EXE) ./$(XCLBIN) $(NUM_DOCS);
else
	cd $(BUILD_DIR) && XCL_EMULATION_MODE=$(TARGET) ./$(HOST_EXE) ./$(XCLBIN) $(NUM_DOCS) ;
endif
## generate profile summary and timeline trace reports
## convert it to html, xprf and wdb formats after generation


## view profile summary and timeline trace report in vitis analyzer

view_report:
	cd $(BUILD_DIR) && vitis_analyzer -open profile_summary.csv timeline_trace.csv &


## Clean generated files

clean:
	rm -rf $(BUILD_DIR)/$(XCLBIN) $(BUILD_DIR)/$(HOST_EXE) $(BUILD_DIR)/$(EMCONFIG_FILE) $(BUILD_DIR)/$(XO_NAME).xo $(BUILD_DIR)/*.ltx $(BUILD_DIR)/*_$(TARGET).log $(BUILD_DIR)/v++_*_$(TARGET)_* $(BUILD_DIR)/_x* $(BUILD_DIR)/*.info $(BUILD_DIR)/runOnfpga_$(TARGET)* $(BUILD_DIR)/link $(BUILD_DIR)/reports/runOnfpga_$(TARGET) ./*log ./*summary ./*csv

