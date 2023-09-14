#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<dlfcn.h>



int main()
{
    void *ptr=NULL;
    bool (*fptr)(char[],char[]);
    bool ret=false;

    char name1[20]="\0";
    char name2[20]=;
    printf("Enter first file name\n");
    scanf("%s",&name1);

    printf("Enter second file name\n");
    scanf("%s",&name2);

    ptr=dlopen("lib.so",RTLD_NOW);
    if(ptr==NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr=dlsym(ptr,"compare");
    if(fptr==NULL)
    {
        printf("Unable to load address of function\n");
        return -1;
    }

    ret=fptr(name1,name2);

    if(ret==true)
    {
        printf("Files are equal");
    }
    else
    {
        printf("Not equal");
    }
    

    return 0;


}