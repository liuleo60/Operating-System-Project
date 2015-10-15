#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include "../headers/rdtsc.h"
#include "../headers/utils.h"

int fd_c2p[2];
int fd_p2c[2];

void * thread_entry() {
	int i;
	for (i = 0; i < ITERS; ++i)
	{
		ticks time_1 = getTime();
		write(fd_c2p[1], &time_1, sizeof(time_1));
		read(fd_p2c[0], &time_1, sizeof(time_1));
		//ticks time_2 = getTime();
	}
	return NULL;
}

int main() {
	ticks vec[ITERS];
	pthread_t thread;

	if (pipe(fd_c2p)) {
		fprintf(stderr, "Cannot create a new pipe.\n");
	}
	if (pipe(fd_p2c)) {
		fprintf(stderr, "Cannot create a new pipe.\n");
	}

	pthread_create(&thread, NULL, thread_entry, NULL);

	int i;
	for (i = 0; i < ITERS; i++) {
		ticks time_1 = 0;
		read(fd_c2p[0], &time_1, sizeof(time_1));
		ticks time_2 = getTime();
		//fprintf(stdout, "son_switch_to_parent %d\n", delta);
		vec[i] = time_2-time_1;
		time_1 = getTime();
		write(fd_p2c[1], &time_1, sizeof(time_1));
	}
	close(fd_c2p[0]);
	close(fd_c2p[1]);
	close(fd_p2c[0]);
	close(fd_p2c[1]);
	pthread_join(thread, NULL);

	writeLLUArray("pipe_kthread_switch_overhead.txt", vec, ITERS);

	return 0;
}