#pragma once
#include <iostream>

class Attendance {
private:
    int daysAttended;  // Holds the number of days attended

public:
    Attendance();  // Constructor declaration
    void setDaysAttended(int days);  // Setter declaration
    int getDaysAttended() const;  // Getter declaration
};
