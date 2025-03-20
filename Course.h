#pragma once
#include <string>

using namespace std;

class Course {
	private:
		string courseCode;
		string courseName;
		string teacherName;
		string classroom;

	public:
		//constructors
		Course(string code, string name, string teacher, string room);

		//Setters
		void setCourseCode(string code);
		void setCourseName(string name);
		void setTeacherName(string teacher);
		void setClassroom(string room);
		//we need to still get the grades for every class!!!!!!!!
		//getters
		string getCourseCode() const;
		string getCourseName() const;
		string getTeacherName() const;
		string getClassroom() const;
		
		//Calculate average grade
		double getAverageGrade() const;


};


