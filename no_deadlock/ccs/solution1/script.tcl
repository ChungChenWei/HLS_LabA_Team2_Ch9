############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project has_deadlock
set_top top
add_files no_deadlock/src/has-deadlock.cpp
add_files no_deadlock/src/has-deadlock.hpp
add_files -tb no_deadlock/src/has-deadlock-test.cpp
open_solution "solution1" -flow_target vivado
set_part {xc7z020clg400-1}
create_clock -period 10 -name default
#source "./no_deadlock/ccs/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all -tool xsim
export_design -rtl verilog -format ip_catalog
