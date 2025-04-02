#pragma once
#include <string>

class Info {
public:
    std::string name;
    int age;
    std::string gender;
    std::string address;

    Info(std::string studentName);

    void enterStudentInfo();
    void displayStudentInfo() const;
};
