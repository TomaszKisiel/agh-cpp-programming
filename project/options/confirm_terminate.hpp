#ifndef CONFIRM_TERMINATE_HPP
#define CONFIRM_TERMINATE_HPP

#include <iostream>
#include "../menu/menu_option.hpp"

using std::cout;
using std::endl;

class ConfirmTerminate : public MenuOption {
public:
    ConfirmTerminate( void );
    void execute(void);
};

#endif
