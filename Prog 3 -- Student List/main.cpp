
#include "myDate.h"
#include <iostream>
#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

struct Student {
	char name[20];
	int ID;
	char grade;
	myDate bday;
	string homeTown;
};

int randomID();
char randomGrade();
myDate randomDate();
void sortByID(Student *spt[]);
void sortByName(Student *spt[]);
void sortByGrade(Student *spt[]);
void sortByBirthday(Student *spt[]);
void sortByHometown(Student *spt[]);
void display(Student *spt[]);
void populateStudents(Student arr[], int size);

int randomID() {
	int x = rand() % ((9999 - 1000) + 1) + 1000;
	return x;
}

char randomGrade() {
	char grade[] = { 'A', 'B', 'C', 'D', 'F' };
	char x = rand() % 5;
	return x;
}

//myDate student::randomDate() {
//	myDate min(1, 1, 1995);
//	myDate max(12, 31, 2000);
//	int x = min.daysBetween(max);
//	int d = rand() % x;
//	min.incrDate(x);
//	return min;
//}


void populateStudents(Student *arr, int size) {
	//string names[] = { "Spongebob Squarepants", "Bruce Wayne", "Clark Kent", "Crimson Chin", "Timmy Turner", "Fred Flinstone", "Mickey Mouse", "Scooby Doo", "Grinch", "Jimmy Neutron" };
	string hometown[] = { "Bikini Bottom", "Gotham City", "Smallville", "Chincinatti", "Dimmsdale", "Bedrock", "Mouseton", "Koolsville", "Whoville", "Retroville" };
	strcpy_s(arr[0].name, "Spongebob Squarepants");
	strcpy_s(arr[1].name, "Bruce Wayne");
	strcpy_s(arr[2].name, "Clark Kent");
	strcpy_s(arr[3].name, "Crimson Chin");
	strcpy_s(arr[4].name, "Timmy Turner");
	strcpy_s(arr[5].name, "Fred Flinstone");
	strcpy_s(arr[6].name, "Mickey Mouse");
	strcpy_s(arr[7].name, "Scooby Doo");
	strcpy_s(arr[8].name, "Grinch");
	strcpy_s(arr[9].name, "Jimmy Neutron");


	for (int i = 0; i < size; i++) {
		//Bday
		/*myDate min(1, 1, 1995);
		myDate max(12, 31, 2000);
		int x = min.daysBetween(max);
		int d = rand() % x;
		min.incrDate(x);
		arr[i].bday.setYear(min.getYear());
		arr[i].bday.setMonth(min.getMonth());
		arr[i].bday.setDay(min.getDay());*/
		arr[i].bday = myDate(rand() % 12, rand() % 31, rand() % (2000 - 1980 + 1) + 1980);

		arr[i].ID = randomID();
		arr[i].grade = randomGrade();
		arr[i].homeTown = hometown[i];
	}
}

//sorts ID
void sortByID(Student *spt[]) {
	int size = 10;
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (spt[j]->ID > spt[j + 1]->ID) {
				Student *temp = spt[j];
				spt[j] = spt[j + 1];
				spt[j + 1] = temp;
			}
		}
	}
}

//sorts names
void sortByName(Student *spt[]) {
	int size = 10;
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (strcmp(spt[j]->name, spt[j + 1]->name) > 0) {
				Student *temp = spt[j];
				spt[j] = spt[j + 1];
				spt[j + 1] = temp;
			}
		}
	}
}

//sort grade
void sortByGrade(Student *spt[]) {
	int size = 10;
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (spt[j]->grade > spt[j + 1]->grade) {
				Student *temp = spt[j];
				spt[j] = spt[j + 1];
				spt[j + 1] = temp;
			}
		}
	}
}

//sorts hometown
void sortByHometown(Student *spt[]) {
	int size = 10;
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (spt[j]->homeTown.compare(spt[j + 1]->homeTown) > 0) {
				Student *temp = spt[j];
				spt[j] = spt[j + 1];
				spt[j + 1] = temp;
			}
		}
	}
}

//sort by bday
void sortByBirthday(Student *spt[]) {
	int size = 10;
	for (int i = size - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (spt[j]->bday.daysBetween(spt[j + 1]->bday) < 0) {
				Student *temp = spt[j];
				spt[j] = spt[j + 1];
				spt[j + 1] = temp;
			}
		}
	}
}

void display(Student *spt[]) {
	int size = 10;
	cout << "Name			Student ID		Grade		Birthday			Home Town" << endl;
	cout << "----			----------		-----		--------			---------" << endl;
	for (int i = 0; i < size; i++) {
		cout << setw(24) << left << spt[i]->name << setw(24) << left << spt[i]->ID << setw(15) << left << spt[i]->grade << setw(24);
		spt[i]->bday.Display();
		cout << spt[i]->homeTown << endl;

	}
}



int main() {
	Student CECS282[10];
	populateStudents(CECS282, 10);
	Student *orig[10];
	Student *name[10];
	Student *ID[10];
	Student *grade[10];
	Student *bday[10];
	Student *home[10];
	for (int i = 0; i < 10; i++) {
		orig[i] = &CECS282[i];
		name[i] = &CECS282[i];
		ID[i] = &CECS282[i];
		grade[i] = &CECS282[i];
		bday[i] = &CECS282[i];
		home[i] = &CECS282[i];
	}
	int input = 0;
	
	while (true) {
		cout << "0) Display original list" << endl;
		cout << "1) Display list sorted by Name" << endl;
		cout << "2) Display list sorted by Student ID" << endl;
		cout << "3) Display list sorted by Grade" << endl;
		cout << "4) Display list sorted by Birthday" << endl;
		cout << "5) Display list sorted by Home Town" << endl;
		cout << "6) Exit" << endl;
		cin >> input;
		switch (input) {
		case 0:
			display(orig);
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4: 
			break; 
		case 5:
			break;
		case 6:
			cout << "Have a great day!!";
			system("pause");
			return 0;
			break;
		default:
			cout << "Invalid Input" << endl;
			break;
		}
	}

	getchar();
	system("pause");
	return 0;
}