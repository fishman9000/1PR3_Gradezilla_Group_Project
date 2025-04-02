#include "Course.h"
#include <iostream>

using namespace std;

Course::Course(string name, string code, string teacher, string room)
    : courseName(name), courseCode(code), teacherName(teacher), classroom(room) {}

void Course::addGrade(int grade) {
    grades.push_back(grade);
}

void Course::viewCourseData() const {
    cout << "\nCourse: " << courseName << endl;
    cout << "Course Code: " << courseCode << endl;
    cout << "Teacher: " << teacherName << endl;
    cout << "Classroom: " << classroom << endl;

    if (grades.empty()) {
        cout << "No grades available." << endl;
    }
    else {
        cout << "Assignments:\n";
        for (size_t i = 0; i < grades.size(); ++i) {
            cout << "  Assignment " << i + 1 << " - Grade: " << grades[i] << endl;
        }
        // Calculate average grade
        int total = 0;
        for (int grade : grades) {
            total += grade;
        }
        double average = (grades.empty()) ? 0 : static_cast<double>(total) / grades.size();
        cout << "Average Grade: " << average << endl;
    }
}
