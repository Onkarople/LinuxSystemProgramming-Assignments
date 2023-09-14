#include<stdio.h>
#include<fcntl.h>


int main(int argc,char *argv[])
{
    int fd=0;

    if(argc!=3)
    {
        printf("invalid number of arguments\n");
        return -1;
    }

    fd=open(argv[1],O_RDONLY);
    if(fd==-1)
    {
        printf("Unable to open file");
    }
    else
    {
        printf("File is opned succesfully");
    }

    return 0;
}