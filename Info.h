#pragma once
#include <string>
using namespace std;
class Info //student's personal info
{
private:
	string name;
	int age;
	string gender;
	string address;
public:
	//setters
	void setName(int n);
	void setAge(int a);
	void setGender(string g);
	void setAddress(string d);


	//getters
	string getName() const;
	int getAge() const;
	string getGender() const;
	string getAddress() const;

	//constructor
	Info(string n, int a, string g, string d);

	void displayInfo() const; //display function to display info data

};

