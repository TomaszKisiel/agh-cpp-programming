#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <iostream>
#include "repositories/dvds_repository.hpp"
#include "repositories/rentals_repository.hpp"

using std::cout;
using std::endl;

class Manager {
    private:
        static Manager* instance;
        Manager();
        DvdsRepository dvds_repository;
        RentalsRepository rentals_repository;
    public:
        static Manager * getInstance();
        DvdsRepository * getDvdsRepository( void );
        RentalsRepository * getRentalsRepository( void );
};

#endif
