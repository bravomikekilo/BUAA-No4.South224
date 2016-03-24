#ifndef DATE_H
#define DATE_H

class Date
{
	public:
		Date( int year, int month, int day );
		Date( Date &d );
	    int getDate( int &a, int &b, int &c );
		void setDate( int y, int m, int d );
		bool isLeapYear();
		int nextDay();
	    void print();
	protected:
	private:
		int year;
		int month;
		int day;
};

#endif


