#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


void *ThreadProc1(void *ptr)
{
    printf("Inside thread1\n");
    printf("Thread1 is created with ID : %ld\n",pthread_self());
    pthread_exit(NULL);
}


void *ThreadProc2(void *ptr)
{
    printf("Inside thread2\n");
    printf("Thread2 is created with ID : %ld\n",pthread_self());
    pthread_exit(NULL);
}


void *ThreadProc3(void *ptr)
{
    printf("Inside thread3\n");
    printf("Thread3 is created with ID : %ld\n",pthread_self());
    pthread_exit(NULL);
}


void *ThreadProc4(void *ptr)
{
    printf("Inside thread4\n");
    printf("Thread4 is created with ID : %ld\n",pthread_self());
    pthread_exit(NULL);
}



int main()
{
   pthread_t tid1,tid2,tid3,tid4;
   int ret1=0,ret2=0,ret3=0,ret4=0;

   ret1=pthread_create(&tid1,NULL,ThreadProc1,NULL);
   if(ret1!=0)
   {
     printf("Unable to create thread1\n");
     return -1;
   }
   pthread_join(tid1,NULL);

   ret2=pthread_create(&tid2,NULL,ThreadProc2,NULL);
   if(ret2!=0)
   {
     printf("Unable to create thread2\n");
     return -1;
   }
   pthread_join(tid2,NULL);

   ret3=pthread_create(&tid3,NULL,ThreadProc3,NULL);
   if(ret3!=0)
   {
     printf("Unable to create thread3\n");
     return -1;
   }
    pthread_join(tid3,NULL);

    ret4=pthread_create(&tid4,NULL,ThreadProc4,NULL);
    if(ret4!=0)
    {
      printf("Unable to create thread2\n");
      return -1;
    }
    pthread_join(tid4,NULL);

   printf("End of main thread\n");

   pthread_exit(NULL);


    return 0;
}