#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>


int main()
{
    int Ret=0;
    int fd=0;
    DIR *dp =NULL;
    struct dirent *entry=NULL;
    char oldname[50];

   
      
    fd=creat("demo.txt",0777);

    dp=opendir(".");
    
    if(dp==NULL)
    {
        printf("Unble to open directory\n");
        return -1;
    }

      while((entry=readdir(dp))!=NULL)
    {
        sprintf(oldname,"%s/%s",".",entry->d_name);
        write(fd,oldname,sizeof(oldname));

    }

     close(fd);  
    



    return 0;
}
