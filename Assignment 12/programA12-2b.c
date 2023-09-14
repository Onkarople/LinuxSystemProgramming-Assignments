#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/shm.h>


//server for named pipe

int main()
{
  int shmid=0;
  int shmsize=100;
  int key=1234;
  char *ptr=NULL;

  printf("client application renning...\n");

  shmid=shmget(key,shmsize,  0666);
  ptr=shmat(shmid,NULL,0);

  if(ptr!=NULL)
  {
    printf("shared memory attched succesfully..\n");
  }

   printf("data is :");
   while(*ptr!='\0')
   {
    printf("%c",*ptr);
    ptr++;
   }
  

  shmdt(shmid);

  



  return 0;
}
