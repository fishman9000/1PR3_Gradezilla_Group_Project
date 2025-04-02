#pragma once

class Grade {
private:
    double grade;

public:
    void enterGrade(int assignmentNumber);
    double getGrade() const { return grade; }
};
