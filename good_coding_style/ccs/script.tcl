############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project good_coding_style
set_top top
add_files good_coding_style/src/good-stream.cpp
add_files good_coding_style/src/good-stream.hpp
add_files -tb good_coding_style/src/good-test.cpp
open_solution "solution1"
set_part {xc7z020clg400-1}
create_clock -period 5 -name default
#source "./good_coding_style/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all -tool xsim
export_design -rtl verilog -format ip_catalog
