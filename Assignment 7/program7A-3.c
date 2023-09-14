#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<stdbool.h>

int main()
{
    void *ptr=NULL;
    bool(*fptr)(int);
    int(*iptr)(int);
    void(*vptr)(int);

    int a=0;
    bool bret=false;
    int ret=0;

    printf("Enter number\n");
    scanf("%d",&a);

    ptr=dlopen("lib.so",RTLD_NOW);
    if(ptr==NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr=dlsym(ptr,"CheckPerfect");
    if(fptr==NULL)
    {
        printf("Unable to load address of  perfect function\n");
        return -1;
    }

    bret=fptr(a);
     if(bret==true)
     {
        printf("perfect\n");
     }
     else
     {
        printf("Not perfect\n");
     }

    iptr=dlsym(ptr,"CountFact");
    if(iptr==NULL)
    {
        printf("Unable to load address of count function\n");
        return -1;
    }
    

    ret=iptr(a);

    printf("Count is :%d\n",ret);


    vptr=dlsym(ptr,"DisplayFact");
    if(vptr==NULL)
    {
        printf("Unable to load address of display function\n");
        return -1;
    }


    vptr(a);




     return 0;


}