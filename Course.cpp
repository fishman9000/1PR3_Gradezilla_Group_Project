#include "Course.h"

Course::Course(std::string code, std::string name, std::string teacher, std::string room)
    : courseCode(code), courseName(name), teacherName(teacher), classroom(room) {}

// Setters
void Course::setCourseCode(std::string code) {
    courseCode = code;
}

void Course::setCourseName(std::string name) {
    courseName = name;
}

void Course::setTeacherName(std::string teacher) {
    teacherName = teacher;
}

void Course::setClassroom(std::string room) {
    classroom = room;
}

//getters 

string Course::getCourseCode() const {
    return courseCode; 
}

string Course::getCourseName() const {
    return courseName; 
}


