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
    

    fd=open("hello.txt",O_RDONLY);

    while((ret=read(fd,Buffer,sizeof(Buffer)))!=0)
    {

       for(int i=0;Buffer[i]!='\0';i++)
       {
          if(Buffer[i]>='a' && Buffer[i]<='z')
          {
            iCnt++;
           
          }
       }
       
    }

    printf("count of small letters is : %d\n",iCnt);
    return 0;
}
