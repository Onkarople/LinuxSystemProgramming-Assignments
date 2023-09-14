#include<stdio.h>
#include<fcntl.h>
#include<string.h>

struct Student
{
    int UID;
    char *Name;
    char *City;
    int age;
    float marks;
};


int main(int argc ,char* argv[])
{
    int fd=0,No=0;
    char name[15];
    char city[15];
    char id[15];
    


    if(argc!=4)
    {
        printf("insufficient arguments");
        return -1;
    }

    fd=open("demo.txt", O_RDWR | O_APPEND);

    struct Student sobj;
     
   

    sobj.UID=atoi(argv[1]);
    sobj.Name=argv[2];
    sobj.City=argv[3];



    sprintf(id,"%s:%d","UID is : ",sobj.UID);
    sprintf(name,"%s:%s","NAme is ",sobj.Name);
    sprintf(city,"%s:%s","City is ",sobj.City);

   

    write(fd,id,sizeof(id));
    write(fd,"\n",sizeof("\n"));
    write(fd,name,sizeof(name));
    write(fd,"\n",sizeof("\n"));
    write(fd,city,sizeof(city));



    return 0;
}