#ifndef MENU_WRAPPER_HPP
#define MENU_WRAPPER_HPP

#include <iostream>
#include "menu.hpp"

using std::cout;
using std::cin;
using std::endl;

class MenuWrapper {
    Menu * menu;
public:
    MenuWrapper( Menu * );
    void start( bool );
};

#endif
