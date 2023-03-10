#pragma once
#include"student.h"
#include"degree.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
class roster
{
	student* classRosterArray;
	int size;
public:
	roster(string studentData[]);
	~roster();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	student* getRosterArray();
	int getSize();
	
};

