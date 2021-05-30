#ifndef MENU_OPTION_HPP
#define MENU_OPTION_HPP

#include <string>

using std::string;

class MenuOption {
    string title;
public:
    MenuOption( string );
    string getTitle(void);
    virtual void execute(void) = 0;
};

#endif
