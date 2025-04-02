#pragma once
#include <iostream>

class Grade {
private:
    double grade;

public:
    // Method to enter grade for an assignment
    void enterGrade(int assignmentNumber);

    // Method to display the grade for an assignment
    void displayGrade() const;

    // Method to get the grade for calculations
    double getGrade() const;
};
