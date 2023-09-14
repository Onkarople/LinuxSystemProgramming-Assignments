#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    int fd=0;
    char Buffer[]="Hello World";
    int ret=0;
    //int size=0;

    if(argc!=2)
    {
        printf("Insufficient arguments");
        return -1;
    }

    fd=open(argv[1],O_RDWR);
    if(fd==-1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    ret=write(fd,Buffer,sizeof(Buffer));
    if(ret>0)
    {
        printf("File write sucessfully\n");
    }
  

    return 0;
}