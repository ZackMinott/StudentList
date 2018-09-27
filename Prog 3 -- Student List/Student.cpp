//#include "student.h"
//#include <iostream>
//#include <random>
//#include <iomanip>
//
//using namespace std;
//
//
//
//int student::randomID() {
//	int x = rand() % ((9999 - 1000) + 1) + 1000;
//	return x;
//}
//
//char student::randomGrade() {
//	char grade[] = { 'A', 'B', 'C', 'D', 'F' };
//	char x = rand() % 5;
//	return x;
//}
//
////myDate student::randomDate() {
////	myDate min(1, 1, 1995);
////	myDate max(12, 31, 2000);
////	int x = min.daysBetween(max);
////	int d = rand() % x;
////	min.incrDate(x);
////	return min;
////}
//
//
////Find help for this
//void student::populateStudents(Student arr[], int size) {
//	string names[] = {"Spongebob Squarepants", "Bruce Wayne", "Clark Kent", "Crimson Chin", "Timmy Turner", "Fred Flinstone", "Mickey Mouse", "Scooby Doo", "Grinch", "Jimmy Neutron"};
//	string hometown[] = {"Bikini Bottom", "Gotham City", "Smallville", "Chincinatti", "Dimmsdale", "Bedrock", "Mouseton", "Koolsville", "Whoville", "Retroville"};
//	for (int i = 0; i < size; i++) {
//		//string x = names[i];
//		//Bday
//		myDate min(1, 1, 1995);
//		myDate max(12, 31, 2000);
//		int x = min.daysBetween(max);
//		int d = rand() % x;
//		min.incrDate(x);
//		arr[i].bday.setYear(min.getYear());
//		arr[i].bday.setMonth(min.getMonth());
//		arr[i].bday.setDay(min.getDay());
//
//		strcpy(arr[i].name, names[i].c_str);
//		arr[i].ID = randomID();
//		arr[i].grade = randomGrade();
//		//arr[i].bday = randomDate();
//		arr[i].homeTown = hometown[i];
//	}
//}
//
////sorts ID
//void student::sortByID(Student *spt[]) {
//	for (int i = size - 1; i > 0; i--) {
//		for (int j = 0; j < i; j++) {
//			if (spt[j]->ID > spt[j + 1]->ID) {
//				Student *temp = spt[j];
//				spt[j] = spt[j + 1];
//				spt[j + 1] = temp;
//			}
//		}
//	}
//}
//
////sorts names
//void student::sortByName(Student *spt[]) {
//	for (int i = size - 1; i > 0; i--) {
//		for (int j = 0; j < i; j++) {
//			if (strcmp(spt[j]->name, spt[j + 1]->name) > 0) {
//				Student *temp = spt[j];
//				spt[j] = spt[j + 1];
//				spt[j + 1] = temp;
//			}
//		}
//	}
//}
//
////sort grade
//void student::sortByGrade(Student *spt[]) {
//	for (int i = size - 1; i > 0; i--) {
//		for (int j = 0; j < i; j++) {
//			if (spt[j]->grade > spt[j + 1]->grade) {
//				Student *temp = spt[j];
//				spt[j] = spt[j + 1];
//				spt[j + 1] = temp;
//			}
//		}
//	}
//}
//
////sorts hometown
//void student::sortByHometown(Student *spt[]) {
//	for (int i = size - 1; i > 0; i--) {
//		for (int j = 0; j < i; j++) {
//			if (spt[j]->homeTown.compare(spt[j + 1] ->homeTown) > 0) {
//				Student *temp = spt[j];
//				spt[j] = spt[j + 1];
//				spt[j + 1] = temp;
//			}
//		}
//	}
//}
//
////sort by bday
//void student::sortByBirthday(Student *spt[]) {
//	for (int i = size - 1; i > 0; i--) {
//		for (int j = 0; j < i; j++) {
//			if (spt[j]->bday.daysBetween(spt[j + 1] ->bday) < 0) {
//				Student *temp = spt[j];
//				spt[j] = spt[j + 1];
//				spt[j + 1] = temp;
//			}
//		}
//	}
//}
//
//void student::display(Student *spt[]) {
//	cout << "Name			Student ID		Grade		Birthday			Home Town" << endl;
//	cout << "----			----------		-----		--------			---------" << endl;
//	for (int i = 0; i < size; i++) {
//		cout << setw(24) << left << spt[i]->name << setw(24) << left << spt[i]->ID << setw(15) << left << spt[i]->grade << setw(24);
//		spt[i]->bday.Display();
//		cout << spt[i]->homeTown << endl;
//
//	}
//}
//
//		