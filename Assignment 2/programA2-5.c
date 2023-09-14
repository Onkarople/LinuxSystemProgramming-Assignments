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
    long int iMax=0;
    char fname[50]={'\0'};

    
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
   

    while((entry=readdir(dp))!=NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        if(iMax<sobj.st_size)
        {
            iMax=sobj.st_size;
            fname=entry->d_name;
        }
        
    }
    closedir(dp);

    printf("Largest size of file is : %ld  and file name is :%s",iMax,fname);


    return 0;
}
