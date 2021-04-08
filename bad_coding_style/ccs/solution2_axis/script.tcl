############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project bad_coding_style
set_top top
add_files bad_coding_style/src/bad-stream.cpp
add_files bad_coding_style/src/bad-stream.hpp
add_files -tb bad_coding_style/src/bad-test.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution2_axis" -flow_target vivado
set_part {xc7z020-clg400-1}
create_clock -period 5 -name default
source "./bad_coding_style/ccs/solution2_axis/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all -tool xsim
export_design -rtl verilog -format ip_catalog
