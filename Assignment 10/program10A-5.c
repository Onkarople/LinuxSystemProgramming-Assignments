#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void *ThreadProc(void *ptr)
{
  printf("Inside thread\n");
  printf("thread id is in thread function %ld\n",pthread_self());
  pthread_exit(NULL);
}

int main()
{
  pthread_t tid;
  int ret=0;

  ret=pthread_create(&tid,NULL,ThreadProc,NULL); 
  if(ret!=0)
  {
    printf("Unable to create thread\n");
    return -1;
  }     

  printf("Thread is created with ID: %ld\n",tid); 

  
  pthread_join(tid,NULL);                                      
                                                    

  printf("End of main thread\n");  


  pthread_exit(NULL);                                        
                                                    

  return 0;
}
