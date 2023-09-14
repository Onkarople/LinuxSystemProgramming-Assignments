#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
    
    int check;

    if(argc!=2)
    {
        printf("Insufficient parameters");
        return -1;

    }

 
    check = mkdir(dirname,0777);
 
    // check if directory is created or not
    if (check==0)
        printf("Directory created\n");
    else {
        printf("Unable to create directory\n");
        exit(1);
    }

   

    



  

    return 0;
}
