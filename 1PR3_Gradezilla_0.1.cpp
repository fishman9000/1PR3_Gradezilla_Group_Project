// 1PR3_Gradezilla_0.1.cpp
// Version notes (list your updates and changes here)
// 2025-3-18 (Fei Zhu)
// Created and made member variables, setters, getters for "Attendance" class
// Began loop implementation in "main" program (the main program loop runs until the user selects X, which sets done (a bool variable) = true; breaking the loop)
// Created "Grade" class, made member variables, setters, getters, constructor
// Created "Info" class for student's personal information, made member variables, setters, getters
// 2025-3-20 (check github logs)

#include <iostream>
#include <iomanip>
#include "Attendance.h"
#include "Student.h"
#include "Course.h"
#include "Info.h"
#include "Grade.h"
#include <algorithm> // Added this header for transform function (handles Upper/lower case scenario)
#include <cctype> // For toupper header for transform function

using namespace std;

// Function declarations
void showMainMenu();
void handleMainMenuChoice(char choice, Student& student);
void handleDataEntryMenu(Student& student);
void handleGradeEntryMenu(Student& student);
void handleDataViewMenu(Student& student);

int main() {
    cout << "**********************************WELCOME TO GRADEZILLA**********************************\n";

    // Creating a student object to store all data for one student
    Student student;
    bool done = false; // Loop control variable
    char userChoice;

    while (!done) {
        showMainMenu();
        cin >> userChoice;
        userChoice = toupper(userChoice); // Convert input to uppercase for consistency

        if (userChoice == 'X') {
            done = true; // Exiting the loop when 'X' is entered
        }
        else {
            handleMainMenuChoice(userChoice, student);
        }
    }

    cout << "Exiting program. Goodbye!\n";
    return 0;
}

// Displays the main menu options
void showMainMenu() {
    cout << "\nHow may I help you?\n";
    cout << "HOME MENU\n";
    cout << "A: Enter Data\nB: View Data\nC: Enter Grades\nX: Exit program\n";
    cout << "Enter your choice: ";
}

// Handles user choice from the main menu
void handleMainMenuChoice(char choice, Student& student) {
    switch (choice) {
    case 'A': handleDataEntryMenu(student); break;
    case 'B': handleDataViewMenu(student); break;
    case 'C': handleGradeEntryMenu(student); break;
    default:  cout << "Invalid input! Please enter A, B, C, or X.\n";
    }
}

// Handles viewing student data based on user selection
void handleDataViewMenu(Student& student) {
    string user_in;
    cout << "\n*****VIEW DATA MENU*****\n";
    cout << "What data would you like to view?\n";
    cout << "A: Attendance\nB: Personal Info\nC: Course Info\nH: Return Home\n";
    cout << "Enter your choice: ";
    cin >> user_in;
    transform(user_in.begin(), user_in.end(), user_in.begin(), ::toupper); // Convert to uppercase

    if (user_in == "A") {
        cout << "Displaying Attendance Records: \n";
        student.displayStudentAttendance();
    }
    else if (user_in == "B") {
        cout << "Displaying Personal Info: \n";
        student.displayStudentInfo();
    }
    else if (user_in == "C") {
        cout << "Course display functionality coming soon!\n"; // Placeholder for missing function
    }
    else if (user_in == "H") {
        cout << "Returning to Home Menu...\n";
    }
    else {
        cout << "Invalid input! Please enter A, B, C, or H.\n";
    }
}

// Handles data entry for attendance, personal info, and courses
void handleDataEntryMenu(Student& student) {
    char dataChoice;
    cout << "***** ENTER DATA MENU *****\n";
    cout << "What would you like to enter data for?\n";
    cout << "A: Attendance\nB: Personal Info\nC: Course Info\nH: Return Home\n";
    cout << "Enter your choice: ";
    cin >> dataChoice;
    dataChoice = toupper(dataChoice); // Convert to uppercase

    if (dataChoice == 'A') {
        int daysAttended, daysMissed;
        cout << "Enter total days attended: ";
        cin >> daysAttended;
        cout << "Enter total days missed: ";
        cin >> daysMissed;
        student.setStudentAttendance(Attendance(daysAttended, daysMissed));
        cout << "Attendance data updated successfully!\n";
    }
    else if (dataChoice == 'B') {
        string name, gender, address;
        int age;
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter your age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter your gender: ";
        getline(cin, gender);
        cout << "Enter your address: ";
        getline(cin, address);
        student.setStudentInfo(Info(name, age, gender, address));
        cout << "Personal information updated successfully!\n";
    }
    else if (dataChoice == 'C') {
        string courseCode, courseName, teacherName, classroom;
        cout << "Enter course code: ";
        cin >> courseCode;
        cin.ignore();
        cout << "Enter course name: ";
        getline(cin, courseName);
        cout << "Enter teacher name: ";
        getline(cin, teacherName);
        cout << "Enter classroom: ";
        getline(cin, classroom);
        student.addCourse(Course(courseCode, courseName, teacherName, classroom));
        cout << "Course added successfully!\n";
    }
    else if (dataChoice == 'H') {
        cout << "Returning to Home Menu...\n";
    }
    else {
        cout << "Invalid input! Please enter A, B, C, or H.\n";
    }
}

// Handles entering grades for student courses
void handleGradeEntryMenu(Student& student) {
    if (student.getNumCourses() == 0) {
        cout << "No courses available for grade entry. Please enter course data first.\n";
        return;
    }
    student.enterGrades(); // Calls the method to enter grades
}
