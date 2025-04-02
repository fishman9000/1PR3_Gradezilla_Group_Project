#pragma once
#include <string>
#include <vector>

using namespace std;

class Course {
private:
    string courseName;
    string courseCode;
    string teacherName;
    string classroom;
    vector<int> grades;

public:
    Course(string name, string code, string teacher, string room);

    void addGrade(int grade);
    void viewCourseData() const;
};
