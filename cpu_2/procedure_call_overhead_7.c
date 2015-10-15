#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include "../headers/utils.h"

void func (int j_1, int j_2, int j_3, int j_4, int j_5, int j_6, int j_7) {
}

int main() {
    ticks vec[ITERS];
    ticks time_1 = 0, time_2 = 0;
    unsigned int hi = 0, lo = 0;

    int j = 0;
    for (; j < ITERS; ++j) {
        asm("cpuid");
        asm volatile("rdtsc" : "=a" (lo), "=d" (hi));
        time_1 = ((ticks)hi << 32) | (ticks)lo;
        func(j, j, j, j, j, j, j);
        asm volatile("rdtsc" : "=a" (lo), "=d" (hi));
        time_2 = ((ticks)hi << 32) | (ticks)lo;
        vec[j] = time_2 - time_1;
    }
    writeLLUArray("procedure_call_overhead_7.txt", vec, ITERS);
    return 0;
}
