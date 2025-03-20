#pragma once
class Grade
{
private:
	double grade, weight; //member variables for a single grade and a weight
public:
	//setters
	void setGrade(double g);
	void setWeight(double w);

	//getters
	double getGrade() const;
	double getWeight() const;

	//constructor
	Grade(double g, double w);
};

