#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>



int main()
{
    void *ptr=NULL;
    int (*fptr)(int,int);

    int a=11,b=10;
    int ret=0;

    ptr=dlopen("lib.so",RTLD_NOW);
    if(ptr==NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr=dlsym(ptr,"Addition");
    if(fptr==NULL)
    {
        printf("Unable to load address of function\n");
        return -1;
    }

    ret=fptr(a,b);
    printf("Addition is:%d\n",ret);

    fptr=dlsym(ptr,"subtration");
    if(fptr==NULL)
    {
        printf("Unable to load address of function\n");
        return -1;
    }

    ret=fptr(a,b);
    printf("subtration  is:%d\n",ret);

    fptr=dlsym(ptr,"Multiplication");
    if(fptr==NULL)
    {
        printf("Unable to load address of function\n");
        return -1;
    }

    ret=fptr(a,b);
    printf("Multiplication is:%d\n",ret);


    fptr=dlsym(ptr,"Divison");
    if(fptr==NULL)
    {
        printf("Unable to load address of function\n");
        return -1;
    }

    ret=fptr(a,b);
    printf("division is:%d\n",ret);


    
    

    return 0;


}