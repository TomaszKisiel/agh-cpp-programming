#include "rentals_repository.hpp"
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::getline;
using std::stoi;
using std::stof;

RentalsRepository::RentalsRepository(void) {
    this->readFromFile();
}

void RentalsRepository::readFromFile(void) {
    ifstream file("storage/rentals.repo");

    string line;
    while (getline(file, line)) {
        string delimiter = ";";

        auto start = 0;
        auto end = line.find(delimiter);

        int dvd_id = stoi( line.substr(start, end - start) );
        start = end + delimiter.length();
        end = line.find(delimiter, start);

        string borrower = line.substr(start, end - start);
        start = end + delimiter.length();
        end = line.find(delimiter, start);

        Rental rental( dvd_id, borrower );
        this->rentals.push_back( rental );
    }
}

void RentalsRepository::writeToFile(void) {
    ofstream file;
    file.open ("storage/rentals.repo", ios_base::trunc | ios_base::out );
    for ( int i=0; i < this->rentals.size(); i++ ) {
        file << this->rentals.at(i).serialize() << "\n";
    }
    file.close();
}

vector<Rental> RentalsRepository::getAll(void) {
    return this->rentals;
}

Rental RentalsRepository::getByDvdId( int id ) {
    for ( int i = 0; i < this->rentals.size(); i++ ) {
        Rental rental = this->rentals.at( i );

        if ( rental.getDvdId() == id ) {
            return this->rentals.at( i );
        }
    }

    throw "Not found";
}

bool RentalsRepository::isDvdInRentals( int dvd_id ) {
    for ( int i = 0; i < this->rentals.size(); i++ ) {
        Rental rental = this->rentals.at( i );

        if ( rental.getDvdId() == dvd_id ) {
            return true;
        }
    }

    return false;
}

void RentalsRepository::add( Rental rental ) {
    this->rentals.push_back( rental );
    this->writeToFile();
}

bool RentalsRepository::remove( Rental rental ) {
    Rental to_remove = this->getByDvdId( rental.getDvdId() );

//    this->rentals.erase( std::remove( rentals.begin(), rentals.end(), to_remove ), rentals.end() );

    this->rentals.erase( remove_if(
        this->rentals.begin(),
        this->rentals.end(),
        [&rental]( Rental other ){ return other.getDvdId() == rental.getDvdId(); }
    ), this->rentals.end());
    this->writeToFile();

    return true;
}
