#include "Course.h"
#include <iostream>

// Enter course details
void Course::enterCourseInfo() {
    std::cout << "Enter course name: ";
    std::getline(std::cin, name);
    std::cout << "Enter course code: ";
    std::getline(std::cin, code);
    std::cout << "Enter teacher name: ";
    std::getline(std::cin, teacher);
    std::cout << "Enter classroom: ";
    std::getline(std::cin, classroom);
}

// Enter grades for the course
void Course::enterGrades(int numAssignments) {
    grades.clear(); // Clear existing grades
    for (int i = 1; i <= numAssignments; i++) {
        Grade grade;
        grade.enterGrade(i);
        grades.push_back(grade);
    }
}

// Set attendance for the course
void Course::setAttendance(int totalDays, int attendedDays) {
    attendance.setAttendance(totalDays, attendedDays);
}

// Display course information
void Course::displayCourseInfo() const {
    std::cout << "Course: " << name << std::endl;
    std::cout << "Course Code: " << code << std::endl;
    std::cout << "Teacher Name: " << teacher << std::endl;
    std::cout << "Classroom: " << classroom << std::endl;
    std::cout << "Assignments:" << std::endl;

    // Display grades for each assignment
    for (const auto& grade : grades) {
        grade.displayGrade();
    }

    // Display attendance information
    attendance.displayAttendance();
}

// Calculate the average grade for the course
double Course::calculateAverage() const {
    double sum = 0;
    for (const auto& grade : grades) {
        sum += grade.getGrade();
    }
    return grades.empty() ? 0 : sum / grades.size();
}
