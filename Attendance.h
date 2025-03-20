#pragma once
class Attendance
{
private:
	int days_attended, days_missed; //member variables for days attended and days missed
public:
	//setters
	void setDaysAttended(int);
	void setDaysMissed(int);
	//getters
	int getDaysAttended() const;
	int getDaysMissed() const;
};

