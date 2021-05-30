#include "menu/menu.hpp"
#include "menu/menu_wrapper.hpp"
#include "options/show_dvds.hpp"
#include "options/show_rentals.hpp"
#include "options/terminate.hpp"

int main( void ) {
    Menu main_menu("Welcome in DVD rental! How can I help you?", "Your choice: ");
    main_menu.addOption( new ShowDvds() );
    main_menu.addOption( new ShowRentals() );
    main_menu.addOption( new Terminate() );

    MenuWrapper main_wrapper( & main_menu );
    main_wrapper.start( true );

	return 0;
}
