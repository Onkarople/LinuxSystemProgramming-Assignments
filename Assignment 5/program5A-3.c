#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

#define BLOCKSIZE 1025

struct fileinfo
{
    char fname[20];
    int fsize;
};

int main(int argc,char *argv[])
{
    DIR *dp =NULL;
    struct dirent *entry=NULL;
    struct stat sobj; 
    char name[256];
    char Buffer[BLOCKSIZE];
    int fd=0;
    int ret=0;
   long int size = 0;


    
    if(argc!=2)
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
  
    fd=open("demo.txt", O_RDWR | O_APPEND);

    struct fileinfo fobj;

    while((entry=readdir(dp))!=NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        size=sobj.st_size;
        fobj.fsize=size;
        strcpy(fobj.fname,entry->d_name);

        write(fd,&fobj,sizeof(fobj));
 
        
    }


     closedir(dp);

    while((ret=read(fd,Buffer,sizeof(Buffer)))!=0)
   {
     write(1,Buffer,ret);
   }

  
    return 0;
}
