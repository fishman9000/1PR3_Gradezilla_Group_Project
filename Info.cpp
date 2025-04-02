#include "Info.h"
#include <iostream>

using namespace std;

Info::Info(string studentName) {
    name = studentName;
}

void Info::enterStudentInfo() {
    cout << "Enter age for " << name << ": ";
    cin >> age;
    cout << "Enter gender for " << name << ": ";
    cin.ignore();  // To ignore the newline from previous input
    getline(cin, gender);
    cout << "Enter address for " << name << ": ";
    getline(cin, address);
}

void Info::displayStudentInfo() const {
    cout << "Student: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Address: " << address << endl << endl;
}
