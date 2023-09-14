#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>


//client for named pipe

int main()
{
  int fd=0;
  char *path="/tmp/mypipe";
  char Buffer[100];

  printf("Client is running and Reading the data from named pipe...\n");
  fd=open(path,O_RDONLY);

  read(fd,Buffer,10);

  printf("data from named pipe is %s \n",Buffer);
  

  return 0;
}
