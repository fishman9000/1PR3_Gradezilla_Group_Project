#include "Info.h"
#include <iostream>
using namespace std;
//setter definition



void Info::setName(string n) {
	name = n;
}
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
string Info::getName() const {
	return name;
}
int Info::getAge() const {
	return age;
}
string Info::getGender() const {
	return gender;
}
string Info::getAddress() const {
	return address;
}

//constructor
Info::Info(string n, int a, string g, string d) {
	name = n;
	age = a;
	gender = g;
	address = d;
}

//output info:
void Info::displayInfo() const {
	cout << "Name: " << getName() << "\nAge: " << getAge() 
		<< "\nGender: " << getGender() << "\nAddress: " 
		<< getAddress() << endl;
}
