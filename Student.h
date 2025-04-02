#pragma once
#include <vector>
#include "Info.h"
#include "Course.h"

class Student {
private:
    Info studentInfo; // Student information
    std::vector<Course> courses; // List of courses the student is enrolled in

public:
    // Method to enter student info
    void enterStudentInfo();

    // Method to display student data
    void displayStudentData() const;

    // Method to enter courses for the student
    void enterCourses();

    // Method to display all course data
    void displayCoursesData() const;

    std::string getName() const { return studentInfo.getName(); } // FIXED: Added getter for student name
};
