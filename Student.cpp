#include "Student.h"
#include "Course.h"
#include <iostream>
using namespace std;


//constructor with parameters definition
Student::Student(string id, string n, Info i, Attendance r) : studentID(id), name(n), courses(), studentInfo(i), record(r) {}

//default constructor definition
Student::Student() {
    setStudentID("");
    setName("");
    studentInfo.setAge(0);
    studentInfo.setGender("");
    studentInfo.setAddress("");
    record.setDaysAttended(0);
    record.setDaysMissed(0);
}

//setters
void Student::setStudentID(string id) {
    studentID = id;
}
void Student::setName(string n) {
    name = n;
}
void Student::setStudentInfo(const Info& info) {
    studentInfo = info;  // Set the personal info for the student
}
void Student::setStudentAttendance(const Attendance& att) {
    record = att;  // Set the attendance record for the student
}

//getters
string Student::getStudentID() const {
    return studentID;
}
string Student::getName() const {
    return name;
}
Info Student::getStudentInfo() const {
    return studentInfo;  // Return the personal info of the student
}
Attendance Student::getStudentAttendance() const {
    return record;  // Return a reference to the attendance record for the student
}
//course related getters
int Student::getNumCourses() const {
    return courses.size();  // Return number of courses using vector size
}
Course Student::getCourse(int index) const {
    if (index >= 0 && index < courses.size()) {
        return courses[index];  // Return the course at the given index
    }
    // If invalid index, return a default Course object
    return Course();
}

//other function definitions
void Student::addCourse(const Course& c) {
    courses.push_back(c);  // Dynamically add a course to the vector
}
void Student::enterGrades() {
    for (int i = 0; i < courses.size(); i++) {
        courses[i].enterGradesForCourse();  // Call the function to input grades for each course
    }
}
//display student info
void Student::displayStudentInfo() const {
    studentInfo.displayInfo();
}
//display student attendance
void Student::displayStudentAttendance() const {
    record.displayAttendance();
}
