#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret=0;
    int ret=0;
    int cpid=0;
    int Exit_status=0;

    Ret=fork();

    if(Ret==0)
    {
      execl("./process3","NULL",NULL);
      
    }
    ret=fork();
    if(ret==0)
    {
      execl("./process2","NULL",NULL);
      
    }
    
    else
    {
       printf("parent process is running\n");
       cpid=wait(&Exit_status);
       printf("Child process is terminated status is:  %d\n",Exit_status);
       
       
    }



    return 0;
}
