#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>


//server for named pipe

int main()
{
  int fd=0;
  char *path="/tmp/mypipe";

  fd=mkfifo(path,0666);
  if(fd==-1)
  {
    printf("Unable to create named pipe\n");
  }

  printf("Server is running and writing the data into named pipe...\n");
  fd=open(path,O_WRONLY);

  write(fd,"Marvellous",10);
  close(fd);

  unlink(path);

  printf("Dta suceesfullr written in hhe pipe\n");

  


  return 0;
}
