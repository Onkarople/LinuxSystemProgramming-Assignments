#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#define  BLOCKSIZE 1024

int main(int argc,char *argv[])
{
    int fdSource=0,fdDest=0;
    int ret=0;
    //int size=0;
    char Buffer[BLOCKSIZE]={'\0'};

    if(argc!=3)
    {
        printf("Insufficient arguments");
        return -1;
    }

    fdSource=open(argv[1],O_RDONLY);
    if(fdSource==-1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fdDest=creat(argv[2],0777);
    if(fdDest==-1)
    {
        printf("Unable to cretae destination file\n");
        close(fdSource);
        return -1;
    }

   while((ret=read(fdSource,Buffer,sizeof(Buffer)))!=0)
   {
     write(fdDest,Buffer,ret);
     memset(Buffer,0,sizeof(Buffer));
   }

   close(fdSource);
   close(fdDest);

    return 0;
}