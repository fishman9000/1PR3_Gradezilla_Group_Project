#include "Grade.h"
#include <iostream>

// Enter grade for an assignment
void Grade::enterGrade(int assignmentNumber) {
    std::cout << "Enter grade for Assignment " << assignmentNumber << ": ";
    std::cin >> grade;
    std::cin.ignore(); // Ignore newline left by cin
}

// Display the grade for an assignment
void Grade::displayGrade() const {
    std::cout << "Assignment - Grade: " << grade << std::endl;
}

// Get the grade for calculations
double Grade::getGrade() const {
    return grade;
}
