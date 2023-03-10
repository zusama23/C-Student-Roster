#include <iostream>
#include<string>
#include"degree.h"
#include"roster.h"
#include"student.h"

using namespace std;
int main()
{
    int choice;
    string degreeProgram;
    string id;
    string fName, lName, email;
    int age;
    int daysInCourse1, daysInCourse2, daysInCourse3;
    student* temp;

    string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Usama,Zafar,zusama23@gmail.com,25,30,10,10,SOFTWARE"
    };

    cout << "Course Title: C867" << endl;
    cout << "Programming Language Used: CPP " << endl;
    cout << "Student Id: 001379822" << endl;
    cout << "Student Name: Usama Zafar" << endl;
    cout << endl;
    cout << endl;

    roster classRoster(studentData);

    while (true)//repeat until user does not exit
    {
        cout << "1. Add" << endl;
        cout << "2. Remove" << endl;
        cout << "3. Print all" << endl;
        cout << "4. Print average days in rows" << endl;
        cout << "5. Print Invalid emails" << endl;
        cout << "6. Print by degree program" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your chocie: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
          
            cout << "Enter Student Id: ";
            cin >> id;
            cout << "Enter First Name: ";
            cin >> fName;
            cout << "Enter Last Name: ";
            cin >> lName;
            cout << "Enter Email Address: ";
            cin >> email;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter Days in course 1: ";
            cin >> daysInCourse1;
            cout << "Enter Days in course 2: ";
            cin >> daysInCourse2;
            cout << "Enter Days in course 3: ";
            cin >> daysInCourse3;
            cout << "Enter Degree program: ";
            cin >> degreeProgram;
            if (degreeProgram.compare("SOFTWARE") == 0)
                classRoster.add(id,fName,lName,email,daysInCourse1, age,daysInCourse2,daysInCourse3,DegreeProgram::SOFTWARE);
            else if (degreeProgram.compare("NETWORK") == 0)
                classRoster.add(id, fName, lName, email, daysInCourse1, age, daysInCourse2, daysInCourse3, DegreeProgram::NETWORK);
            else if (degreeProgram.compare("SECURITY") == 0)
                classRoster.add(id, fName, lName, email, daysInCourse1, age, daysInCourse2, daysInCourse3, DegreeProgram::SECURITY);
            break;

        case 2:
            cout << "Enter Student Id: ";
            cin >> id;
            classRoster.remove(id);
            cout << endl;
            break;
        case 3:
            classRoster.printAll();
            cout << endl;
            break;
        case 4:
            //loop through classRosterArray and for each element:
            temp = classRoster.getRosterArray();
            for (int i = 0; i < classRoster.getSize(); i++)
            {
                classRoster.printAverageDaysInCourse(temp[i].getStudentId());
            }
            
            cout << endl;
            break;
        case 5:
            classRoster.printInvalidEmails();
            cout << endl;
            break;
        case 6:
            cout << "Enter Degree program: ";
            cin >> degreeProgram;
            if (degreeProgram.compare("SOFTWARE") == 0)
                classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
            else if (degreeProgram.compare("NETWORK") == 0)
                classRoster.printByDegreeProgram(DegreeProgram::NETWORK);
            else if (degreeProgram.compare("SECURITY") == 0)
                classRoster.printByDegreeProgram(DegreeProgram::SECURITY);
            else
                cout << "Wrong Degree Program selected";            
            cout << endl;
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "Wrong Choice!!! Try again...";
            break;
        }
        cout << endl;
    }
    temp = NULL;
    delete temp;
    
    
   
   
    
}
