#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include"sharedfile2.h"


bool compare(char name1[20],char name2[20])
{
    int fd1=0,fd2=0,ret=0;
    char Buffer1[1024];
    char Buffer2[1024];


    struct stat obj1,obj2;


    fd1=open(name1,O_RDONLY);
    fd2=open(name2,O_RDONLY);

    if(fd1==-1||fd2==-1)
    {
        printf("Unable to open \n");
        return -1;
    }  


    fstat(fd1,&obj1);
    fstat(fd2,&obj2);

    if(obj1.st_size !=obj2.st_size)
    {
        printf("files are differnt as sizes are differnt");
        return -1;
    }



     while((ret=read(fd1,Buffer1,sizeof(Buffer1)))!=0)
     {

        ret=read(fd2,Buffer2,sizeof(Buffer2));
        if(memcmp(Buffer1,Buffer2,ret)!=0)
        {
            break;
        }

     }

    if(ret==0)
    {
        return true;
    }
    else
    {
        return false;
    }

    close(fd2);
    close(fd2);

}