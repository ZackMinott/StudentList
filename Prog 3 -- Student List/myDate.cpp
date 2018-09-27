//myDate.cpp
//Author: Zachary Minott
//CECS 282-05 (T/TH)
//Program #2 due date:	10/03/2017
//
//
#include "myDate.h"
#include <iostream>
#include <string>
using namespace std;

myDate::myDate() {
	day = 11;
	month = 5;
	year = 1959;
}

myDate::myDate(int M, int D, int Y) {
	int a, b, c;
	a = M;
	b = D;
	c = Y;

	julian = JD(M, D, Y);

	GD(julian, M, D, Y);

	if (M == a && D == b && Y == c) {
		month = M;
		day = D;
		year = Y;
	}
	else {
		month = 5;
		day = 11;
		year = 1959;
	}

}

void myDate::setMonth(int M) {
	month = M;
}

void myDate::setDay(int D) {
	day = D;
}

void myDate::setYear(int Y) {
	year = Y;
}

void myDate::Display() {
	if (month == 1)
		cout << "January ";
	else if (month == 2)
		cout << "February ";
	else if (month == 3)
		cout << "March ";
	else if (month == 4)
		cout << "April ";
	else if (month == 5)
		cout << "May ";
	else if (month == 6)
		cout << "June ";
	else if (month == 7)
		cout << "July ";
	else if (month == 8)
		cout << "August ";
	else if (month == 9)
		cout << "September ";
	else if (month == 10)
		cout << "October ";
	else if (month == 11)
		cout << "November ";
	else if (month == 12)
		cout << "December ";

	cout << day << ", " << year;
}

void myDate::incrDate(int N) {
	julian = JD(month, day, year);
	julian = julian + N;
	GD(julian, month, day, year);
	/*for (int i = 0; i < N; i++) {
	day++;
	if (leap == false) {
	if (day > nums[month - 1]) {
	month++;
	if (month > 12)
	month = 1;
	day = 1;
	}
	}
	else if (leap == true) {
	if (month == 2) {
	if (day > 29) {
	month++;
	day = 1;
	}
	}
	else if (day > nums[month - 1]) {
	month++;
	if (month > 12)
	month = 1;
	day = 1;
	}
	}
	}
	*/
}

void myDate::decrDate(int N) {
	julian = JD(month, day, year);
	julian = julian - N;
	GD(julian, month, day, year);
	/*for (int i = 0; i < N; i++) {
	day--;
	if (leap == false) {
	if (day < 1) {
	if (month == 1) {
	month = 12;
	}
	else
	month--;
	day = nums[month - 1];
	}
	}
	else if (leap == true) {
	if (month == 3 && day < 1) {
	day = 29;
	month--;
	}
	else if (day < 1) {
	if (month == 1) {
	month = 12;
	}
	else
	month--;
	day = nums[month - 1];
	}
	}
	}*/
}

int myDate::daysBetween(myDate D) {
	julian = JD(month, day, year);
	int m = D.getMonth();
	int d = D.getDay();
	int y = D.getYear();
	int jDate = D.JD(m, d, y);
	int diff = julian - jDate;
	if (diff < 0)
		return -1 * diff;
	else
		return diff;

}



int myDate::getMonth() {
	return month;
}

int myDate::getDay() {
	return day;
}

int myDate::getYear() {
	return year;
}

void myDate::leapYear() {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)
				leap = true;
			else
				leap = false;
		}
		else
			leap = true;
	}
	else
		leap = false;
}

int myDate::addingDays(int m) {
	int sum = 0;
	int nums[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0; i < m; i++) {
		sum += nums[i];
	}
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0)
				sum += 1;
			else
				sum = sum;
		}
		else
			sum += 1;
	}
	return sum;
}

int myDate::dayOfYear() {
	int nums[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	totalDays = 0;
	if (month == 1) {
		totalDays = day;
	}
	else if (month == 2) {
		totalDays = nums[0] + day;
	}
	else if (month == 3) {
		totalDays = addingDays(2) + day;
	}
	else if (month == 4) {
		totalDays = addingDays(3) + day;
	}
	else if (month == 5) {
		totalDays = addingDays(4) + day;
	}
	else if (month == 6) {
		totalDays = addingDays(5) + day;
	}
	else if (month == 7) {
		totalDays = addingDays(6) + day;
	}
	else if (month == 8) {
		totalDays = addingDays(7) + day;
	}
	else if (month == 9) {
		totalDays = addingDays(8) + day;
	}
	else if (month == 10) {
		totalDays = addingDays(9) + day;
	}
	else if (month == 11) {
		totalDays = addingDays(10) + day;
	}
	else if (month == 12) {
		totalDays = addingDays(11) + day;
	}


	/*else if (totalDays > 366 && leap == true) {
	totalDays = 0;
	}*/

	return totalDays;
}

string myDate::dayOfWeek() {
	string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;
	int d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m / 12)) % 7;

	return days[d];
}

//converts gregorian date to julian date
int myDate::JD(int m, int d, int y) {
	int I, J, K;

	I = y;

	J = m;

	K = d;



	julian = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;

	return julian;
}

//converts julian date to gregorian
void myDate::GD(int JD, int &month, int &day, int &year) {
	int I, J, K;
	int L, N;

	L = JD + 68569;

	N = 4 * L / 146097;

	L = L - (146097 * N + 3) / 4;

	I = 4000 * (L + 1) / 1461001;

	L = L - 1461 * I / 4 + 31;

	J = 80 * L / 2447;

	K = L - 2447 * J / 80;

	L = J / 11;

	J = J + 2 - 12 * L;

	I = 100 * (N - 49) + I + L;

	year = I;
	month = J;
	day = K;
}