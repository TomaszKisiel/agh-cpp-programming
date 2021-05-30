#include "rental.hpp"

Rental::Rental( Rental * that ) {
    this->dvd_id = that->getDvdId();
    this->borrower = that->getBorrower();
}

Rental::Rental( int id, string borrower ) {
    this->dvd_id = id;
    this->borrower = borrower;
}

void Rental::setDvdId( int id ) {
    this->dvd_id = id;
}

void Rental::setBorrower( string borrower ) {
    this->borrower = borrower;
}

int Rental::getDvdId(void) {
    return this->dvd_id;
}

string Rental::getBorrower(void) {
    return this->borrower;
}

string Rental::serialize(void) {
    return to_string( this->dvd_id ) + ";" + this->borrower + ";";
}
