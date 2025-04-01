#pragma once
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;   // Maximum students per course
const int MAX_ASSIGNMENTS = 10; // Maximum assignments per course

class Course {
protected:
    string courseCode;
    string courseName;
    string teacherName;
    string classroom;
    string studentIDs[MAX_STUDENTS];      // Stores student IDs
    double grades[MAX_STUDENTS][MAX_ASSIGNMENTS]; // Stores grades for assignments
    int studentCount;                     // Number of students
    int assignmentCount;                   // Number of assignments

public:
    //default constructor
    Course();

    // Constructor
    Course(string code, string name, string teacher, string room);

    // Setters
    void setCourseCode(string code);
    void setCourseName(string name);
    void setTeacherName(string teacher);
    void setClassroom(string room);

    // Getters
    string getCourseCode() const;
    string getCourseName() const;
    string getTeacherName() const;
    string getClassroom() const;

    // Grade Management
    void addStudent(string studentID);
    void addGrade(string studentID, int assignmentIndex, double grade);
    double getGrade(string studentID, int assignmentIndex) const;
    double getAverageGrade(string studentID) const;
    double getCourseAverage() const;
    void displayGrades() const;
};
