#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "../headers/rdtsc.h"
#include "../headers/utils.h"

int main() {
    ticks time_1 = 0, time_2 = 0, temp = 0;
    ticks vec[ITERS];

    int fd[2];
	if ( pipe(fd) ) {
		fprintf(stderr, "Cannot create a new pipe.\n");
	}

	int i, j;
	for (i = 0; i < ITERS; i++) {
		time_1 = getTime();
		write(fd[1], &temp, sizeof(temp));
		read(fd[0], &temp, sizeof(temp));
		time_2 = getTime();
		vec[i] = (time_2 - time_1);
	}

	writeLLUArray("pipe_overhead.txt", vec, ITERS);
    return 0;

}
