#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() : studentID(""), name(""), courses(), personalInfo(), attendance() {}

Student::Student(string id, string n) : studentID(id), name(n), courses(), personalInfo(), attendance() {}

void Student::setStudentID(string id) {
    studentID = id;
}

void Student::setName(string n) {
    name = n;
}

string Student::getStudentID() const {
    return studentID;
}

string Student::getName() const {
    return name;
}

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

void Student::addCourse(const Course& c) {
    courses.push_back(c);  // Dynamically add a course to the vector
}

void Student::setStudentInfo(const Info& info) {
    personalInfo = info;  // Set the personal info for the student
}

Info Student::getStudentInfo() const {
    return personalInfo;  // Return the personal info of the student
}

Attendance& Student::getAttendanceRecord() {
    return attendance;  // Return a reference to the attendance record for the student
}

void Student::setAttendanceRecord(const Attendance& att) {
    attendance = att;  // Set the attendance record for the student
}

void Student::enterGrades() {
    for (int i = 0; i < courses.size(); i++) {
        courses[i].enterGradesForCourse();  // Call the function to input grades for each course
    }
}
