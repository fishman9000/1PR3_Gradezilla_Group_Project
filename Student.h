#pragma once
#include <string>
#include "Attendance.h"
#include "Course.h"
#include "Info.h"
#include <vector>  // Include vector header

class Student {
protected:
    string studentID;               // Stores student ID
    string name;                    // Stores student name
    Attendance record;          // Stores attendance record
    std::vector<Course> courses;    // Vector to store courses (dynamic)
    Info studentInfo;              // The personal info of the student

public:
    Student(); // Default constructor
    Student(string id, string n, Info i, Attendance r); //constructor with parameters for id, name, student info, and attendance

    //~Student(); // destructor for DAM

    // Setters
    void setStudentID(string id);
    void setName(string n);
    void setStudentInfo(const Info& info);
    void setStudentAttendance(const Attendance& att);

    // Getters
    string getStudentID() const;
    string getName() const;
    int getNumCourses() const;
    Course getCourse(int index) const;
    Info getStudentInfo() const;
    Attendance getStudentAttendance() const;  // Returns reference to the Attendance object

    // Method to add course
    void addCourse(const Course& c);

    // Method to enter grades for each course
    void enterGrades();

    //display student info function
    void displayStudentInfo() const;

    //display attendance function
    void displayStudentAttendance() const;
};
