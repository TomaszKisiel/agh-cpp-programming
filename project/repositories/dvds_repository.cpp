#include "dvds_repository.hpp"
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::getline;
using std::stoi;
using std::stof;

DvdsRepository::DvdsRepository(void) {
    std::ifstream file("storage/dvds.repo");

    string line;
    while (getline(file, line)) {
        string delimiter = ";";

        auto start = 0;
        auto end = line.find(delimiter);

        int id = stoi( line.substr(start, end - start) );
        start = end + delimiter.length();
        end = line.find(delimiter, start);

        string title = line.substr(start, end - start);
        start = end + delimiter.length();
        end = line.find(delimiter, start);

        string description = line.substr(start, end - start);
        start = end + delimiter.length();
        end = line.find(delimiter, start);

        float rating = stof( line.substr(start, end - start) );
        start = end + delimiter.length();
        end = line.find(delimiter, start);

        int duration = stoi( line.substr(start, end - start) );
        start = end + delimiter.length();
        end = line.find(delimiter, start);

        Dvd dvd(id,title,description,rating,duration);
        this->dvds.push_back( dvd );
    }
}

vector<Dvd> DvdsRepository::getAll(void) {
    return this->dvds;
}

Dvd DvdsRepository::getById( int id ) {
    for ( unsigned int i = 0; i < this->dvds.size(); i++ ) {
        if ( this->dvds.at(i).getId() == id ) {
            return this->dvds.at( i );
        }
    }

    throw "Not found";
}

void DvdsRepository::store( Dvd dvd ) {
    this->dvds.push_back( dvd );

    ofstream file;
    file.open ("storage/dvds.repo", ios_base::app );
    file << dvd.serialize() << "\n";
    file.close();
}
