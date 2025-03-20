#include "Grade.h"

//setter definitions
void Grade::setGrade(double g) {
	grade = g;
}
void Grade::setWeight(double w) {
	weight = w;
}

//getter definitions
double Grade::getGrade() const {
	return grade;
}
double Grade::getWeight() const {
	return weight;
}

//constructor definition
Grade::Grade(double g, double w) {
	grade = g;
	weight = w;
}