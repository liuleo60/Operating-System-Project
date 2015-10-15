// measure the overhead of rdtsc iteratively with a loop.// compile: O0. (O3 will optimize the loop)

#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include "../headers/utils.h"


int main() {
    ticks vec[ITERS];
    ticks time_1 = 0, time_2 = 0;
    unsigned int hi = 0, lo = 0;
    int i = 0;
    for (; i < ITERS; ++i) {
        asm("cpuid");
        // getTime 1
        asm volatile("rdtsc" : "=a" (lo), "=d" (hi));
        time_1 = ((ticks)hi << 32) | (ticks)lo;
        // getTime 2
        asm volatile("rdtsc" : "=a" (lo), "=d" (hi));
        time_2 = ((ticks)hi << 32) | (ticks)lo;

        vec[i] = time_2 - time_1;
    }

    writeLLUArray("reading_time.txt", vec, ITERS);
    return 0;
}
