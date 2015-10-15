#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <pthread.h>
#include "../headers/rdtsc.h"
#include "../headers/utils.h"

void * foo (void * arg) {
    ;
}

int main() {

    setpriority(PRIO_PROCESS, 0, -20);
    ticks vec[ITERS];
    ticks time_1 = 0, time_2 = 0;
    
    int i = 0;
    pthread_t pt;
    for ( ; i<ITERS; i++) {
    	time_1 = getTime();
    	pthread_create(&pt, NULL, foo, NULL);
        time_2 = getTime();
    	vec[i] = time_2 - time_1;
    }

    writeLLUArray("kthread_creation_overhead.txt", vec, ITERS);
    return 0;
}