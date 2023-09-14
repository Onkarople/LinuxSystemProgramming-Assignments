#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


void *ThreadProc1(void *ptr)
{
  int i=0;
  for(i=1;i<500;i++)
  {
    printf("thread1 with counter : %d\n",i);
  }
  pthread_exit(NULL);
}


void *ThreadProc2(void *ptr)
{
  int i=0;
  for(i=500;i>=1;i--)
  {
    printf("thread2 with counter : %d\n",i);
  }
  pthread_exit(NULL);
}


int main()
{
  pthread_t tid1,tid2;
  int ret1=0,ret2=0;

  ret1=pthread_create(&tid1,NULL,ThreadProc1,NULL); 

  if(ret1!=0)
  {
    printf("Unable to create thread\n");
    return -1;
  }     

  printf("Thread1 is created with ID: %ld\n",tid1); 
  pthread_join(tid1,NULL);     


  ret2=pthread_create(&tid2,NULL,ThreadProc2,NULL); 

  if(ret2!=0)
  {
    printf("Unable to create thread\n");
    return -1;
  }     

  printf("Thread2 is created with ID: %ld\n",tid2);   


  
  pthread_join(tid2,NULL);                                      
                                                                                             

  printf("End of main thread\n");  


  pthread_exit(NULL);
  return 0;
}
