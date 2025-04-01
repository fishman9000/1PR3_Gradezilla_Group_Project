#pragma once
class Attendance
{
protected:
	int days_attended, days_missed; //member variables for days attended and days missed
public:
	//setters
	void setDaysAttended(int);
	void setDaysMissed(int);
	//getters
	int getDaysAttended() const;
	int getDaysMissed() const;

	//default constructor
	Attendance();

	//constructors
	Attendance(int a, int m);

	//display attendance info
	void displayAttendance() const;
};

