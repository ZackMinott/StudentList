#ifndef _myDATE
#define _myDATE
#include <string>

class myDate {
private:
	int month;
	int day;
	int year;
	int totalDays = 0;
	bool leap = false;
	int julian;
	int greg;
	//int nums[] //= { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
	myDate();
	myDate(int M, int D, int Y);
	void setYear(int Y);
	void setMonth(int M);
	void setDay(int D);
	void Display();
	void incrDate(int N);
	void decrDate(int N);
	int daysBetween(myDate D);
	int getMonth();
	int getDay();
	int getYear();
	int dayOfYear();
	int addingDays(int month);
	int JD(int month, int day, int year);
	void GD(int JD, int &month, int &day, int &year);
	void leapYear();
	std::string dayOfWeek();
};
#endif