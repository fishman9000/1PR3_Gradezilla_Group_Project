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

void Student::setStudentInfo(Info i) {
	studentInfo = i;
}
Info Student::getStudentInfo() const {
	return studentInfo;
}

//display student info
void Student::displayStudentInfo() const {
	studentInfo.displayInfo();
}
