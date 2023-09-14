#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>

#define  BLOCKSIZE 1025


int main(int argc,char *argv[])
{
   
    char name[256];
    char Buffer1[BLOCKSIZE];
    char Buffer2[BLOCKSIZE];

    struct stat sobj1;
    struct stat sobj2;

    int fds=0,fdd=0;
    int ret=0;

    
    if(argc!=3)
    {
        printf("Insufficient parameters");
        return -1;

    }

    fds=open(argv[1],O_RDONLY);
    if(fds==-1)
    {
        printf("Unable to open file\n");
        return -1;
    }


    fdd=open(argv[2],O_RDONLY);
    if(fdd==-1)
    {
        printf("Unable to open file\n");
        return -1;
    }


    stat(argv[1],&sobj1);
    stat(argv[2],&sobj2);

    if(sobj1.st_size!=sobj2.st_size)
    {
        printf("Not equall\n");
        return -1;
    }

    while((ret=read(fds,Buffer1,sizeof(Buffer1)))!=0)
   {
       ret=read(fdd,Buffer2,sizeof(Buffer2));
       if(memcmp(Buffer1,Buffer2,ret)!=0)
       {
         break;
       }

   }
   
    if(ret==0)
    {
        printf("both files are smae\n");
    }
    else
    {
        printf("differnt\n");
    }


    close(fdd);
    close(fds);



    

    return 0;
}
