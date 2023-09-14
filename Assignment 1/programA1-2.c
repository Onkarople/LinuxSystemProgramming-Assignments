#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int fd=0;
    int Mode=0;
    if(argc!=3)
    {
        printf("invalid number of arguments\n");
        return -1;
    }

    if(strcmp(argv[2],"Read")==0)
    {
        Mode=O_RDONLY;
    }
    else if(strcmp(argv[2],"Write")==0)
    {
        Mode=O_WRONLY;
    }
    else if(strcmp(argv[2],"RDWR")==0)
    {
        Mode=O_RDWR;
    }

    else
    {
        Mode=O_RDONLY;
    }
   

    fd=open(argv[1],Mode);
    if(fd==-1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("File is succesfully opened with fd : %d\n",fd);
    }

    return 0;
}

//O_RDONLY
//O_RDWR
//o-WRONLY
//O_CREATE