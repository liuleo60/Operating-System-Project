#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main()
{
    int fd; // readfile
    int size, chunksize; // define the size and chunksize
    chunksize = 256 * 1024 * 2; // chunk size is 256*1024*2
    size = 1024 * 1024 * 1024 / chunksize; // size is size = 1024 * 1024 * 1024 / chunksize

    fd = open("abc", O_RDONLY); // open the file


    int pos; // position

    pos = 2; // positon is 2
    dst = mmap(size * pos , size * chunksize, PROT_READ, MAP_SHARED, fd, 0); //use mmap


    int flags;
    flags = 0;
    ticks t1,t2; 
    int number = 0;
    t1 = gettime();
    for (i = 0; i < (size * chunksize); i += chunksize)
    {
	memcpy(tmp, dst+i, chunksize / 2 - 10); // use memcpy
	number++;
    }
    t2 = gettime();

    
    printf("%lf\n", (t2 - t1));  //get the cycle numbers
    
    munmap(dst, size* chunksize);
    close(fd);//close file
    exit(0);
}
