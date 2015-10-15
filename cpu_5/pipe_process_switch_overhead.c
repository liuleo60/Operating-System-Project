#include <stdlib.h>
#include <stdio.h>
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

	int fd_c2p[2];
	int fd_p2c[2];
	if ( pipe(fd_c2p) ) {
		fprintf(stderr, "Cannot create a new pipe.\n");
	}
	if (pipe(fd_p2c)) {
		fprintf(stderr, "Cannot create a new pipe.\n");
	}

	pid_t pid = fork();
	if ( pid < 0 ) {
		fprintf(stderr, "Cannot spawn a new child process.\n");	
	}

	if ( pid == 0 ) {  // Child
		close(fd_c2p[0]);
		close(fd_p2c[1]);

		for (int i = 0; i < ITERS; ++i) {
			time_1 = getTime();
			write(fd_c2p[1], &time_1, sizeof(time_1));
			read(fd_p2c[0], &time_1, sizeof(time_1));
			//time_2 = getTime();
		}
		exit(0);
	}

	close(fd_c2p[1]);
	close(fd_p2c[0]);

	int i;
	for (i = 0; i < ITERS; ++i) {
		read(fd_c2p[0], &time_1, sizeof(time_1));
		time_2 = getTime();
		vec[i] = time_2-time_1;
		//printf("%llu\n", time_2-time_1);
		time_1 = getTime();
		write(fd_p2c[1], &time_1, sizeof(time_1));
	}
	
	//vec[i] = time_2-time_1;

	writeLLUArray("pipe_process_switch_overhead.txt", vec, ITERS);
	return 0;
}