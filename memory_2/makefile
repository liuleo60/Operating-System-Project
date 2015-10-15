all: ram_bandwidth_long ram_bandwidth_int ram_bandwidth_int_stride

ram_bandwidth_long: ram_bandwidth_long.o
	gcc -o ram_bandwidth_long ram_bandwidth_long.o

ram_bandwidth_long.o: ram_bandwidth_long.c
	gcc -c -Wall ram_bandwidth_long.c

ram_bandwidth_int: ram_bandwidth_int.o
	gcc -o ram_bandwidth_int ram_bandwidth_int.o

ram_bandwidth_int.o: ram_bandwidth_int.c
	gcc -c -Wall ram_bandwidth_int.c

ram_bandwidth_int_stride: ram_bandwidth_int_stride.o
	gcc -o ram_bandwidth_int_stride ram_bandwidth_int_stride.o

ram_bandwidth_int_stride.o: ram_bandwidth_int_stride.c
	gcc -c -Wall ram_bandwidth_int_stride.c

clean:
	rm ram_bandwidth_long ram_bandwidth_int ram_bandwidth_int_stride *.o *.txt
