#pragma once
#include <iostream>
#include <iomanip> // For formatted output

class Attendance {
private:
    int totalDays;
    int attendedDays;

public:
    // Constructor to initialize attendance
    Attendance() : totalDays(0), attendedDays(0) {}

    // Set total days and attended days
    void setAttendance(int total, int attended);

    // Calculate and return the attendance percentage
    double getAttendancePercentage() const;

    // Display attendance information
    void displayAttendance() const;
};
