#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(string n, int a, string g, string addr)
    : name(n), age(a), gender(g), address(addr) {}

string Student::getName() const {
    return name;
}

void Student::addCourse(const Course& course) {
    courses.push_back(course);
}

void Student::viewData() const {
    cout << "\nStudent: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Address: " << address << endl;

    if (courses.empty()) {
        cout << "No courses available." << endl;
    }
    else {
        for (const auto& course : courses) {
            course.viewCourseData();
        }
    }
}
