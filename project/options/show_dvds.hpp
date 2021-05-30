#ifndef SHOW_DVDS_HPP
#define SHOW_DVDS_HPP

#include <iostream>
#include "back_to_menu.hpp"
#include "../manager.hpp"
#include "../menu/menu.hpp"
#include "../menu/menu_wrapper.hpp"
#include "../menu/menu_option.hpp"

using std::cout;
using std::endl;

class ShowDvds : public MenuOption {
public:
    ShowDvds( void );
    void execute(void);
};

#endif
