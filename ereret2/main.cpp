#include <iostream>
#include "Date.h"
using namespace std;

int main(int argc, char** argv) {
		Date date;
	Date &date1 = date;
	int a, b, c;
	cout << "Enter the date: ";
	cin >> a >> b >> c;
	date.getDate( a, b, c );
	date.setDate( a, b, c );
	date.print();
	date1.print();
	if ( date.isLeapYear() )
		cout << "����������" << endl; 
	else
	    cout << "���겻������" << endl;
	date.nextDay();
    cout << "date = ";
    date.print();
}




