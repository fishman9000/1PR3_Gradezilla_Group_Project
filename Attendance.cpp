#include "Attendance.h"
#include <iostream>
using namespace std;

// Default constructor
Attendance::Attendance() : daysAttended(0) {}

// Setter for daysAttended
void Attendance::setDaysAttended(int days) {
    if (days >= 0) {  // Ensure that days attended is non-negative
        daysAttended = days;
    }
    else {
        cout << "Error: Days attended cannot be negative.\n";
    }
}

// Getter for daysAttended
int Attendance::getDaysAttended() const {
    return daysAttended;
}

