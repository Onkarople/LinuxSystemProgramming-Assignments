#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


void *ThreadProc1(void *ptr)
{
  int fd=0;
  char Buffer[512];
  int iCnt=0;
  int iRet=0;


  fd=open("demo.txt",O_RDONLY);

  while((iRet=read(fd,Buffer,sizeof(Buffer)))!=0)
  {
    for(int i=0;i<iRet;i++)
    {
        if((Buffer[i]>='A')&&(Buffer[i]<='Z'))
        {
            iCnt++;
        }
     }
   }
   printf("Number of Capital leters are:%d\n",iCnt);

   close(fd);
    
  pthread_exit(NULL);
  
}


void *ThreadProc2(void *ptr)
{
  int fd=0;
  char Buffer[512];
  int iCnt=0;
  int iRet=0;


  fd=open("demo.txt",O_RDONLY);

  while((iRet=read(fd,Buffer,sizeof(Buffer)))!=0)
  {
    for(int i=0;i<iRet;i++)
    {
        if((Buffer[i]>='a')&&(Buffer[i]<='z'))
        {
            iCnt++;
        }
     }
   }
   printf("Number of small leters are:%d\n",iCnt);

   close(fd);
    
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

  printf("Thread1 is created with ID: %lu\n",tid1);

  ret2=pthread_create(&tid2,NULL,ThreadProc2,NULL); 
  if(ret2!=0)
  {
    printf("Unable to create thread2\n");
    return -1;
  }     

  printf("Thread2 is created with ID: %lu\n",tid2);   


  pthread_join(tid1,NULL);                                
  pthread_join(tid2,NULL);                                      
                                                    

  printf("End of main thread\n");                                                  

  return 0;
}
