#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

#define  BLOCKSIZE 20


int main(int argc,char *argv[])
{

    int fd=0;
    char buffer[BLOCKSIZE];
    int iPos=0;
    int ret=0;
    int mode=0;

    
    if(argc!=3)
    {
        printf("Insufficient parameters");
        return -1;

    }

    fd=open(argv[1],O_RDONLY);
    iPos=atoi(argv[2]);


    lseek(fd,iPos,0);

    read(fd,buffer,20);

    write(1,buffer,20);



    return 0;
}
