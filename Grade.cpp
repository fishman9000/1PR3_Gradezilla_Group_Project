#include "Grade.h"

//setter definitions
void Grade::setName(string n) {
	name = n;
}

void Grade::setGrade(double g) {
	grade = g;
}
void Grade::setWeight(double w) {
	weight = w;
}

//getter definitions
string Grade::getName() const {
	return name;
}

double Grade::getGrade() const {
	return grade;
}
double Grade::getWeight() const {
	return weight;
}

//constructor definition
Grade::Grade(string n, double g, double w) {
	name = n;
	grade = g;
	weight = w;
}