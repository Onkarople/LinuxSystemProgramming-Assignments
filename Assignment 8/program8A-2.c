#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret=0;

    Ret=fork();

    if(Ret==0)
    {
      execl("./process2","NULL",NULL);
    }
    else
    {
       printf(" grand parent process is running\n");
       
    }



    return 0;
}
