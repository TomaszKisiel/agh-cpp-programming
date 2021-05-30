#include "menu_wrapper.hpp"

MenuWrapper::MenuWrapper( Menu * menu ) {
    this->menu = menu;
}

void MenuWrapper::start( bool infinite = false ) {
    bool executed = false;
    while ( infinite || !executed ) {
        this->menu->printOptions();
        this->menu->printHint();

        int choose;
        cin >> choose;

        if ( cin.fail() ) {
            cin.clear();
            cin.ignore(100000, '\n');
        }

        try {
            this->menu->handleOption( choose - 1 );
        } catch(...) {
            cout << "\033[1;31m" << "The given value was invalid! Please try again." << "\033[0m" << endl;
            continue;
        }

        executed = true;
    }
}
