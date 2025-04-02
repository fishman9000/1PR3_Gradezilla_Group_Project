#include "Info.h"
#include <iostream>
using namespace std;

void Info::enterInfo() {
    cout << "Enter student full name: ";
    getline(cin, name); // Captures full name with spaces

    cout << "Enter age: ";
    cin >> age;
    cin.ignore(); // Clears newline character left in the buffer

    cout << "Enter gender: ";
    getline(cin, gender); // Allows spaces in gender input (if needed)

    cout << "Enter full address: ";
    getline(cin, address); //  Captures full address with spaces
}

void Info::displayInfo() const {
    cout << "Student Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Address: " << address << endl;
}
