#include "Student.h"
#include "Course.h"
//constructor
Student::Student(int n, Info i, Attendance r) :numCourses(n), studentInfo(i), record(r) {
	courseArrayTest = new Course[numCourses]; // Dynamically allocate array
}

//default constructor
Student::Student() {
	studentInfo.setName("");
	studentInfo.setAge(0);
	studentInfo.setGender("");
	studentInfo.setAddress("");
	record.setDaysAttended(0);
	record.setDaysMissed(0);
}

Student::~Student() {
	delete[] courseArrayTest;
}

//setter and getter for student personal info
void Student::setStudentInfo(Info i) {
	studentInfo = i;
}
Info Student::getStudentInfo() const {
	return studentInfo;
}

//setter and getter for student attendance record
void Student::setStudentAttendance(Attendance a) {
	record = a;
}
Attendance Student::getStudentAttendance() const {
	return record;
}



//display student info
void Student::displayStudentInfo() const {
	studentInfo.displayInfo();
}

void Student::displayStudentAttendance() const {
	record.displayAttendance();
}
