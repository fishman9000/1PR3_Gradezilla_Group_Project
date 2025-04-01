#include "Attendance.h"
#include <iomanip>
#include <iostream>
using namespace std;


// Setter for daysAttended
void Attendance::setDaysAttended(int days) {
    if (days >= 0) {  // Ensure that days attended is non-negative
        days_attended = days;
    }
    else {
        cout << "Error: Days attended cannot be negative.\n";
    }
}
//setter for days missed
void Attendance::setDaysMissed(int days) {
    if (days >= 0) {  // Ensure that days is non-negative
        days_attended = days;
    }
    else {
        cout << "Error: Days missed cannot be negative.\n";
    }
}


// Getter for daysAttended
int Attendance::getDaysAttended() const {
    return days_attended;
}
//getter for days missed
int Attendance::getDaysMissed() const {
    return days_missed;
}


//default constructor
Attendance::Attendance() {
	days_attended = 0;
	days_missed = 0;
}

//constructor definition

Attendance::Attendance(int a, int m) {
	days_attended = a;
	days_missed = m;
}

//display attendance data function definition
void Attendance::displayAttendance() const {
	cout << "Days Attended: " << getDaysAttended() << "\nDays Missed: " << getDaysMissed() << endl;
}