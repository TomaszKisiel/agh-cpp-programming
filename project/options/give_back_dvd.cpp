#include "give_back_dvd.hpp"

GiveBackDvd::GiveBackDvd( Rental rental ) :
    MenuOption( "Give back this dvd." ),
    rental( & rental ) {}

void GiveBackDvd::execute(void) {
    cout << "\033[1;33m" << "Provide your name to give back this DVD: " << "\033[0m";

    string identity;
    cin.ignore();
    getline( cin, identity );

    if ( this->rental.getBorrower() == identity ) {
        Manager * manager = Manager::getInstance();
        RentalsRepository * rentals_repository = manager->getRentalsRepository();

        rentals_repository->remove( rental );

        cout << "\033[1;32m" << "DVD successfully returned!" << "\033[0m" << endl;
    } else {
        cout << "\033[1;31m" << "Unfortunately this DVD was rented by someone else. You can't give it back." << "\033[0m" << endl;
    }
}
