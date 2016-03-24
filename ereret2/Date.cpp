#include "Date.h"
#include <iostream>
#include <iomanip>
using namespace std;

Date::Date( int year, int month, int day )
{
	setDate( year, month, day );
}

Date::Date( Date &d )
{
	year = d.year;
	month = d.month;
	day = d.day;
}
int Date::getDate( int &a, int &b, int &c )
{
	year = a;
	month = b;
	day = c;
	return 0;	
}

void Date::setDate( int y, int m, int d )
{
	year = ( y >= 1 ) ? y : 1900;
	month = ( m >= 1 && m <= 12) ? m : 1;
	int days[ 2 ][ 13 ] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, 
{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
    int leapyear = 0;
	if ( isLeapYear() )
       leapyear = 1;
    day = ( d >= 1 && d <= days[ leapyear ][ m ] ) ? d : 1;
	
}

bool Date::isLeapYear()
{
	if ( ( year % 100 != 0 && year % 4 == 0) || year % 400 == 0 )
	   return true;
	else 
	   return false;
}

int Date::nextDay()
{
	int days[ 2 ][ 13 ] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, 
{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
    int leapyear = 0;
	if ( isLeapYear() )
       leapyear = 1;
    day++;
	if ( day > days[ leapyear ][ month ] )
	{
		month++;
		day = 1;
	}   
	if ( month > 12 )
	{
		year++;
		month = 1;
		day = 1;
	} 
}

void Date::print()
{
	cout << year << " " << setfill( '0' ) << setw( 2 ) << month << " " << setw( 2 ) << day << endl;
}

