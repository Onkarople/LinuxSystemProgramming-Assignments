#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

#define  BLOCKSIZE 1024


int main(int argc,char *argv[])
{
    DIR *dp =NULL;
    struct dirent *entry=NULL;
    struct stat sobj; 
    char name[256];
    char dname[256];
    int ret=0;


    

    
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
   

   
    
    while((entry=readdir(dp))!=NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        sprintf(dname,"%s/%s",argv[2],entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            ret=rename(name,dname);
        }
        
        
    }
    closedir(dp);

   


    return 0;
}
