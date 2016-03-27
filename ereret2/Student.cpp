#include "Student.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <iostream>

int Student::student_count =0;
Student::Student(const char* name,int size, Date birthdate)
{
    this->size = size;
    this->name = new char[size];
    birthDate =birthdate;
    set_name(name,size);
    student_count++;
}
Student::Student(std::string name,Date birthdate)
{
    size = name.size()+1;
    this->name = (char *)malloc(size);
    birthDate=birthdate;
    set_name(name.c_str(),size);
    student_count++;
}
Student::Student(Student &student)
{
    size = student.size;
    birthDate = student.birthDate;
    name = new char[size];
    memcpy(name,student.name,size);
    student_count++;
}
Student::~Student()
{
    delete name;
    student_count--;
}
int Student::get_name_size()
{
    return size;
}
int Student::get_name(char *buf)
{
    memcpy(buf,name,size);
    return 0;
}
char *Student::get_name()
{
    char *p = new char[size];
    memcpy(p,name,size);
    return p;
}
Date Student::get_birthDate()
{
    return birthDate;
}
void Student::set_name(const char *buf,int size)
{
    delete name;
    name = new char[size];
    memcpy(name,buf,size);
    this->size = size;
    return;
}
void Student::set_name(std::string name)
{
    delete this->name;
    size = name.size()+1;
    this->name = new char[size];
    memcpy(this->name,name.c_str(),size);
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
    for(int i=0;i<size-1;i++)
        printf("%c",name[i]);
    std::cout<<std::endl;
    std::cout<<"date |>"<<std::endl;
    birthDate.print();
}
