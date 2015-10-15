#!/bin/sh

make clean

make

./pipe_overhead
./pipe_kthread_switch_overhead
./pipe_process_switch_overhead