#include "student.hpp"

Student::Student( std::string n, std::string s, std::string p, std::string i, std::string f ) : Person( n, s, p ) {
	student_id = i;
	field_of_study = f;
}

void Student::setStudentId( std::string i ) {
	student_id = i;
}

std::string Student::getStudentId( ) const {
	return student_id;
}

void Student::setFieldOfStudy( std::string f ) {
	field_of_study = f;
}

std::string Student::getStudentId( std::string ) const {
	return field_of_study;
}

std::string Student::toString() {
	return Person::toString() + " | INDEKS: " + student_id + " | KIERUNEK: " + field_of_study;
}
