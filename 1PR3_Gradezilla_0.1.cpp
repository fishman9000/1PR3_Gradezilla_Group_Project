#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;

int main() {
    vector<Student> students;
    
    while (true) {
        cout << "\n======== Welcome to GradeZilla =======" << endl;
        cout << "1. Enter Student Info" << endl;
        cout << "2. View Data" << endl;
        cout << "3. Enter Course Info" << endl;
        cout << "4. Exit Program" << endl;
        cout << "Choose an option: ";

        int choice;
        cin >> choice;
        cin.ignore(); // Ignore newline

        if (choice == 1) {
            Student newStudent;
            newStudent.enterStudentInfo();
            students.push_back(newStudent);
        } 
        else if (choice == 2) {
            if (students.empty()) {
                cout << "No students available." << endl;
            } else {
                cout << "\n===== Student List =====" << endl;
                for (size_t i = 0; i < students.size(); ++i) {
                    cout << i + 1 << ". " << students[i].getName() << endl;
                }
                
                cout << "\nSelect a student to view details (Enter number): ";
                int studentIndex;
                cin >> studentIndex;
                cin.ignore(); // Ignore newline

                if (studentIndex > 0 && studentIndex <= students.size()) {
                    cout << "\n===== Student Info =====" << endl;
                    students[studentIndex - 1].displayStudentData();
                    cout << "\n===== Course Info =====" << endl;
                    students[studentIndex - 1].displayCoursesData();
                } else {
                    cout << "Invalid selection!" << endl;
                }
            }
        } 
        else if (choice == 3) {
            if (students.empty()) {
                cout << "No students available. Please enter student info first." << endl;
            } else {
                cout << "\n===== Student List =====" << endl;
                for (size_t i = 0; i < students.size(); ++i) {
                    cout << i + 1 << ". " << students[i].getName() << endl;
                }
                
                cout << "\nSelect a student to add courses for: ";
                int studentIndex;
                cin >> studentIndex;
                cin.ignore(); // Ignore newline

                if (studentIndex > 0 && studentIndex <= students.size()) {
                    students[studentIndex - 1].enterCourses();
                } else {
                    cout << "Invalid selection!" << endl;
                }
            }
        } 
        else if (choice == 4) {
            cout << "Exiting GradeZilla..." << endl;
            break;
        } 
        else {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
