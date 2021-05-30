#ifndef TERMINATE_HPP
#define TERMINATE_HPP

#include <iostream>
#include "../menu/menu_option.hpp"

using std::cout;
using std::cin;
using std::endl;

class Terminate : public MenuOption {
public:
    Terminate( void );
    void execute(void);
};

#endif
