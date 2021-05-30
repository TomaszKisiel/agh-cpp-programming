#include "show_rentals.hpp"

#include <vector>
#include "../entities/dvd.hpp"

ShowRentals::ShowRentals(void) : MenuOption("Show rentals.") {}

void ShowRentals::execute(void) {
    Manager * manager =  Manager::getInstance();
    RentalsRepository * rentals_repository = manager->getRentalsRepository();
    DvdsRepository * dvds_repository = manager->getDvdsRepository();

    vector<Rental> rentals = rentals_repository->getAll();

    Menu rental_menu("Which rental you want to choose?", "Chose rental: ");
    for ( int i = 0; i < rentals.size(); i++ ) {
        rental_menu.addOption( new RentalListItem( rentals.at(i)) );
    }

    rental_menu.addOption( new BackToMenu( "[back]" ) );

    MenuWrapper rental_wrapper( & rental_menu );
    rental_wrapper.start( false );
}
