
#pragma once

#include <string>
#include <iostream>

class Info {
private:
    std::string name;
    int age;
    std::string gender;
    std::string address;

public:
    void enterInfo();
    void displayInfo() const;

    std::string getName() const { return name; }  // Getter for name
};

