#include "terminate.hpp"
#include "../menu/menu.hpp"
#include "../menu/menu_wrapper.hpp"
#include "confirm_terminate.hpp"
#include "suspend_terminate.hpp"

Terminate::Terminate(void) : MenuOption("Exit") {}

void Terminate::execute(void) {
    ConfirmTerminate confirm_terminate;
    SuspendTerminate suspend_terminate;

    Menu confirmation_menu("Are you sure you want to leave?", "Your choice: ");
    confirmation_menu.addOption( & confirm_terminate );
    confirmation_menu.addOption( & suspend_terminate );

    MenuWrapper main_wrapper( & confirmation_menu );
    main_wrapper.start( false );
}
