#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("childd is running\n");
    int ret=0;

    ret=fork();
    if(ret==0)
    {
        execl("./procces","NULL",NULL);
    }
   

    return 0;
}