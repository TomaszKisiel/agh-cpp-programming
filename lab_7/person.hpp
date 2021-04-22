#include <string>

#ifndef PERSON_HPP
#define PERSON_HPP

class Person {
	std::string name;
	std::string surname;
	std::string personal_id;

public:
	Person( std::string, std::string, std::string );
	void setName( std::string );
	std::string getName() const;
	void setSurname( std::string );
	std::string getSurname() const;
	void setPersonalId( std::string );
	std::string getPersonalId() const;
	virtual std::string toString() const;
};

#endif
