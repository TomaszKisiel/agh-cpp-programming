#include <string>
#include "person.hpp"

#ifndef STUDNET_HPP
#define STUDENT_HPP

class Student : public Person {
	std::string student_id;
	std::string field_of_study;
public:
	Student( std::string, std::string, std::string, std::string, std::string );
	void setStudentId( std::string );
	std::string getStudentId( ) const;
	void setFieldOfStudy( std::string );
	std::string getStudentId( std::string ) const;
	std::string toString();
};

#endif
