#include "Student.h"

//constructor
Student::Student(int n, Info i, Attendance r) :numCourses(n), studentInfo(i), record(r) {}

//default constructor
Student::Student() {
	studentInfo.setName("jeff");
	studentInfo.setAge(0);
	studentInfo.setGender("helicopter");
	studentInfo.setAddress("wakanda");
	record.setDaysAttended(0);
	record.setDaysMissed(0);
}