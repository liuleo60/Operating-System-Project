#include <sys/time.h>
#include <time.h>
#include <stdio.h>

typedef unsigned long long ticks;

ticks getTime() {
    unsigned int hi, lo;
    asm volatile("rdtsc" : "=a" (lo), "=d" (hi));
    return ((ticks)hi << 32) | (ticks)lo;
}
