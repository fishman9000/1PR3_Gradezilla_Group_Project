#include "Grade.h"
#include <iostream>

using namespace std;

void Grade::enterGrade(int assignmentNumber) {
    cout << "Enter grade for Assignment " << assignmentNumber << ": ";
    cin >> grade;
}
