#include "rental_list_item.hpp"

#include <vector>

string generateOptionName( Rental rental ) {
    Manager * manager = Manager::getInstance();
    DvdsRepository * dvds_repository = manager->getDvdsRepository();

    Dvd dvd = dvds_repository->getById( rental.getDvdId() );

    return rental.getBorrower() + "\033[1;32m -> \033[0m" + dvd.getTitle();
}

RentalListItem::RentalListItem( Rental item ) :
    MenuOption( generateOptionName( item ) ),
    rental( & item ) {}

void RentalListItem::execute(void) {
    Menu list_menu("What you want to do with this rental?", "Your choice: ");
    list_menu.addOption( new GiveBackDvd( this->rental ) );
    list_menu.addOption( new BackToMenu( "[back]" ) );

    MenuWrapper list_wrapper( & list_menu );
    list_wrapper.start( false );
}

