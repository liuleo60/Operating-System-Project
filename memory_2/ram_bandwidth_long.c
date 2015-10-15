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
	unsigned long arraySize = 64*ONE_KB*ONE_KB;
	char * array = malloc(arraySize * sizeof(char));
	//char * array2 = malloc(arraySize * sizeof(char));

	unsigned long i = 0, sum = 0;
	for (i = 0; i < arraySize; ++i)
	{
		array[i] = i % ONE_KB;
	}

	// stride long
	int j = 0;
	for (j = 0 ; j < ITERS; j++) {
		char * origin = array;
		for (i = 0; i < arraySize; i+=1024)
		{
			time_1 = getTime();
			sum += ((long *)array)[0];sum += ((long *)array)[1];sum += ((long *)array)[2];sum += ((long *)array)[3];sum += ((long *)array)[4];sum += ((long *)array)[5];sum += ((long *)array)[6];sum += ((long *)array)[7];
			sum += ((long *)array)[8];sum += ((long *)array)[9];sum += ((long *)array)[10];sum += ((long *)array)[11];sum += ((long *)array)[12];sum += ((long *)array)[13];sum += ((long *)array)[14];sum += ((long *)array)[15];
			sum += ((long *)array)[16];sum += ((long *)array)[17];sum += ((long *)array)[18];sum += ((long *)array)[19];sum += ((long *)array)[20];sum += ((long *)array)[21];sum += ((long *)array)[22];sum += ((long *)array)[23];
			sum += ((long *)array)[24];sum += ((long *)array)[25];sum += ((long *)array)[26];sum += ((long *)array)[27];sum += ((long *)array)[28];sum += ((long *)array)[29];sum += ((long *)array)[30];sum += ((long *)array)[31];
			sum += ((long *)array)[32];sum += ((long *)array)[33];sum += ((long *)array)[34];sum += ((long *)array)[35];sum += ((long *)array)[36];sum += ((long *)array)[37];sum += ((long *)array)[38];sum += ((long *)array)[39];
			sum += ((long *)array)[40];sum += ((long *)array)[41];sum += ((long *)array)[42];sum += ((long *)array)[43];sum += ((long *)array)[44];sum += ((long *)array)[45];sum += ((long *)array)[46];sum += ((long *)array)[47];
			sum += ((long *)array)[48];sum += ((long *)array)[49];sum += ((long *)array)[50];sum += ((long *)array)[51];sum += ((long *)array)[52];sum += ((long *)array)[53];sum += ((long *)array)[54];sum += ((long *)array)[55];
			sum += ((long *)array)[56];sum += ((long *)array)[57];sum += ((long *)array)[58];sum += ((long *)array)[59];sum += ((long *)array)[60];sum += ((long *)array)[61];sum += ((long *)array)[62];sum += ((long *)array)[63];
			sum += ((long *)array)[64];sum += ((long *)array)[65];sum += ((long *)array)[66];sum += ((long *)array)[67];sum += ((long *)array)[68];sum += ((long *)array)[69];sum += ((long *)array)[70];sum += ((long *)array)[71];
			sum += ((long *)array)[72];sum += ((long *)array)[73];sum += ((long *)array)[74];sum += ((long *)array)[75];sum += ((long *)array)[76];sum += ((long *)array)[77];sum += ((long *)array)[78];sum += ((long *)array)[79];
			sum += ((long *)array)[80];sum += ((long *)array)[81];sum += ((long *)array)[82];sum += ((long *)array)[83];sum += ((long *)array)[84];sum += ((long *)array)[85];sum += ((long *)array)[86];sum += ((long *)array)[87];
			sum += ((long *)array)[88];sum += ((long *)array)[89];sum += ((long *)array)[90];sum += ((long *)array)[91];sum += ((long *)array)[92];sum += ((long *)array)[93];sum += ((long *)array)[94];sum += ((long *)array)[95];
			sum += ((long *)array)[96];sum += ((long *)array)[97];sum += ((long *)array)[98];sum += ((long *)array)[99];sum += ((long *)array)[100];sum += ((long *)array)[101];sum += ((long *)array)[102];sum += ((long *)array)[103];
			sum += ((long *)array)[104];sum += ((long *)array)[105];sum += ((long *)array)[106];sum += ((long *)array)[107];sum += ((long *)array)[108];sum += ((long *)array)[109];sum += ((long *)array)[110];sum += ((long *)array)[111];
			sum += ((long *)array)[112];sum += ((long *)array)[113];sum += ((long *)array)[114];sum += ((long *)array)[115];sum += ((long *)array)[116];sum += ((long *)array)[117];sum += ((long *)array)[118];sum += ((long *)array)[119];
			sum += ((long *)array)[120];sum += ((long *)array)[121];sum += ((long *)array)[122];sum += ((long *)array)[123];sum += ((long *)array)[124];sum += ((long *)array)[125];sum += ((long *)array)[126];sum += ((long *)array)[127];
			
			time_2 = getTime();
			time_sum += time_2 - time_1;
			array += 1024;
		}
		vec[j] = time_sum;
		time_sum = 0;
		array = origin;
		printf("%d %llu\n", j, vec[j]);
	}
	//time_2 = getTime();
	free(array);
	writeLLUArray("ram_bandwidth_stride_long.txt", vec, ITERS);

	printf("start writing measurement\n");
	for (j = 0 ; j < ITERS; j++) {
		char * array2 = malloc(arraySize * sizeof(char));
		char * origin = array2;
		for (i = 0; i < arraySize; i+=1024)
		{
			time_1 = getTime();
			((long *)array2)[0] = 1; ((long *)array2)[1] = 1; ((long *)array2)[2] = 1; ((long *)array2)[3] = 1; ((long *)array2)[4] = 1; ((long *)array2)[5] = 1; ((long *)array2)[6] = 1; ((long *)array2)[7] = 1; 
			((long *)array2)[8] = 1; ((long *)array2)[9] = 1; ((long *)array2)[10] = 1; ((long *)array2)[11] = 1; ((long *)array2)[12] = 1; ((long *)array2)[13] = 1; ((long *)array2)[14] = 1; ((long *)array2)[15] = 1; 
			((long *)array2)[16] = 1; ((long *)array2)[17] = 1; ((long *)array2)[18] = 1; ((long *)array2)[19] = 1; ((long *)array2)[20] = 1; ((long *)array2)[21] = 1; ((long *)array2)[22] = 1; ((long *)array2)[23] = 1; 
			((long *)array2)[24] = 1; ((long *)array2)[25] = 1; ((long *)array2)[26] = 1; ((long *)array2)[27] = 1; ((long *)array2)[28] = 1; ((long *)array2)[29] = 1; ((long *)array2)[30] = 1; ((long *)array2)[31] = 1; 
			((long *)array2)[32] = 1; ((long *)array2)[33] = 1; ((long *)array2)[34] = 1; ((long *)array2)[35] = 1; ((long *)array2)[36] = 1; ((long *)array2)[37] = 1; ((long *)array2)[38] = 1; ((long *)array2)[39] = 1; 
			((long *)array2)[40] = 1; ((long *)array2)[41] = 1; ((long *)array2)[42] = 1; ((long *)array2)[43] = 1; ((long *)array2)[44] = 1; ((long *)array2)[45] = 1; ((long *)array2)[46] = 1; ((long *)array2)[47] = 1; 
			((long *)array2)[48] = 1; ((long *)array2)[49] = 1; ((long *)array2)[50] = 1; ((long *)array2)[51] = 1; ((long *)array2)[52] = 1; ((long *)array2)[53] = 1; ((long *)array2)[54] = 1; ((long *)array2)[55] = 1; 
			((long *)array2)[56] = 1; ((long *)array2)[57] = 1; ((long *)array2)[58] = 1; ((long *)array2)[59] = 1; ((long *)array2)[60] = 1; ((long *)array2)[61] = 1; ((long *)array2)[62] = 1; ((long *)array2)[63] = 1; 
			((long *)array2)[64] = 1; ((long *)array2)[65] = 1; ((long *)array2)[66] = 1; ((long *)array2)[67] = 1; ((long *)array2)[68] = 1; ((long *)array2)[69] = 1; ((long *)array2)[70] = 1; ((long *)array2)[71] = 1; 
			((long *)array2)[72] = 1; ((long *)array2)[73] = 1; ((long *)array2)[74] = 1; ((long *)array2)[75] = 1; ((long *)array2)[76] = 1; ((long *)array2)[77] = 1; ((long *)array2)[78] = 1; ((long *)array2)[79] = 1; 
			((long *)array2)[80] = 1; ((long *)array2)[81] = 1; ((long *)array2)[82] = 1; ((long *)array2)[83] = 1; ((long *)array2)[84] = 1; ((long *)array2)[85] = 1; ((long *)array2)[86] = 1; ((long *)array2)[87] = 1; 
			((long *)array2)[88] = 1; ((long *)array2)[89] = 1; ((long *)array2)[90] = 1; ((long *)array2)[91] = 1; ((long *)array2)[92] = 1; ((long *)array2)[93] = 1; ((long *)array2)[94] = 1; ((long *)array2)[95] = 1; 
			((long *)array2)[96] = 1; ((long *)array2)[97] = 1; ((long *)array2)[98] = 1; ((long *)array2)[99] = 1; ((long *)array2)[100] = 1; ((long *)array2)[101] = 1; ((long *)array2)[102] = 1; ((long *)array2)[103] = 1; 
			((long *)array2)[104] = 1; ((long *)array2)[105] = 1; ((long *)array2)[106] = 1; ((long *)array2)[107] = 1; ((long *)array2)[108] = 1; ((long *)array2)[109] = 1; ((long *)array2)[110] = 1; ((long *)array2)[111] = 1; 
			((long *)array2)[112] = 1; ((long *)array2)[113] = 1; ((long *)array2)[114] = 1; ((long *)array2)[115] = 1; ((long *)array2)[116] = 1; ((long *)array2)[117] = 1; ((long *)array2)[118] = 1; ((long *)array2)[119] = 1; 
			((long *)array2)[120] = 1; ((long *)array2)[121] = 1; ((long *)array2)[122] = 1; ((long *)array2)[123] = 1; ((long *)array2)[124] = 1; ((long *)array2)[125] = 1; ((long *)array2)[126] = 1; ((long *)array2)[127] = 1; 
			time_2 = getTime();
			
			time_sum += time_2 - time_1;
			
			array2 += 1024;
		}
		vec[j] = time_sum;
		time_sum = 0;
		free(origin);
		printf("%d %llu\n", j, vec[j]);
	}
	
	writeLLUArray("ram_bandwidth_stride_long_write.txt", vec, ITERS);
	return 0;
}