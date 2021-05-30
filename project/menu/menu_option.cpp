#include "menu_option.hpp"

MenuOption::MenuOption( string title ) {
    this->title = title;
}

string MenuOption::getTitle() {
    return this->title;
}
