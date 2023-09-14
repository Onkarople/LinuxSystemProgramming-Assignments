#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    struct stat sobj;
    int mode =0;
   

    if(argc!=3)
    {
        printf("Insufficient parameters");
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
   

    


    if(!access(argv[1],F_OK | R_OK | W_OK | x_OK))
    {
        printf("permission is there");
    }
    else
    {
        printf("Failure");
        return -1;
    }
    
    
   


    return 0;
}
