#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include <string>
class Student
{
    public:
	Student( const char* name,int size,Date birthdate);
	Student(std::string name,Date birthdate);
	int get_name_size();
	int get_name(char* buf);
	char *get_name();
	Date get_birthDate();
	void set_name(const char *buf,int size);
	void set_birthDate(Date date);
	void print();

    protected:
    private:
	char *name;
	static int student_count;
	Date birthDate;
};

#endif
