#pragma once
#include<iostream>
#include<string>
#include"degree.h"
using namespace std;
//define the student class
class student
{
	//define all the private variables
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;
public:
	//define the constructor to set value when object is created
	student();
	student(string studentId_, string firstName_, string lastName_, string emailAddress_, int age_, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram_);
	//define all the getter and setter method
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	DegreeProgram getDegreeProgram();
	int getAge();
	int* getNumberOfDays();

	void setStudentId(string studentId_);
	void setFirstName(string firstName_);
	void setLastName(string lastName_);
	void setEmailAddress(string emailAddress_);
	void setDegreeProgram(DegreeProgram degreeProgram_);
	void setAge(int age_);
	void setNumberOfDays(int daysInCourse1, int daysInCourse2, int daysInCourse3);

	//define the print method
	void print();
	
};

