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
#include <algorithm> //added this header for transform function (handles Upper/lower case scenario)
#include <cctype> // for toupper header for transform function
using namespace std;


int main()
{
    cout << "**********************************WELCOME TO GRADEZILLA**********************************" << endl; //intro message
    
    Student currentStudent; // make a student object
    
    
    bool done = false;
    string user_in; //user input variable (make sure to validate the input so if the user doesn't enter one of the menu options, it does the loop again)
    while (!done) { //this loop runs over and over again as long as the user doesn't end the program
        cout << "\nHow may I help you?" << endl; //help prompt
        cout << "HOME MENU" << endl;
        cout << "A: Enter Data\nB: View Data \nX: Exit program. " << endl; //have default constructor for everything so that if there's no data,it can be like "no data entered"
        cin >> user_in; //take user input
        transform(user_in.begin(), user_in.end(), user_in.begin(), ::toupper);// this is to handle any lower/upper case scenario
        
        if (user_in == "A") {
            cout << "*****ENTER DATA MENU***" << endl;
            cout << "What would you like to enter data for?" << endl;
            cout << "A: Attendance\nB: Personal Info\nC: Course Info\nH: Return Home" << endl;
            cin >> user_in;
            transform(user_in.begin(), user_in.end(), user_in.begin(), ::toupper);// this is to handle any lower/upper case scenario
            
            if (user_in == "A") {
                cout << "get attendance records" << endl;
            }
            if (user_in == "B") {
                string tmp;
                cout << "Enter Personal Info Selected." << endl;
                cout << "Please enter your name: ";
                cin >> tmp;
                
            }
            if (user_in == "C") {
                cout << "choose course" << endl;
            }
            if (user_in == "H") {
                cout << "Returning to Home Menu." << endl;
            }
        }
        if (user_in == "B") {
            cout << "*****VIEW DATA MENU*****" << endl;
            cout << "What data would you like to view?" << endl;
            cout << "A: Attendance\nB: Personal Info\nC: Course Info\nH: Return Home" << endl;
            cin >> user_in;
            transform(user_in.begin(), user_in.end(), user_in.begin(), ::toupper);// this is to handle any lower/upper case scenario
            
            if (user_in == "A") {
                cout << "get attendance records" << endl;
            }
            if (user_in == "B") {
                cout << "Displaying Personal Info: " << endl;
            }
            if (user_in == "C") {
                cout << "choose course" << endl;
            }
            if (user_in == "H") {
                cout << "Returning to Home Menu." << endl;
            }
        }
        if (user_in == "X") { //if the user input is X...
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
