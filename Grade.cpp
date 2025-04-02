#include "Grade.h"
#include <iostream>
using namespace std;

// Default constructor
Grade::Grade() : name(""), grade(0.0), weight(0.0) {}

// Parameterized constructor
Grade::Grade(string n, double g, double w) {
    name = n;
    grade = g;
    weight = w;
}

// Setter definitions
void Grade::setName(string n) {
    name = n;
}
void Grade::setGrade(double g) {
    grade = g;
}
void Grade::setWeight(double w) {
    weight = w;
}

// Getter definitions
string Grade::getName() const {
    return name;
}
double Grade::getGrade() const {
    return grade;
}
double Grade::getWeight() const {
    return weight;
}

// Method to calculate weighted grade
double Grade::calculateWeightedGrade() const {
    return grade * (weight / 100.0);
}
