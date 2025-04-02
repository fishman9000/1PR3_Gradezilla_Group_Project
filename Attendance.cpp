#include "Attendance.h"

// Set attendance details
void Attendance::setAttendance(int total, int attended) {
    totalDays = total;
    attendedDays = attended;
}

// Calculate and return attendance percentage
double Attendance::getAttendancePercentage() const {
    if (totalDays == 0) return 0; // Avoid division by zero
    return (static_cast<double>(attendedDays) / totalDays) * 100;
}

// Display attendance information
void Attendance::displayAttendance() const {
    std::cout << "Total Days: " << totalDays << std::endl;
    std::cout << "Attended Days: " << attendedDays << std::endl;
    std::cout << "Attendance Percentage: " << std::fixed << std::setprecision(2) << getAttendancePercentage() << "%" << std::endl;
}
