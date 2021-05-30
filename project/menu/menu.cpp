#include "menu.hpp"

Menu::Menu( string title = "", string hint = "" ) {
    this->title = title;
    this->hint = hint;
}

void Menu::addOption(MenuOption *opt) {
    this->options.push_back(opt);
}

void Menu::handleOption( int index ) {
    MenuOption * option = this->options.at( index );

    option->execute();
}

void Menu::printOptions(void) {
    cout << endl;
    cout << "\033[1;32m" << this->title << "\033[0m" << endl;

    for ( int i = 0; i < this->options.size(); i++ ) {
        cout << "  " << i + 1 << ". ";
        cout << this->options[i]->getTitle() << endl;
    }

    cout << endl;
}

void Menu::printHint(bool newline) {
    cout << "\033[1;33m" << this->hint << "\033[0m";

    if ( newline ) {
        cout << endl;
    }
}

