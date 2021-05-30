#ifndef RENTALS_REPOSITORY_HPP
#define RENTALS_REPOSITORY_HPP

#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "../entities/rental.hpp"

using std::vector;
using std::ofstream;
using std::ifstream;
using std::ios_base;
using std::cout;
using std::endl;
using std::remove_if;

class RentalsRepository {
    vector<Rental> rentals;
    void writeToFile();
    void readFromFile();
public:
    RentalsRepository(void);
    vector<Rental> getAll(void);
    Rental getByDvdId(int);
    bool isDvdInRentals(int);
    void add(Rental);
    bool remove(Rental);
};

#endif
