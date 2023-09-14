#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void *ThreadProc(void *ptr)
{
   printf("Value recived from main thread is : %d\n",(int)ptr);
}

int main()
{
  pthread_t tid;
  int ret=0;
  int no=11;

  ret=pthread_create(&tid,NULL,ThreadProc,(int *)no);

  if(ret!=0)
  {
    printf("Unable to create thread\n");
    return -1;
  }     

  printf("Thread is created with ID: %lu\n",tid);   
  pthread_join(tid,NULL);                                      
  printf("End of main thread\n");                                                  

  return 0;
}
