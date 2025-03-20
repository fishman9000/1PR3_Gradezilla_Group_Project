#include "Info.h"
//setter definition
void Info::setAge(int a) {
	age = a;
}
void Info::setGender(string g) {
	gender = g;
}
void Info::setAddress(string d) {
	address = d;
}

//getter definition
int Info::getAge() const {
	return age;
}
string Info::getGender() const {
	return gender;
}
string Info::getAddress() const {
	return address;
}