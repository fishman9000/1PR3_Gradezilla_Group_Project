#include "Attendance.h"
#include <iostream>
#include <iomanip>  // For setting precision

using namespace std;

void Attendance::enterAttendanceInfo() {
    cout << "Enter total number of days in the semester: ";
    cin >> totalDays;
    cout << "Enter the number of days attended: ";
    cin >> daysAttended;
}

void Attendance::displayAttendanceInfo() const {
    double attendancePercentage = getAttendancePercentage();
    cout << "Total Days: " << totalDays << endl;
    cout << "Attended Days: " << daysAttended << endl;
    cout << "Attendance Percentage: " << fixed << setprecision(2) << attendancePercentage << "%" << endl;
}

double Attendance::getAttendancePercentage() const {
    if (totalDays == 0) return 0.0;  // Avoid division by zero
    return (static_cast<double>(daysAttended) / totalDays) * 100.0;
}
