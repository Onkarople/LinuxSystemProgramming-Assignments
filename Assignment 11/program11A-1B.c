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
   pthread_t tid[4];
   int ret[4];
   char name[20];

   for(int i=1;i<=4;i++)
   {
     sprintf(name,"%s%d",ThreadProc,i);
     ret[i]=pthread_create(tid[i],NULL,name,NULL);
     if(ret[i]!=0)
     {
      printf("Unable to create thread\n");
      return -1;
     }
     pthread_join(tid[i],NULL);
   }

   printf("End of main thread\n");

   pthread_exit(NULL);


    return 0;
}