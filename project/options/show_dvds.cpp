#include "show_dvds.hpp"

#include <vector>
#include "../entities/dvd.hpp"
#include "dvd_list_item.hpp"

ShowDvds::ShowDvds(void) : MenuOption("Show available DVDs.") {}

void ShowDvds::execute(void) {
    Manager * manager = Manager::getInstance();
    DvdsRepository * dvds_repository = manager->getDvdsRepository();

    Menu dvd_menu("Which dvd you want to choose?", "Chose DVD: ");

    vector<Dvd> dvds = dvds_repository->getAll();
    for ( int i = 0; i < dvds.size(); i++ ) {
        dvd_menu.addOption( new DvdListItem( dvds.at(i)) );
    }

    dvd_menu.addOption( new BackToMenu( "[back]" ) );

    MenuWrapper dvd_wrapper( & dvd_menu );
    dvd_wrapper.start( false );
}
