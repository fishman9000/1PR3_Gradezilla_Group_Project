#include "Student.h"

//constructor
Student::Student(int n, Info i, Attendance r) {
	numCourses = n;
	studentInfo = i;
	record = r;




Student::Student(int m , Info i, Attendence r) : numCourses(n), studentInfo(i), record(r) {
    courseArrayTest = new Course[numCourses]; // Dynamically allocate array
}

Student::~Student(){
	delete[] courseArrayTest;
}
