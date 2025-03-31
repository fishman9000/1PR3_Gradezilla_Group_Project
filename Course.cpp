#include "Course.h"
#include "Grade.h"
#include <iostream>
using namespace std;

// Default constructor
Course::Course() : courseCode(""), courseName(""), teacherName(""), classroom(""), numAssignments(0) {}

// Constructor with course details
Course::Course(string code, string name, string teacher, string room)
    : courseCode(code), courseName(name), teacherName(teacher), classroom(room), numAssignments(0) {}

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

// Getters
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

int Course::getNumAssignments() const {
    return numAssignments;
}

// Add a student to the course
void Course::addStudent(string studentID) {
    studentIDs.push_back(studentID);  // Dynamically add students
    grades.push_back(vector<Grade>()); // Initialize an empty vector of grades for each student
}

// Add an assignment to the course
void Course::addAssignment(const Grade& grade) {
    // Removed the limit check if we don't need it
    // if (numAssignments < MAX_ASSIGNMENTS) {
    for (int i = 0; i < studentIDs.size(); i++) {
        grades[i].push_back(grade);  // Add grade to student's list
    }
    numAssignments++;  // Increment the assignment count
    // }
}


// Add a grade for a specific student
void Course::addGradeForStudent(int studentIndex, const Grade& grade) {
    if (studentIndex >= 0 && studentIndex < studentIDs.size()) {
        grades[studentIndex].push_back(grade);  // Add the grade dynamically
    }
    else {
        cout << "Error: Invalid student index.\n";
    }
}


double Course::calculateCourseAverage() const {
    double totalGrade = 0.0;
    double totalWeight = 0.0;

    // Loop through each student's grades for all assignments
    for (int i = 0; i < studentIDs.size(); i++) {
        double studentTotalGrade = 0.0;
        double studentTotalWeight = 0.0;

        // Loop through each assignment
        for (int j = 0; j < numAssignments; j++) {
            double grade = grades[i][j].getGrade();  // Get grade for this assignment
            double weight = grades[i][j].getWeight();  // Get weight for this assignment

            studentTotalGrade += grade * (weight / 100);  // Add weighted grade
            studentTotalWeight += weight;  // Add weight for this assignment
        }

        // Only include students with grades
        if (studentTotalWeight > 0) {
            totalGrade += studentTotalGrade;
            totalWeight += studentTotalWeight;
        }
    }

    // Debugging output
    cout << "Total grade: " << totalGrade << ", Total weight: " << totalWeight << endl;

    // Return the overall average for the course
    if (totalWeight > 0) {
        return totalGrade / totalWeight;  // No need to divide by 100 here
    }

    return 0.0;  // Return 0 if no valid grades are available
}


// Function to handle user input for entering grades for the course
void Course::enterGradesForCourse() {
    for (int i = 0; i < studentIDs.size(); i++) {
        cout << "Enter grades for student " << studentIDs[i] << ":\n";
        for (int j = 0; j < numAssignments; j++) {
            double grade;
            double weight;

            cout << "Assignment " << j + 1 << " - Enter grade: ";
            cin >> grade;
            cout << "Enter weight of assignment (in %): ";
            cin >> weight;

            Grade newGrade(to_string(j + 1), grade, weight);  // Create Grade object for this assignment
            addGradeForStudent(i, newGrade);  // Add the grade for the student
            // Debugging output
            cout << "Added grade: " << grade << ", weight: " << weight << endl;
        }
    }
}
