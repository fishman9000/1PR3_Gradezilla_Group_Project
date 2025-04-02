#pragma once

class Attendance {
private:
    int totalDays;
    int daysAttended;

public:
    void enterAttendanceInfo();
    void displayAttendanceInfo() const;
    double getAttendancePercentage() const;
};
