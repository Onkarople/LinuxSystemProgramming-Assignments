#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
    DIR *dp =NULL;
    struct dirent *entry=NULL;
    struct stat sobj; 
    char name[256];
    int fd=0;

    
    if(argc!=3)
    {
        printf("Insufficient parameters");
        return -1;

    }

    dp=opendir(argv[1]);
    if(dp==NULL)
    {
        printf("Unable to open directory");
        return -1;
    }
    
    sprintf(name,"%s/%s",argv[1],argv[2]);
    fd=creat(name,0777);



    return 0;
}
