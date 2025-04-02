#pragma once
#include <string>
#include <vector>
#include "Course.h"

using namespace std;

class Student {
private:
    string name;
    int age;
    string gender;
    string address;
    vector<Course> courses;

public:
    Student(string n, int a, string g, string addr);

    string getName() const;
    void addCourse(const Course& course);
    void viewData() const;
};
