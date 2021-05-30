#include "manager.hpp"

Manager::Manager() {
    DvdsRepository dvds_repository;
    this->dvds_repository = dvds_repository;
}

Manager * Manager::instance = 0;

Manager * Manager::getInstance() {
    if (instance == 0) {
        instance = new Manager();
    }

    return instance;
}

DvdsRepository * Manager::getDvdsRepository( void ) {
    return & this->dvds_repository;
}

RentalsRepository * Manager::getRentalsRepository( void ) {
    return & this->rentals_repository;
}
