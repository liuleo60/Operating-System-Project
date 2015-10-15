#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "../headers/rdtsc.h"
#include "../headers/utils.h"
#define SIZE_NUM 18
#define STRIDE_NUM 20
#define N_ITERS 1000000

int main () {
    // sizes are in byte. log_size = log(size)/log(2)
    int log_size_list[SIZE_NUM];
    int i = 0;
    for (; i < SIZE_NUM; ++i) {
        log_size_list[i] = 11 + i;
    }

    int log_stride_list[STRIDE_NUM];
    i = 0;
    for (; i < STRIDE_NUM; ++i) {
        log_stride_list[i] = 3 + i;
    }

    i = 0;
    float time_mat[STRIDE_NUM][SIZE_NUM];
    for (; i < STRIDE_NUM; ++i) {
        printf("%d\n", i);
        long stride = (long)pow(2, log_stride_list[i]);
        long array_stride = stride / sizeof(long);
        int j = 0;
        for (; j < SIZE_NUM; ++j) {
            long size = (long)pow(2, log_size_list[j]);
            long array_size = size / sizeof(long);

            long* block = (long*) calloc(sizeof(long), array_size);
            printf("array_size = %ld \n", array_size);
            printf("array_stride = %ld \n", array_stride);
            //assert (array_size % array_stride == 0 || array_stride % array_size == 0);

            int k = 0;
            for (; k < array_size; k += array_stride) {
                block[k] = (long)(&block[(k + array_stride) % array_size]);
                //printf("%d : %ld\n", k, block[k]);
            }

            //flush cache?

            long* p = block;

            k = 0;
            ticks time_1 = 0, time_2 = 0;
            time_1 = getTime();
            for (; k < N_ITERS; ++k) {
                p = (long*)*p;
            }
            time_2 = getTime();
            time_mat[i][j] = (float)((time_2 - time_1) / (N_ITERS * 1.0));

            free(block);
        }
    }
    writeXYZ("memory_size.txt", STRIDE_NUM, SIZE_NUM, log_stride_list, log_size_list, time_mat);

    return 0;
}
