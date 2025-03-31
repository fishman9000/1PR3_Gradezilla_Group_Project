#pragma once
#include "Course.h"
#include "Info.h"
#include "Attendance.h"
class Student
{
private:
	//course data handling
	int numCourses; //number of courses (determines the size of the array, user inputs this through the main)
	static const int SIZE = 5; //this should be set to numCourses, but we'll leave it here for now for testing purposes
	//Course courseArray[SIZE]; //array of courses, disabled for now so I can do everything but the course stuff

	Course* courseArrayTest; //Testing Array with dynamically allocated memory


	//other private members
	Info studentInfo; //student info object to store their data and stuff
	Attendance record; //attendance record object to store their attendance record


public:

	//default constructor
	Student();

	//constructor
	Student(int n, Info i, Attendance r);

	//Test Constructor
	Student(int n, Info i, Attendance r);

	~Student(); // destructor for DAM

};

