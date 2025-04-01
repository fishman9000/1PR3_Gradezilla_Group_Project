#pragma once
#include <string>
#include <vector>
#include "Grade.h"

using namespace std;

const int MAX_STUDENTS = 100;   // Maximum students per course
const int MAX_ASSIGNMENTS = 10; // Maximum assignments per course

class Course {
private:
    string courseCode;
    string courseName;
    string teacherName;
    string classroom;
    vector<string> studentIDs;  // Dynamically sized vector for student IDs
    vector<vector<Grade>> grades;  // Dynamically sized 2D vector for storing grades
    int numAssignments;  // Tracks number of assignments added

public:
    Course();  // Default constructor
    Course(string code, string name, string teacher, string room);

    // Setters
    void setCourseCode(string code);
    void setCourseName(string name);
    void setTeacherName(string teacher);
    void setClassroom(string room);
    void addAssignment(const Grade& grade);

    // Getters
    string getCourseCode() const;
    string getCourseName() const;
    string getTeacherName() const;
    string getClassroom() const;
    int getNumAssignments() const;

    // Methods to manage students
    void addStudent(string studentID);
    void addGradeForStudent(int studentIndex, const Grade& grade);
    void enterGradesForCourse();

    // Calculate course average
    double calculateCourseAverage() const;
};
