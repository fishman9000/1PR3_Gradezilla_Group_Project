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
		//consructors
		Course(string code, string name, string teacher, string room);

		//Setters
		void setCourseCode(std::string code);
		void setCourseName(std::string name);
		void setTeacherName(std::string teacher);
		void setClassroom(std::string room);

		//getters
		std::string getCourseCode() const;
		std::string getCourseName() const;
		std::string getTeacherName() const;
		std::string getClassroom() const;
		
		//Calculate average grade
		double getAverageGrade() const;


};


