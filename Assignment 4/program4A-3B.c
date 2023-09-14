#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

#define  BLOCKSIZE 10


int main(int argc,char *argv[])
{
    DIR *dp =NULL;
    struct dirent *entry=NULL;
    struct stat sobj; 
    char name[256];
    int fdScr=0;
    int fddest=0;
    int ret=0;

    char Buffer[BLOCKSIZE];

    

    
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
   
    fddest=creat("demo.txt",0777);
  
   
    while((entry=readdir(dp))!=NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
          fdScr=open(entry->d_name,O_RDONLY);
          if(fdScr==-1)
          {
           printf("Unable to open file\n");
           return -1;
          }

         ret=read(fdScr,Buffer,sizeof(Buffer))
       
         write(fddest,Buffer,ret);
               
        }
       
        
    }
    closedir(dp);
    close(fdDest);

   


    return 0;
}
