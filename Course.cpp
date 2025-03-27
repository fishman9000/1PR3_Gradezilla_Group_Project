#include "Course.h"
#include <iostream>

using namespace std;

// Constructor
Course::Course(string code, string name, string teacher, string room)
    : courseCode(code), courseName(name), teacherName(teacher), classroom(room), studentCount(0), assignmentCount(0) {
    // Initialize grades array with -1 to indicate no grade assigned
    for (int i = 0; i < MAX_STUDENTS; i++) {
        for (int j = 0; j < MAX_ASSIGNMENTS; j++) {
            grades[i][j] = -1;
        }
    }
}

// Setters
void Course::setCourseCode(string code) { courseCode = code; }
void Course::setCourseName(string name) { courseName = name; }
void Course::setTeacherName(string teacher) { teacherName = teacher; }
void Course::setClassroom(string room) { classroom = room; }

// Getters
string Course::getCourseCode() const { return courseCode; }
string Course::getCourseName() const { return courseName; }
string Course::getTeacherName() const { return teacherName; }
string Course::getClassroom() const { return classroom; }

// Add a new student
void Course::addStudent(string studentID) {
    if (studentCount < MAX_STUDENTS) {
        studentIDs[studentCount] = studentID;
        studentCount++;
    }
    else {
        cout << "Error: Maximum student limit reached.\n";
    }
}

// Add or update a student's grade for a specific assignment
void Course::addGrade(string studentID, int assignmentIndex, double grade) {
    if (assignmentIndex >= MAX_ASSIGNMENTS) {
        cout << "Error: Assignment index out of range.\n";
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        if (studentIDs[i] == studentID) {
            grades[i][assignmentIndex] = grade;
            if (assignmentIndex >= assignmentCount) {
                assignmentCount = assignmentIndex + 1;
            }
            return;
        }
    }

    cout << "Error: Student not found.\n";
}

// Retrieve a student's grade for a specific assignment
double Course::getGrade(string studentID, int assignmentIndex) const {
    if (assignmentIndex >= MAX_ASSIGNMENTS) {
        return -1;
    }

    for (int i = 0; i < studentCount; i++) {
        if (studentIDs[i] == studentID) {
            return grades[i][assignmentIndex];
        }
    }
    return -1; // Student not found
}

// Calculate the average grade for a student
double Course::getAverageGrade(string studentID) const {
    for (int i = 0; i < studentCount; i++) {
        if (studentIDs[i] == studentID) {
            double total = 0;
            int count = 0;
            for (int j = 0; j < assignmentCount; j++) {
                if (grades[i][j] != -1) { // Only count valid grades
                    total += grades[i][j];
                    count++;
                }
            }
            return (count > 0) ? total / count : 0.0;
        }
    }
    return 0.0; // Student not found
}

// Calculate the class average across all students and assignments
double Course::getCourseAverage() const {
    if (studentCount == 0 || assignmentCount == 0) return 0.0;

    double total = 0;
    int count = 0;
    for (int i = 0; i < studentCount; i++) {
        for (int j = 0; j < assignmentCount; j++) {
            if (grades[i][j] != -1) {
                total += grades[i][j];
                count++;
            }
        }
    }
    return (count > 0) ? total / count : 0.0;
}

// Display all student grades
void Course::displayGrades() const {
    cout << "\nGrades for " << courseName << ":\n";
    cout << "Student ID\t";
    for (int j = 0; j < assignmentCount; j++) {
        cout << "Assignment " << j + 1 << "\t";
    }
    cout << endl;

    for (int i = 0; i < studentCount; i++) {
        cout << studentIDs[i] << "\t\t";
        for (int j = 0; j < assignmentCount; j++) {
            if (grades[i][j] == -1) {
                cout << "-\t\t";
            }
            else {
                cout << grades[i][j] << "\t\t";
            }
        }
        cout << endl;
    }
}
