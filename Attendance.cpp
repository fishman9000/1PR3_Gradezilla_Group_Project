#include "Attendance.h"

//setter definitions
void Attendance::setDaysAttended(int a) {
	days_attended = a;
}
void Attendance::setDaysMissed(int m) {
	days_missed = m;
}

//getter definitions
int Attendance::getDaysAttended() const {
	return days_attended;
}
int Attendance::getDaysMissed() const {
	return days_missed;
}
