#pragma once
class Grade
#include <string>
{
private:
	string name;
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
	Grade(string n, double g, double w);
};

