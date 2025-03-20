#pragma once
#include <string>
using namespace std;
class Info //student's personal info
{
private:
	int age;
	string gender;
	string address;
public:
	//setters
	void setAge(int a);
	void setGender(string g);
	void setAddress(string d);

	//getters
	int getAge() const;
	string getGender() const;
	string getAddress() const;
};

