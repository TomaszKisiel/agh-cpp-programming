#ifndef SHOW_Rentals_HPP
#define SHOW_Rentals_HPP

#include <iostream>
#include "back_to_menu.hpp"
#include "rental_list_item.hpp"
#include "../entities/rental.hpp"
#include "../entities/dvd.hpp"
#include "../manager.hpp"
#include "../menu/menu.hpp"
#include "../menu/menu_wrapper.hpp"
#include "../menu/menu_option.hpp"
#include "../repositories/rentals_repository.hpp"
#include "../repositories/dvds_repository.hpp"

using std::cout;
using std::endl;

class ShowRentals : public MenuOption {
public:
    ShowRentals( void );
    void execute(void);
};

#endif
