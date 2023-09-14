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
    printf("--------------------------------------------------------------------------\n");

    printf("Entries from the directory file are: \n");
    printf("--------------------------------------------------------------------------\n");
    printf("file Name\n");

    



    while((entry=readdir(dp))!=NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        printf("%20s\n",entry->d_name);
    }
    closedir(dp);


    return 0;
}
