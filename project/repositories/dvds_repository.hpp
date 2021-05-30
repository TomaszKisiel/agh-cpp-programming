#ifndef DVDS_REPOSITORY_HPP
#define DVDS_REPOSITORY_HPP

#include <vector>
#include <fstream>
#include <iostream>
#include "../entities/dvd.hpp"

using std::vector;
using std::ofstream;
using std::ios_base;
using std::cout;
using std::endl;

class DvdsRepository {
    vector<Dvd> dvds;
public:
    DvdsRepository(void);
    vector<Dvd> getAll(void);
    Dvd getById(int);
    void store(Dvd);
};

#endif
