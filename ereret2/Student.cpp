#include "Student.h"
#include <stdlib.h>
#include <cstring>
#include <iostream>

int Student::student_count =0;
Student::Student(const char* name,int size, Date birthdate)
{
    name = (char *)malloc(size);
    birthDate =birthdate;
    set_name(name,size);
    student_count++;
}
Student::Student(std::string name,Date birthdate)
{
    name = (char *)malloc(sizeof name.c_str());
    birthDate=birthdate;
    set_name(name.c_str(),sizeof name.c_str());
    student_count++;
}
int Student::get_name_size()
{
    char *p = name;
    int size = 1;
    while(*p!='\0')
    {
	size++;
	p++;
    }
    return size;
}
int Student::get_name(char *buf)
{
    memcpy(buf,name,get_name_size());
    return 0;
}
char *Student::get_name()
{
    char *p = (char *)malloc(get_name_size());
    memcpy(p,name,get_name_size());
    return p;
}
Date Student::get_birthDate()
{
    return birthDate;
}
void Student::set_name(const char *buf,int size)
{
    memcpy(name,buf,size);
    return;
}
void Student::set_birthDate(Date date)
{
    birthDate = date;
    return;
}
void Student::print()
{
    std::cout<<"name |>"<<std::endl;
    for(int i=0;i<get_name_size()-1;i++)
        printf("%c",name[i]);
    std::cout<<std::endl;
    std::cout<<"date |>"<<std::endl;
    birthDate.print();
}
