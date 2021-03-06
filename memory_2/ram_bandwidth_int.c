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
					DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
					DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
					DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
					DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
					DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
					DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
					DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
					DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
					DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
					DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
					DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
					DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
					DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
					DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
					DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
					DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
					DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
					DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
					DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
					DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
					DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
					DOIT(123) DOIT(124) DOIT(125) DOIT(126) array[127];

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
	writeLLUArray("ram_bandwidth_stride_int_read.txt", vec, ITERS);

	for (j = 0 ; j < ITERS; j++) {
		int * origin = array;
		for (i = 0; i < arraySize; i+=128)
		{
			time_1 = getTime();

			#define	DOIT(i)	array[i]=
					DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
					DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
					DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
					DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
					DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
					DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
					DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
					DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
					DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
					DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
					DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
					DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
					DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
					DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
					DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
					DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
					DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
					DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
					DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
					DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
					DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
					DOIT(123) DOIT(124) DOIT(125) DOIT(126) DOIT(127) 1;

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
	writeLLUArray("ram_bandwidth_stride_int_write.txt", vec, ITERS);
	return 0;
}