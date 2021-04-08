############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project good_coding_style
set_top top
add_files good_coding_style/src/good-stream.cpp
add_files good_coding_style/src/good-stream.hpp
add_files -tb good_coding_style/src/good-test.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution2_axis"
set_part {xc7z020-clg400-1}
create_clock -period 5 -name default
source "./good_coding_style/ccs/solution2_axis/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all -tool xsim
export_design -rtl verilog -format ip_catalog
