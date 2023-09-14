#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

#define BLOCKSIZE 1025


int main(int argc,char *argv[])
{
    DIR *dp =NULL;
    struct dirent *entry=NULL;
    struct stat sobj; 
    char name[256];
    int fd=0;
    int fdScr=0;
    int ret=0;
    char Buffer[BLOCKSIZE];
    char header[100]={'\0'};
    char hname[256];
    long int lsize=0;

   
    
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
   
     fd=creat("FileCobine.txt",0777);

    while((entry=readdir(dp))!=NULL)
    {
        
         sprintf(name,"%s/%s",argv[1],entry->d_name);
          stat(name,&sobj);
          if(S_ISREG(sobj.st_mode))
          {
            fdScr=open(name,O_RDWR);
            if(fdScr==-1)
            {
              printf("Unable to open file\n");
              return -1;
            }

            printf("File name :%s\n",name);
            strcpy(header,entry->d_name);
            


          
            write(fd,header,sizeof(header));
            write(fd,"\n",sizeof("\n"));
            write(fd,"1",2);
            write(fd,"\n",sizeof("\n"));

        
           
            while((ret=read(fdScr,Buffer,sizeof(Buffer)))!=0)
            {
                write(fd,Buffer,ret);

            }
            write(fd,"\n",sizeof("\n"));


             
             
           
          }
   }

  
          
    closedir(dp);


    return 0;
}
