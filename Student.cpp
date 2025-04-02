#include "Student.h"
#include "Info.h"
#include <iostream>

// Enter student information
void Student::enterStudentInfo() {
    studentInfo.enterInfo();
}

// Display student data
void Student::displayStudentData() const {
    studentInfo.displayInfo();
}

// Enter courses for the student
void Student::enterCourses() {
    int numCourses;
    std::cout << "Enter number of courses: ";
    std::cin >> numCourses;
    std::cin.ignore(); // Ignore newline left by cin

    for (int i = 1; i <= numCourses; i++) {
        Course course;
        std::cout << "Enter course " << i << " details:" << std::endl;
        course.enterCourseInfo();

        int numAssignments;
        std::cout << "Enter number of assignments: ";
        std::cin >> numAssignments;
        std::cin.ignore(); // Ignore newline left by cin

        course.enterGrades(numAssignments);

        int totalDays, attendedDays;
        std::cout << "Enter total number of days in the semester: ";
        std::cin >> totalDays;
        std::cout << "Enter the number of days attended: ";
        std::cin >> attendedDays;
        std::cin.ignore(); // Ignore newline left by cin

        course.setAttendance(totalDays, attendedDays);

        courses.push_back(course);
    }
}

// Display all course data for the student
void Student::displayCoursesData() const {
    for (const auto& course : courses) {
        course.displayCourseInfo();
        std::cout << "Average Grade: " << course.calculateAverage() << std::endl;
        std::cout << std::endl;
    }
}
