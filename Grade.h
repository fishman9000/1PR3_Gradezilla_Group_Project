#pragma once
#include <string>
using namespace std;
class Grade
{
private:
	string name; //the name of what the grade is for
	double grade, weight; //member variables for a single grade and a weight
public:
	//setters
	void setName(string n);
	void setGrade(double g);
	void setWeight(double w);

	//getters
	string getName() const;
	double getGrade() const;
	double getWeight() const;

	//constructor
	Grade(string, double, double);
};

