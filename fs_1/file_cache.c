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

#define BLOCKSIZE 4096

int main(int argc, char** argv)
{
  unsigned long long file_size = atoll(argv[1]) * BLOCKSIZE;
  char* file_name = argv[2];
  printf("%llu\n", file_size);
  printf("%s\n", file_name);

  ticks t1, t2;
  char* i[5000];
  int fd = open(file_name, O_RDONLY, 0);
  unsigned long long bytesRead = 0;
  int bytes;
  char* j[5000];
  lseek(fd, file_size-1,SEEK_SET);
  while(1)
  {
    lseek(fd, -2*BLOCKSIZE, SEEK_CUR);
    bytes = read(fd, &j,BLOCKSIZE);
    //printf("%llu %llu %d\n", bytesRead, file_size - 2*BLOCKSIZE, bytesRead >= file_size-2*BLOCKSIZE);
    if (bytes <= 0 || bytesRead >= file_size-2*BLOCKSIZE)
      break;
    bytesRead += bytes;
    //printf("bytes read = %llu\n",bytesRead);
  }
  printf("bytes read = %llu\n",bytesRead);

  t1 = getTime();
  printf("%llu\n",t1);

  

  lseek(fd, file_size-1, SEEK_SET);
  bytesRead = 0;
  while(1){
    lseek(fd, -2*BLOCKSIZE, SEEK_CUR);
    bytes = read(fd, &i, BLOCKSIZE);
    if (bytes <= 0 || bytesRead >= file_size-2*BLOCKSIZE)
      break;
    bytesRead += bytes;
    //printf("bytes read = %llu\n", bytesRead);
  }
  printf("bytes read = %llu\n",bytesRead);

  t2 = getTime();
  printf("%llu\n", t2);
  printf("cycles = %llu\n", t2 - t1);
 
  return 0;
}
