#!/bin/sh

gcc -c syscall_overhead.c
gcc -o syscall_overhead syscall_overhead.o

rm -f syscall_overhead.txt

i=1
while [ $i -le 1000 ]
do
	./syscall_overhead>>syscall_overhead.txt
	i=$(( $i + 1 )) 
done 
