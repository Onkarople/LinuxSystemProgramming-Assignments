#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>


int main()
{
    int Ret=0;

    Ret=fork();

    if(Ret==0)
    {
       execl("./copy","NULL",NULL);
    }
    else
    {
      printf("Parent is running with PID : %d\n",getpid());
    }



    return 0;
}
