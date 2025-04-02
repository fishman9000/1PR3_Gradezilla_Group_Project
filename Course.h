#pragma once
#include <string>
#include <vector>
#include "Grade.h"
#include "Attendance.h"

class Course {
private:
    std::string name;
    std::string code;
    std::string teacher;
    std::string classroom;
    std::vector<Grade> grades;
    Attendance attendance;

public:
    // Methods for course details
    void enterCourseInfo();

    // Enter grades for assignments
    void enterGrades(int numAssignments);

    // Set attendance for the course
    void setAttendance(int totalDays, int attendedDays);

    // Display course information
    void displayCourseInfo() const;

    // Calculate average grade for the course
    double calculateAverage() const;
};
