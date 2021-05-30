#ifndef BACK_TO_MENU_HPP
#define BACK_TO_MENU_HPP

#include <iostream>
#include "../menu/menu_option.hpp"

class BackToMenu : public MenuOption {
public:
    BackToMenu( string );
    void execute(void);
};

#endif
