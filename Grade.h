#pragma once
#include <string>
#include <vector>
using namespace std;

class Grade {
private:
    string name;
    double grade;
    double weight;

public:
    // Constructors
    Grade(); // Default constructor
    Grade(string n, double g, double w);

    // Setters
    void setName(string n);
    void setGrade(double g);
    void setWeight(double w);

    // Getters
    string getName() const;
    double getGrade() const;
    double getWeight() const;

    // Method to calculate weighted grade
    double calculateWeightedGrade() const;
};