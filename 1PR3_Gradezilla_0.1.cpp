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
#include <algorithm> //added this header for transform function (handles Upper/lower case scenario)
#include <cctype> // for toupper header for transform function

using namespace std;

void showMainMenu();
void handleMainMenuChoice(char choice, Student& student);
void handleDataEntryMenu(Student& student);
void handleGradeEntryMenu(Student& student);
void handleDataViewMenu(Student& student);

int main() {
    cout << "**********************************WELCOME TO GRADEZILLA**********************************\n";

    // Creating a student object to store all data for one student
    Student student;

    Info tempInfo;

    bool done = false;
    char userChoice;

    while (!done) {
        showMainMenu();
        cin >> userChoice;
        userChoice = toupper(userChoice); // Convert input to uppercase for consistency

        if (userChoice == 'X') {
            done = true;
        }
        else {
            handleMainMenuChoice(userChoice, student);
        }
    }

    cout << "Exiting program. Goodbye!\n";
    return 0;
}

void showMainMenu() {
    cout << "\nHow may I help you?\n";
    cout << "HOME MENU" << endl;
    cout << "A: Enter Data\nB: View Data\nC: Enter Grades\nX: Exit program" << endl;
    cout << "Enter your choice: ";
}

void handleMainMenuChoice(char choice, Student& student) {
    if (choice == 'A') {
        handleDataEntryMenu(student);
    }
    else if (choice == 'B') {
        //cout << "View Data functionality coming soon!\n";
        handleDataViewMenu(student);
    }
    else if (choice == 'C') {
        handleGradeEntryMenu(student);
    }
    else {
        cout << "Invalid input! Please enter A, B, C, or X." << endl;
    }
}

void handleDataViewMenu(Student& student) {
    string user_in; //user input thingy
    cout << "\n*****VIEW DATA MENU*****" << endl;
    cout << "What data would you like to view?" << endl;
    cout << "A: Attendance\nB: Personal Info\nC: Course Info\nH: Return Home" << endl;
    cout << "Enter your choice: ";
    cin >> user_in;
    transform(user_in.begin(), user_in.end(), user_in.begin(), ::toupper);// this is to handle any lower/upper case scenario

    if (user_in == "A") {
        cout << "Displaying Attendance Records: " << endl;
        student.displayStudentAttendance();
    }
    if (user_in == "B") {
        cout << "Displaying Personal Info: " << endl;
        student.displayStudentInfo(); //call display student info function
    }
    if (user_in == "C") {
        cout << "View course data functionality coming soon!" << endl;
    }
    if (user_in == "H") {
        cout << "Returning to Home Menu..." << endl;
    }
}

void handleDataEntryMenu(Student& student) {
    char dataChoice;

    // Displaying menu to enter data
    cout << "***** ENTER DATA MENU *****\n";
    cout << "What would you like to enter data for?\n";
    cout << "A: Attendance\nB: Personal Info\nC: Course Info\nH: Return Home\n";
    cout << "Enter your choice: ";
    cin >> dataChoice;
    dataChoice = toupper(dataChoice);  // Convert choice to uppercase to handle case-insensitivity

    if (dataChoice == 'A') {
        int daysAttended;
        int daysMissed;
        //Attendance tempRecord;
        cout << "Enter total days attended: ";
        cin >> daysAttended;        //tempRecord.setDaysAttended(daysAttended);
        cout << "Enter total days missed: ";
        cin >> daysMissed;
        //student.setStudentAttendance().setDaysMissed(daysMissed); //set missed days across all courses (disabled cuz it dont work)
        //tempRecord.setDaysMissed(daysMissed);
        student.setStudentAttendance(Attendance(daysAttended, daysMissed));  // Set attendance across all courses

    }
    else if (dataChoice == 'B') {
        // Input student personal information
        string name, gender, address;
        int age;

        cout << "Enter your name: ";
        cin.ignore(); // To ignore the newline character left by previous input
        getline(cin, name);
        cout << "Enter your age: ";
        cin >> age;
        cout << "Enter your gender: ";
        cin.ignore(); // Ignore newline from age input
        getline(cin, gender);
        cout << "Enter your address: ";
        getline(cin, address);

        student.setStudentInfo(Info(name, age, gender, address));  // Set personal info
    }
    else if (dataChoice == 'C') {
        // Input course information
        string courseCode, courseName, teacherName, classroom;

        cout << "Enter course code: ";
        cin >> courseCode;
        cout << "Enter course name: ";
        cin.ignore();  // To ignore the newline character left by previous input
        getline(cin, courseName);
        cout << "Enter teacher name: ";
        getline(cin, teacherName);
        cout << "Enter classroom: ";
        getline(cin, classroom);

        Course course(courseCode, courseName, teacherName, classroom); // Create course object
        student.addCourse(course);  // Add course to student
    }
    else if (dataChoice == 'H') {
        cout << "Returning to Home Menu...\n";
    }
    else {
        cout << "Invalid input! Please enter A, B, C, or H." << endl;
    }
}

void handleGradeEntryMenu(Student& student) {
    // Check if the student has any courses
    if (student.getNumCourses() == 0) {
        cout << "No courses available for grade entry. Please enter course data first.\n";
        return;  // Return to main menu
    }

    // Call the updated `enterGrades()` method, which lets the user choose a course
    student.enterGrades();
}
