#!/usr/bin/env sh

######################################################################
# @author      : kistenklaus (karlsasssie@gmail.com)
# @file        : run
# @created     : Sonntag Jun 23, 2024 14:23:17 CEST
#
# @description : 
######################################################################

canzero gen input_board src/canzero
cmake -Bbuild
cmake --build build -j8
alacritty -e ./build/input_board&


