#pragma once
#include <string>
#include "Attendance.h"
#include "Course.h"
#include "Info.h"
#include <vector>  // Include vector header

class Student {
private:
    string studentID;               // Stores student ID
    string name;                    // Stores student name
    Attendance attendance;          // Stores attendance record
    std::vector<Course> courses;    // Vector to store courses (dynamic)
    Info personalInfo;              // The personal info of the student

public:
    Student();                      // Default constructor
    Student(string id, string n);   // Constructor with student ID and name

    // Setters
    void setStudentID(string id);
    void setName(string n);
    void setStudentInfo(const Info& info);
    void setAttendanceRecord(const Attendance& att);

    // Getters
    string getStudentID() const;
    string getName() const;
    int getNumCourses() const;
    Course getCourse(int index) const;
    Info getStudentInfo() const;
    Attendance& getAttendanceRecord();  // Returns reference to the Attendance object

    // Method to add course
    void addCourse(const Course& c);

    // Method to enter grades for each course
    void enterGrades();
};
