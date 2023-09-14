#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

#pragma pack(1)

struct Student
{
    int roolno;
    char sname[20];
    float Marks;
    int age;
};


int main(int argc,char* argv[])
{
   int fd=0; 
   char Fname[20];
   struct Student sobj;


   printf("Enter file name\n");
   scanf("%s",Fname);

    fd=open(Fname,O_RDONLY);

    read(fd,&sobj,sizeof(sobj));
    printf("roll no is : %d",sobj.roolno);
    printf("filename is : %s",sobj.sname);
    printf("marks are %f",sobj.Marks);
    printf("age is  %d",sobj.age);


    return 0;
}
