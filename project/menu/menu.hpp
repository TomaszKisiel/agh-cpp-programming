#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include <vector>
#include "menu_option.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Menu {
    string title;
    string hint;
    vector<MenuOption *> options;
public:
    Menu( string, string );
    void addOption( MenuOption * );
    void printOptions( void );
    void handleOption( int );
    void printHint( bool = false );
};

#endif
