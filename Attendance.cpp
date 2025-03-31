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