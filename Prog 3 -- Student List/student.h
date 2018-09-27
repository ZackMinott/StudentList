#ifndef Student_
#define Student_

#include "myDate.h"
#include <string>
using namespace std;

struct Student {
	char name[20];
	int ID;
	char grade;
	myDate bday;
	string homeTown;
};

class student {
private:
	int size = 10;
public:
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
};
#endif
