#include "dvd_list_item.hpp"

#include <vector>

DvdListItem::DvdListItem( Dvd item ) :
    MenuOption( item.getTitle() ),
    dvd( & item ) {}

void DvdListItem::execute(void) {
    cout << endl;
    cout << "\033[1;34m" << "TITLE: " << "\033[0m" << this->dvd.getTitle() << endl;
    cout << "\033[1;34m" << "DESCRIPTION: " << "\033[0m" << this->dvd.getDescription() << endl;
    cout << "\033[1;34m" << "RATING: " << "\033[0m" << this->dvd.getRating() << endl;
    cout << "\033[1;34m" << "DURATION: " << "\033[0m" << this->dvd.getDuration() << endl;
    cout << "\033[1;34m" << "STATUS: " << "\033[0m";

    Manager * manager =  Manager::getInstance();
    RentalsRepository * rentals_repository = manager->getRentalsRepository();

    if ( rentals_repository->isDvdInRentals( this->dvd.getId() ) ) {
        cout << "\033[1;31m" << "rented" << "\033[0m" << endl;
    } else {
        cout << "\033[1;32m" << "available" << "\033[0m" << endl;
    }

    Menu list_menu("What you want to do with this DVD?", "Your choice: ");
    list_menu.addOption( new RentDvd( dvd ) );
    list_menu.addOption( new BackToMenu( "[back]" ) );

    MenuWrapper list_wrapper( & list_menu );
    list_wrapper.start( false );
}
