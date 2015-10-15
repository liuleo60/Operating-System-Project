#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "math.h"
#include <stdlib.h>
#include "../headers/rdtsc.h"
#include "../headers/utils.h"
#define BLKSIZE 4096
int main(int argc, char** argv)
{


    unsigned char* block = memalign(BLKSIZE, BLKSIZE); // set the block

    unsigned long long total = 0; // total size read
    unsigned long long file_size = 0; // filesize
    file_size = atoi(argv[1]); // assign filesize

    pid_t pid;
    int i;

    int number;

    number = atoi(argv[2]);
    pid_t child[number];
    int n, fd;
    ticks t1, t2;
    for (i = 0; i < number; i++)
    {
	pid = fork();
	if (pid)
	{
	    continue;
	}
	else
	{
	    fd = open("/dev/sda3", O_RDONLY | O_DIRECT);
	    total = 0;
	    t1 = getTime();
	    while (1)
	    {
		n = read(fd, block, BLKSIZE); // read

		total += n;
		if ((total / 1024 / 1024) > 32)
		{
		    break;
		}
	    }
	    t2 = getTime();
	    printf("%llu",t2-t1);
	    return 0;
	}
    }
    for (i = 0; i < number; i++)
    {
	waitpid(child[i]);
    }
    close(fd); // close he file

    return 0;
}
