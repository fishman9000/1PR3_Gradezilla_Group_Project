#include <iostream>
#include <vector>
#include "Student.h"
#include "Course.h"

using namespace std;

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        cout << "======== Welcome to GradeZilla =======" << endl;
        cout << "1. Enter Student Info" << endl;
        cout << "2. View Data" << endl;
        cout << "3. Enter Course Info" << endl;
        cout << "4. Exit Program" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            string name, gender, address;
            int age;
            cout << "\nEnter Student Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Gender: ";
            cin >> gender;
            cout << "Enter Address: ";
            cin >> address;

            Student student(name, age, gender, address);
            students.push_back(student);
        }
        else if (choice == 2) {
            for (const auto& student : students) {
                student.viewData();
            }
        }
        else if (choice == 3) {
            if (students.empty()) {
                cout << "\nNo students available. Please add a student first." << endl;
                continue;
            }

            cout << "\nEnter course information for a student:" << endl;
            string studentName;
            cout << "Enter Student Name: ";
            cin >> studentName;

            Student* student = nullptr;
            for (auto& s : students) {
                if (s.getName() == studentName) {
                    student = &s;
                    break;
                }
            }

            if (student == nullptr) {
                cout << "Student not found!" << endl;
                continue;
            }

            string courseName, courseCode, teacherName, classroom;
            int numAssignments;

            cout << "\nEnter Course Name: ";
            cin >> courseName;
            cout << "Enter Course Code: ";
            cin >> courseCode;
            cout << "Enter Teacher Name: ";
            cin >> teacherName;
            cout << "Enter Classroom: ";
            cin >> classroom;

            Course course(courseName, courseCode, teacherName, classroom);
            student->addCourse(course);

            cout << "\nHow many assignments does the course have? ";
            cin >> numAssignments;

            for (int i = 0; i < numAssignments; ++i) {
                int grade;
                cout << "Enter grade for Assignment " << i + 1 << ": ";
                cin >> grade;
                course.addGrade(grade);
            }
        }
        else if (choice == 4) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
