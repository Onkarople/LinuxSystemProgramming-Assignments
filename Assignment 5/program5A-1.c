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

   sobj.roolno=11;
   sobj.Marks=89.00;
   sobj.age=23;
   strcpy(sobj.sname,"om");


   printf("Enter file name\n");
   scanf("%s",Fname);

   fd=creat(Fname,0777);

   write(fd,&sobj,sizeof(sobj));
   




    return 0;
}
