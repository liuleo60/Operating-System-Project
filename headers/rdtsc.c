#include <sys/time.h>
#include <time.h>
#include <stdio.h>
typedef unsigned long long ticks;

static inline ticks getTime() {
    unsigned int hi, lo;
    asm volatile("rdtsc" : "=a" (lo), "=d" (hi));
    return ((ticks)hi << 32) | (ticks)lo;
}

int main() {
    ticks time_1 = 0, time_2 = 0;
    asm("cpuid");
    time_1 = getTime();
    time_2 = getTime();
    printf("%llu\n", time_2 - time_1);
    return 0;
}
