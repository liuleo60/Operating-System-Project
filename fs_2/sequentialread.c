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
    int n = 0;

    unsigned char* block; //set the block
    block = memalign(BLKSIZE, BLKSIZE); // set the block b memaligh

    int fd = open("/dev/sda3", O_RDONLY | O_DIRECT);

    unsigned long long file_size = atoi(argv[1]);//set the file size
    unsigned long long total = 0;//

    ticks t1, t2;
    t1 = getTime();
    while (1)
    {
	n = read(fd, block, BLKSIZE);//read sequentially
	total += n;
	if ((total / 1024 / 1024) > 32)
	{
	    break;
	}
    }
    t2 = getTime();
    printf("the cycles are %llu", t2-t1);



    close(fd);
    return 0;
}
