#ifndef GIVE_BACK_DVD_HPP
#define GIVE_BACK_DVD_HPP

#include <iostream>
#include <string>
#include "../manager.hpp"
#include "../entities/rental.hpp"
#include "../menu/menu_option.hpp"
#include "../repositories/rentals_repository.hpp"

using std::cout;
using std::cin;
using std::endl;

class GiveBackDvd : public MenuOption {
    Rental rental;
public:
    GiveBackDvd( Rental );
    void execute(void);
};

#endif
