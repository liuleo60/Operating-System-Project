#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include "../headers/rdtsc.h"
#include "../headers/utils.h"


int main() {

    setpriority(PRIO_PROCESS, 0, -20);
    ticks time_1 = 0, time_2 = 0;
    ticks vec[ITERS];
    
    int i = 0;
    pid_t pid;
    for ( ; i<ITERS; i++) {
    	time_1 = getTime();
    	if ((pid = fork()) == 0) {  // child
    		exit(0);
    	}
        time_2 = getTime();
        //printf("%llu\n", time_2-time_1);
        vec[i] = time_2 - time_1;
    	waitpid(pid, NULL, 0);
    }

    writeLLUArray("process_creation_overhead.txt", vec, ITERS);
    return 0;
}