#include "Student.h"
#include "Course.h"
#include <iostream>
using namespace std;


//constructor with parameters definition
Student::Student(string id, string n, Info i, Attendance r) : studentID(id), name(n), courses(), studentInfo(i), record(r) {}

//default constructor definition
Student::Student() {
    setStudentID("");
    setName("");
    studentInfo.setAge(0);
    studentInfo.setGender("");
    studentInfo.setAddress("");
    record.setDaysAttended(0);
    record.setDaysMissed(0);
}

//setters
void Student::setStudentID(string id) {
    studentID = id;
}
void Student::setName(string n) {
    name = n;
}
void Student::setStudentInfo(const Info& info) {
    studentInfo = info;  // Set the personal info for the student
}
void Student::setStudentAttendance(const Attendance& att) {
    record = att;  // Set the attendance record for the student
}

//getters
string Student::getStudentID() const {
    return studentID;
}
string Student::getName() const {
    return name;
}
Info Student::getStudentInfo() const {
    return studentInfo;  // Return the personal info of the student
}
Attendance Student::getStudentAttendance() const {
    return record;  // Return a reference to the attendance record for the student
}
//course related getters
int Student::getNumCourses() const {
    return courses.size();  // Return number of courses using vector size
}
Course Student::getCourse(int index) const {
    if (index >= 0 && index < courses.size()) {
        return courses[index];  // Return the course at the given index
    }
    // If invalid index, return a default Course object
    return Course();
}

//other function definitions
void Student::addCourse(const Course& c) {
    courses.push_back(c);  // Dynamically add a course to the vector
}
void Student::enterGrades() {
    if (courses.size() == 0) {
        cout << "No courses available. Please add a course first." << endl;
        return;
    }

    cout << "Please select a course to enter grades:\n";
    for (int i = 0; i < courses.size(); i++) {
        cout << i + 1 << ". " << courses[i].getCourseName() << endl;
    }

    int courseChoice;
    cout << "Enter the number of the course you want to enter grades for: ";
    cin >> courseChoice;

    // Ensure the input is valid
    if (courseChoice < 1 || courseChoice > courses.size()) {
        cout << "Invalid course number!" << endl;
        return;
    }

    // Get the selected course
    Course& selectedCourse = courses[courseChoice - 1];  // Adjusting for 0-based indexing

    int numAssignments;
    cout << "Enter number of assignments for " << selectedCourse.getCourseName() << ": ";
    cin >> numAssignments;

    // Loop through the assignments and ask for grades and weights
    for (int i = 0; i < numAssignments; i++) {
        string assignmentName;
        double grade, weight;

        cout << "Enter assignment " << i + 1 << " name: ";
        cin.ignore();  // Ignore leftover newline
        getline(cin, assignmentName);

        cout << "Enter grade for " << assignmentName << ": ";
        cin >> grade;

        // Validate grade input
        if (grade < 0 || grade > 100) {
            cout << "Invalid grade! Please enter a value between 0 and 100." << endl;
            i--;  // Decrement to re-enter the grade for this assignment
            continue;
        }

        cout << "Enter weight for " << assignmentName << " (as a percentage): ";
        cin >> weight;

        // Validate weight input
        if (weight < 0 || weight > 100) {
            cout << "Invalid weight! Please enter a value between 0 and 100." << endl;
            i--;  // Decrement to re-enter the weight for this assignment
            continue;
        }

        // Create a grade object and add it to the course
        Grade newGrade(assignmentName, grade, weight);
        selectedCourse.addAssignment(newGrade);
    }
}
//display student info
void Student::displayStudentInfo() const {
    studentInfo.displayInfo();
}
//display student attendance
void Student::displayStudentAttendance() const {
    record.displayAttendance();
}

