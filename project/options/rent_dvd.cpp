#include "rent_dvd.hpp"

RentDvd::RentDvd( Dvd item ) :
    MenuOption( "Rent this dvd." ),
    dvd( & item ) {}

void RentDvd::execute(void) {
    Manager * manager =  Manager::getInstance();
    RentalsRepository * rentals_repository = manager->getRentalsRepository();

    if ( rentals_repository->isDvdInRentals( this->dvd.getId() ) ) {
        cout << "\033[1;31m" << "Unfortunately this DVD is already rented. Please try again latter." << "\033[0m" << endl;
    } else {
        cout << "\033[1;33m" << "Provide your name to rent this DVD: " << "\033[0m";

        string borrower;
        cin.ignore();
        getline( cin, borrower );

        Rental rental( this->dvd.getId(), borrower );
        rentals_repository->add( rental );

        cout << "\033[1;32m" << "DVD successfully rented!" << "\033[0m" << endl;
    }
}
