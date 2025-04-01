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

int main() {
    cout << "**********************************WELCOME TO GRADEZILLA**********************************\n";

    // Creating a student object to store all data for one student
    Student student;

    //temporary info object used as a middleman to write data to the "student" object
    Info tempInfo;
    Attendance tempRecord;

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


///fei's code inside main

string user_in; //user input variable (make sure to validate the input so if the user doesn't enter one of the menu options, it does the loop again)
while (!done) { //this loop runs over and over again as long as the user doesn't end the program
    cout << "\nHow may I help you?" << endl; //help prompt
    cout << "HOME MENU" << endl;
    cout << "A: Enter Data\nB: View Data \nX: Exit program. " << endl; //have default constructor for everything so that if there's no data,it can be like "no data entered"
    cin >> user_in; //take user input
    transform(user_in.begin(), user_in.end(), user_in.begin(), ::toupper);// this is to handle any lower/upper case scenario

    if (user_in == "A") {
        cout << "\n*****ENTER DATA MENU*****" << endl;
        cout << "What would you like to enter data for?" << endl;
        cout << "A: Attendance\nB: Personal Info\nC: Course Info\nH: Return Home" << endl;
        cin >> user_in;
        transform(user_in.begin(), user_in.end(), user_in.begin(), ::toupper);// this is to handle any lower/upper case scenario

        if (user_in == "A") {
            cout << "Enter Attendance Info Selected." << endl;
            int tmp1;
            cout << "Please enter days of class attended: ";
            cin >> tmp1;
            tempRecord.setDaysAttended(tmp1);
            cout << "Please enter days of class missed: ";
            cin >> tmp1;
            tempRecord.setDaysMissed(tmp1);
            currentStudent.setStudentAttendance(tempRecord);
        }
        if (user_in == "B") {
            string tmp;
            int tmpage; //an int temporary value, specifically for the age
            cout << "Enter Personal Info Selected." << endl;
            cout << "Please enter your name: ";
            cin.ignore(); //ignore leftover line from previous input
            getline(cin, tmp); //use getline to get user input (using cin >> tmp would not work if input contained spaces)
            tempInfo.setName(tmp);
            cout << "Please enter your age: ";
            cin >> tmpage; //cin works here because age won't have spaces
            tempInfo.setAge(tmpage);
            cout << "Please enter your gender: ";
            cin.ignore();
            getline(cin, tmp);
            tempInfo.setGender(tmp);
            cout << "Please enter your address: ";
            cin.ignore();
            getline(cin, tmp);
            tempInfo.setAddress(tmp);
            currentStudent.setStudentInfo(tempInfo);
            cout << "Data entered successfully." << endl;
        }
        if (user_in == "C") {
            cout << "choose course" << endl;
        }
        if (user_in == "H") {
            cout << "Returning to Home Menu." << endl;
        }
    }
    else if (user_in == "B") {
        cout << "\n*****VIEW DATA MENU*****" << endl;
        cout << "What data would you like to view?" << endl;
        cout << "A: Attendance\nB: Personal Info\nC: Course Info\nH: Return Home" << endl;
        cin >> user_in;
        transform(user_in.begin(), user_in.end(), user_in.begin(), ::toupper);// this is to handle any lower/upper case scenario

        if (user_in == "A") {
            cout << "Displaying Attendance Records: " << endl;
            currentStudent.displayStudentAttendance();
        }
        if (user_in == "B") {
            cout << "Displaying Personal Info: " << endl;
            currentStudent.displayStudentInfo(); //call display student info function
        }
        if (user_in == "C") {
            cout << "choose course" << endl;
        }
        if (user_in == "H") {
            cout << "Returning to Home Menu." << endl;
        }
    }
    else if (user_in == "X") { //if the user input is X...
        cout << "Thank you for using GradeZilla. Keep those grades high - remember, A is for alpha, Bs are for betas!!" << endl; //exit message
        //don't forget to prompt the user to save the program data into a file
        done = true; //exit the loop, therefore ending the program
    }
    else {
        cout << "Invalid input, please enter something else." << endl;
    }

}
return 0;

}
