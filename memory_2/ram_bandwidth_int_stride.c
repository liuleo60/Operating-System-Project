#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../headers/rdtsc.h"
#include "../headers/utils.h"

#define ONE_KB 1024

int main()
{
	ticks time_1 = 0, time_2 = 0, time_sum = 0;
	ticks vec[ITERS];

	// Create a 64MB array
	unsigned long arraySize = 16*ONE_KB*ONE_KB;
	int * array = malloc(arraySize * sizeof(int));

	unsigned long i = 0, sum = 0;
	for (i = 0; i < arraySize; ++i)
	{
		array[i] = i;
	}

	// stride is 1
	int j = 0;
	for (j = 0 ; j < ITERS; j++) {
		int * origin = array;
		for (i = 0; i < arraySize; i+=128)
		{
			time_1 = getTime();
			sum += 
			#define	DOIT(i)	array[i]+
				DOIT(0) DOIT(4) DOIT(8) DOIT(12) DOIT(16) DOIT(20) DOIT(24)
				DOIT(28) DOIT(32) DOIT(36) DOIT(40) DOIT(44) DOIT(48) DOIT(52)
				DOIT(56) DOIT(60) DOIT(64) DOIT(68) DOIT(72) DOIT(76)
				DOIT(80) DOIT(84) DOIT(88) DOIT(92) DOIT(96) DOIT(100)
				DOIT(104) DOIT(108) DOIT(112) DOIT(116) DOIT(120) 
				array[124];

			time_2 = getTime();
			time_sum += time_2 - time_1;
			array += 128;
		}
		vec[j] = time_sum;
		time_sum = 0;
		array = origin;
		printf("%d %llu\n", j, vec[j]);
	}
	#undef	DOIT
	writeLLUArray("ram_bandwidth_stride_int_read_stride.txt", vec, ITERS);

	for (j = 0 ; j < ITERS; j++) {
		int * origin = array;
		for (i = 0; i < arraySize; i+=128)
		{
			time_1 = getTime();

			#define	DOIT(i)	array[i] = 1;
					DOIT(0) DOIT(4) DOIT(8) DOIT(12) DOIT(16) DOIT(20) DOIT(24)
					DOIT(28) DOIT(32) DOIT(36) DOIT(40) DOIT(44) DOIT(48) DOIT(52)
					DOIT(56) DOIT(60) DOIT(64) DOIT(68) DOIT(72) DOIT(76)
					DOIT(80) DOIT(84) DOIT(88) DOIT(92) DOIT(96) DOIT(100)
					DOIT(104) DOIT(108) DOIT(112) DOIT(116) DOIT(120) DOIT(124);

			time_2 = getTime();
			time_sum += time_2 - time_1;

			array += 128;
		}
		vec[j] = time_sum;
		time_sum = 0;
		array = origin;
		printf("%d %llu\n", j, vec[j]);
	}
	#undef	DOIT
	//time_2 = getTime();
	writeLLUArray("ram_bandwidth_stride_int_write_stride.txt", vec, ITERS);
	return 0;
}