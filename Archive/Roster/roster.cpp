#include "roster.h"

roster::roster(string studentData[])
{
	//craeate the student data
	
	size = 5;
	classRosterArray = new student[5];//initilize array 
	//itereate over the stdent data and store it in roster array
	for (int i = 0; i < 5; i++)
	{
		string temp = studentData[i];
		stringstream ss(temp);
		string word;
		int course1, course2, course3;
		//split the string using the ',' seperator and set correct value for the student array
		getline(ss, word, ',');
		classRosterArray[i].setStudentId(word);
		getline(ss, word, ',');
		classRosterArray[i].setFirstName(word);
		getline(ss, word, ',');
		classRosterArray[i].setLastName(word);
		getline(ss, word, ',');
		classRosterArray[i].setEmailAddress(word);
		getline(ss, word, ',');
		classRosterArray[i].setAge(stoi(word));
		
		getline(ss, word, ',');
		course1 = stoi(word);
		getline(ss, word, ',');
		course2 = stoi(word);
		getline(ss, word, ',');
		course3 = stoi(word);

		classRosterArray[i].setNumberOfDays(course1, course2, course3);

		getline(ss, word, ',');
		//set degree program according to the value
		if (word.compare("SECURITY") == 0)
			classRosterArray[i].setDegreeProgram(DegreeProgram::SECURITY);
		else if (word.compare("NETWORK") == 0)
			classRosterArray[i].setDegreeProgram(DegreeProgram::NETWORK);
		else 
			classRosterArray[i].setDegreeProgram(DegreeProgram::SOFTWARE);
	}

}
//destructor
roster::~roster()
{
	delete[] classRosterArray;//deallocate all the allocated memory
}
//function to add student to the list
void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{	
	//copy all the old value in the temporary variable
	student* newData = new student[size+1];
	for (int i = 0; i < size; i++)//iterate over the student data
	{	
			newData[i] = classRosterArray[i];
	}
	//add new values
	newData[size].setStudentId(studentID);
	newData[size].setFirstName(firstName);
	newData[size].setLastName(lastName);
	newData[size].setEmailAddress(emailAddress);
	newData[size].setAge(age);
	newData[size].setNumberOfDays(daysInCourse1,daysInCourse2,daysInCourse3);
	newData[size].setDegreeProgram(degreeprogram);
	//set temporary variable to class roster array
	student* temp = classRosterArray;
	temp = NULL;
	delete temp;
	classRosterArray = newData;
	size++;
}
//function to remove student from the list
void roster::remove(string studentID)
{
	bool flag = false;
	//check if studentId is present in the array
	for (int i = 0; i < size; i++)//iterate over the student data
	{
		if (classRosterArray[i].getStudentId().compare(studentID) == 0) {
			flag = true;
			break;
		}
	}
	//if student id is present in the array
	if (flag == true)
	{
		int index = 0;
		
		student* newData = new student[size];
		for (int i = 0; i < size; i++)//iterate over the student data
		{
			if (classRosterArray[i].getStudentId().compare(studentID) != 0) {
				newData[index] = classRosterArray[i];
				index++;
			}
		}
		size--;
		student* temp = classRosterArray;
		temp = NULL;
		delete temp;
		classRosterArray = newData;
	}
	else
	{
		cout << "student with " << studentID << " ID was not found.";
	}
}
//function to print all the student
void roster::printAll()
{
	cout << "Printing all Student Details\n";
	for (int i = 0; i < size; i++)
	{
		classRosterArray[i].print();
	}
}
//function to print average days in course
void roster::printAverageDaysInCourse(string studentID)
{
	int sum = 0;
	for (int i = 0; i < size; i++)//iterate over the student data
	{
		if (classRosterArray[i].getStudentId().compare(studentID) == 0) {
			int* temp = classRosterArray[i].getNumberOfDays();//get all the number of days
			sum += temp[0] + temp[1] + temp[2];
			temp = NULL;
			delete temp;
		}
	}
	cout << "Average Days in course: " << sum / (3.0 ) << endl;//calculate and print average
}
//function to print invalid emails
void roster::printInvalidEmails()
{
	bool flag = true;
	cout << "Invalid email list is : " << endl;

	for (int i = 0; i < size; i++)//iterate over the student data
	{
		
		int spaceCount = 0;
		int specialcount = 0;
		int periodCount = 0;

		string temp = classRosterArray[i].getEmailAddress();
		for (int j = 0; j < temp.length(); j++)//iterate over the email address
		{
			if (temp[j] == ' ')//if email address contain space
				spaceCount += 1;
			if (temp[j] == '@')//if email addres conai @
				specialcount += 1;
			if (temp[j] == '.')//if email address contain .
				periodCount += 1;
		}
		if (spaceCount > 0 || specialcount == 0 || periodCount == 0)//if any codition is true
		{
			cout << temp << endl;
			flag = false;
		}
	}
	if (flag == true)
		cout << "No invalid email found" << endl;
}
//print to print student with given degree program
void roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	cout << "Student by degree program" << endl;
	for (int i = 0; i < size; i++)//iterate over the student data
	{
		if (classRosterArray[i].getDegreeProgram() == degreeProgram)//if it is the given degree program
		{
			classRosterArray[i].print();//print the student details
		}
	}
}

student* roster::getRosterArray()
{
	return classRosterArray;
}

int roster::getSize()
{
	return size;
}
