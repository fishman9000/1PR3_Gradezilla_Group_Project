#include "Course.h"
using namespace std;

Course::Course(string code, string name, string teacher, string room)
    : courseCode(code), courseName(name), teacherName(teacher), classroom(room) {}

// Setters
void Course::setCourseCode(string code) {
    courseCode = code;
}

void Course::setCourseName(string name) {
    courseName = name;
}

void Course::setTeacherName(string teacher) {
    teacherName = teacher;
}

void Course::setClassroom(string room) {
    classroom = room;
}

//getters 



string Course::getCourseCode() const {
    return courseCode;
}

string Course::getCourseName() const {
    return courseName;
}

string Course::getTeacherName() const {
    return teacherName;
}

string Course::getClassroom() const {
    return classroom;
}



// Calculate the average grade
//DO THIS LATERRRRR