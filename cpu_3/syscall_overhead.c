#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../headers/rdtsc.h"
#include "../headers/utils.h"

int main(int argc, char const *argv[])
{
    ticks time_1 = 0, time_2 = 0;
    pid_t pid;

    asm("cpuid");
    if ( (pid = fork()) == 0) {    
    	time_1 = getTime();
    	//pid = getppid();
    	pid = syscall(SYS_getppid);
    	time_2 = getTime();
    	printf("%llu\n", time_2 - time_1);
    }

    waitpid(pid, NULL, 0);

    return 0;
}
