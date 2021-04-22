#include "person.hpp"

Person::Person( std::string n, std::string s, std::string p ) {
	name = n;
	surname = s;
	personal_id = p;
}

void Person::setName( std::string n ) {
	name = n;
}

std::string Person::getName() const {
	return name;
}

void Person::setSurname( std::string s ) {
	surname = s;
}

std::string Person::getSurname() const {
	return surname;
}

void Person::setPersonalId( std::string p ) {
	personal_id = p;
}

std::string Person::getPersonalId() const {
	return personal_id;
}

std::string Person::toString() const {
	return "DANE OSOBOWE: " + name + " " + surname + " | PESEL: " + personal_id;
}
