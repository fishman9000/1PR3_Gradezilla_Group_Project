// 1PR3_Gradezilla_0.1.cpp
// Version notes (list your updates and changes here)
// 2025-3-18 (Fei Zhu)
// Created and made member variables, setters, getters for "Attendance" class
// Began loop implementation in "main" program (the main program loop runs until the user selects X, which sets done (a bool variable) = true; breaking the loop)
// Created "Grade" class, made member variables, setters, getters, constructor
// Created "Info" class for student's personal information, made member variables, setters, getters
// 2025-3-20 (check github logs)

#include <iostream>
#include "Attendance.h"
#include "Student.h"
#include "Course.h"
#include "Info.h"
#include "Grade.h"

using namespace std;

void showMainMenu();
void handleMainMenuChoice(char choice, Student& student);
void handleDataEntryMenu(Student& student);
void handleGradeEntryMenu(Student& student);

int main() {
    cout << "**********************************WELCOME TO GRADEZILLA**********************************\n";

    // Creating a student object to store all data for one student
    Student student;

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
        cout << "View Data functionality coming soon!\n";
    }
    else if (choice == 'C') {
        handleGradeEntryMenu(student);
    }
    else {
        cout << "Invalid input! Please enter A, B, C, or X." << endl;
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
        cout << "Enter total days attended: ";
        cin >> daysAttended;
        student.getAttendanceRecord().setDaysAttended(daysAttended);  // Set attendance across all courses
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
    bool done = false;

    // Check if the student has any courses
    if (student.getNumCourses() == 0) {
        cout << "No courses available for grade entry. Please enter course data first.\n";
        return;  // Return to main menu or elsewhere if no courses are present
    }

    // Loop through all courses the student is enrolled in
    for (int i = 0; i < student.getNumCourses(); i++) {
        cout << "Enter grades for course: " << student.getCourse(i).getCourseName() << endl;
        int numAssignments;
        cout << "How many assignments for this course? ";
        cin >> numAssignments;

        // Loop through assignments and ask for grades and weights
        for (int j = 0; j < numAssignments; j++) {
            string assignmentName;
            double grade, weight;

            cout << "Enter assignment " << j + 1 << " name: ";
            cin.ignore();  // Ignore leftover newline
            getline(cin, assignmentName);
            cout << "Enter grade for " << assignmentName << ": ";
            cin >> grade;
            cout << "Enter weight for " << assignmentName << " (as a percentage): ";
            cin >> weight;

            // Create grade object and add it to course
            Grade newGrade(assignmentName, grade, weight);
            student.getCourse(i).addAssignment(newGrade);  // Add the grade to the course
        }

        // Calculate and display the average grade for this course
        double averageGrade = student.getCourse(i).calculateCourseAverage();
        cout << "Average grade for " << student.getCourse(i).getCourseName() << ": " << averageGrade << "%" << endl;
    }

    // Ask if the user wants to go back to the menu
    char returnChoice;
    cout << "\nWould you like to return to the main menu? (Y/N): ";
    cin >> returnChoice;
    returnChoice = toupper(returnChoice);

    if (returnChoice == 'Y') {
        done = true;  // End the loop and go back to the main menu
    }
    else {
        // Optionally, you can implement code to allow the user to continue entering grades for other courses.
        // For now, we will just return to the main menu directly when they press 'Y'.
    }
}