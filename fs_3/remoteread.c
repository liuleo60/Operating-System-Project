#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "../headers/rdtsc.h"
#include "../headers/utils.h"

#define BLKSIZE 512
int main(int argc, char** argv)
{
    int fd;
    int random = 0;
    int n;
    ticks total = 0, t1 = 0, t2 = 0;
    unsigned long long file_size = 0;

    srand(time(0));

    fd = open("/mnt/nfs/sda3", O_RDONLY | O_DIRECT);
    if (fd < 0) {
       fprintf(stderr, "Failed to open file.\n");
       exit(0);
    }

    if (argc < 3) {
        printf("Usage: random/sequential \n");
        exit(0);
    }

    file_size = atoi(argv[1]);
    random = atoi(argv[2]);

    unsigned char* block;
    block = memalign(BLKSIZE, BLKSIZE);
    
    
    t1 = getTime();
    while (1)
    {
    	if (random) {
    	    lseek(fd, (rand() % (file_size * 1024 * 1024)) / 512 * 512, 0); // Make sure to align
    	}
    	n = read(fd, block, BLKSIZE);
    	total += n;
    	//if ((total / 1024 / 1024) > file_size)
    	if ((total / 1024 / 1024) > 20) {
    	    
    	    break;
    	}
    	printf("%llu\r", total / 1024 / 1024);
    }
    t2 = getTime();
    
    printf("\n");
    //printf("latency=usec/MB,%llu\n", interval / file_size);
    if (random) {
	    printf("random:\n");
    }
    else {
	    printf("seq:\n");
    }


    printf("latency=usec/MB,%llu\n", t2-t1 / 20);


    close(fd);
    return 0;
}
