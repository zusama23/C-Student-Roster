#include "student.h"

student::student()
{
}

//implement every function of student class
student::student(string studentId_, string firstName_, string lastName_, string emailAddress_, int age_, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram_)
{
	studentId = studentId_;
	firstName = firstName_;
	lastName = lastName_;
	emailAddress = emailAddress_;
	age = age_;
	degreeProgram = degreeProgram_;
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;
}

string student::getStudentId()
{
	return studentId;
}

string student::getFirstName()
{
	return firstName;
}

string student::getLastName()
{
	return lastName;
}

string student::getEmailAddress()
{
	return emailAddress;
}

DegreeProgram student::getDegreeProgram()
{
	return degreeProgram;
}

int student::getAge()
{
	return age;
}

int* student::getNumberOfDays()
{
	return daysInCourse;
}

void student::setStudentId(string studentId_)
{
	studentId = studentId_;
}

void student::setFirstName(string firstName_)
{
	firstName = firstName_;
}

void student::setLastName(string lastName_)
{
	lastName = lastName_;
}

void student::setEmailAddress(string emailAddress_)
{
	emailAddress = emailAddress_;
}

void student::setDegreeProgram(DegreeProgram degreeProgram_)
{
	degreeProgram = degreeProgram_;
}

void student::setAge(int age_)
{
	age = age_;
}

void student::setNumberOfDays(int daysInCourse1, int daysInCourse2, int daysInCourse3)
{
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;
}

void student::print()
{
	//print all the details to the console
	cout << studentId << "\t First Name: " << firstName << " \t Last Name: " << lastName << " \t Age: " << age << " \t daysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "} Degree Program: " ;
	if (degreeProgram == DegreeProgram::NETWORK)
		cout << "NETWORK";
	else if (degreeProgram == DegreeProgram::SECURITY)
		cout << "SECURITY";
	else
		cout << "SOFTWAER";
	cout << endl;
}
