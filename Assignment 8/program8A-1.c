#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret=0;

    Ret=fork();

    if(Ret==0)
    {
      execl("./procces","NULL",NULL);
    }
    else
    {
       printf("parent process is running\n");
       wait(NULL);
       printf("Child is terminated\n");
    }



    return 0;
}
