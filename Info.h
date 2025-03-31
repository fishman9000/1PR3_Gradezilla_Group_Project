#pragma once
#include <string>

using namespace std;

class Info {
private:
    string name;
    int age;
    string gender;
    string address;

public:
    Info();  // Default constructor
    Info(string name, int age, string gender, string address);  // Parametrized constructor

    // Setters and Getters
    void setName(string n);
    string getName() const;

    void setAge(int a);
    int getAge() const;

    void setGender(string g);
    string getGender() const;

    void setAddress(string addr);
    string getAddress() const;
};
