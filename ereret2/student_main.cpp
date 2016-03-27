#include "Student.h"
#include <iostream>
#include <string>
#include "Student.h"
#define PROMPT " |> "
using namespace std;
int main()
{
    string name;
    int a,b,c;
    cout<<"输入生日"<<PROMPT;
    cin >> a>>b>>c;
    Date birthday(a,b,c);
    cout<<"输入姓名"<<PROMPT;
    cin >> name;
    Student S1(name.c_str(),name.size()+1,birthday);
    Student S2(name,birthday);
    S1.print();
    S2.print();
    S1.get_birthDate().print();
    S2.get_birthDate().print();
    string nameout(S1.get_name());
    cout<< "nameout"<<nameout<<endl;
    cout<< S1.get_name_size()<<endl;
    string nextname;
    cout<<"next name"<<PROMPT;
    cin >> nextname;
    S1.set_name(nextname);
    S2.set_name(nextname.c_str(),nextname.size()+1);
    S1.print();
    S2.print();
    cout<<"next date"<<PROMPT;
    cin >>a>>b>>c;
    Date nextdate(a,b,c);
    S2.set_birthDate(nextdate);
    S2.print();


}
