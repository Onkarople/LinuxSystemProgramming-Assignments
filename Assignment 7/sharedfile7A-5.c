#include<sys/stat.h>
#include"sharedfile5.h"
#include<stdio.h>

void Display(char Arr[])
{
    struct stat sobj;

    stat(Arr,&sobj);

    printf("FIle name is %s\n",Arr);
    printf("file size is :%ld\n",sobj.st_size);
    printf("Number of links:%ld\n",sobj.st_nlink);
    printf("Inode Number:%ld\n",sobj.st_ino);
    printf("file system number:%ld\n",sobj.st_dev);
    //printf("number of blocks :%ld\n",sobj.st_blocks);
    printf("Mode of file is :%d\n",sobj.st_mode);

}
