#ifndef RENTAL_LIST_ITEM_HPP
#define RENTAL_LIST_ITEM_HPP

#include <iostream>
#include "back_to_menu.hpp"
#include "give_back_dvd.hpp"
#include "../manager.hpp"
#include "../entities/rental.hpp"
#include "../menu/menu.hpp"
#include "../menu/menu_wrapper.hpp"
#include "../menu/menu_option.hpp"

using std::cout;
using std::endl;

class RentalListItem : public MenuOption {
    Rental rental;
public:
    RentalListItem( Rental rental );
    void execute(void);
};

#endif
