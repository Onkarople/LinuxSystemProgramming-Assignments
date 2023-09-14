#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

int Counter=0;

void *ThreadProc(void *ptr)
{
  
  int i=0;
  Counter++;
  printf("Thread executed with Counter : %d\n",Counter);
  for(i=0;i<0xFFFFFFFF;i++);
  printf("Thread completed with Counter :%d\n",Counter);
  pthread_exit(NULL);
   
}

int main()
{
  pthread_t tid1,tid2;
  int ret1=0,ret2=0;

  ret1=pthread_create(&tid1,NULL,ThreadProc,NULL);

  if(ret1!=0)
  {
    printf("Unable to create thread1\n");
    return -1;
  }     

  printf("Thread1 is created with ID: %lu\n",tid1);  

  ret2=pthread_create(&tid2,NULL,ThreadProc,NULL);

  if(ret2!=0)
  {
    printf("Unable to create thread\n");
    return -1;
  }     

  pthread_join(tid1,NULL);  
  pthread_join(tid2,NULL);                                      
  printf("End of main thread\n");                                                

  return 0;
}
