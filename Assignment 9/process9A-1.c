#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>


#define  BLOCKSIZE 1024


int main()
{
     
    int fd=0;
    int ret=0;
    int i=0;
    int iCnt=0;

    char Buffer[BLOCKSIZE];
    

    fd=open("demo.txt",O_RDONLY);

    while((ret=read(fd,Buffer,sizeof(Buffer)))!=0)
    {

       for(int i=0;Buffer[i]!='\0';i++)
       {
          if(Buffer[i]>=65 && Buffer[i]<=90)
          {
            iCnt++;
           
          }
       }
       
    }

    printf("count is : %d\n",iCnt);
    return 0;
}
