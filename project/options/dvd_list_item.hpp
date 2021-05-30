#ifndef DVD_LIST_ITEM_HPP
#define DVD_LIST_ITEM_HPP

#include <iostream>
#include "back_to_menu.hpp"
#include "rent_dvd.hpp"
#include "../manager.hpp"
#include "../entities/dvd.hpp"
#include "../menu/menu.hpp"
#include "../menu/menu_wrapper.hpp"
#include "../menu/menu_option.hpp"
#include "../repositories/rentals_repository.hpp"

using std::cout;
using std::endl;

class DvdListItem : public MenuOption {
    Dvd dvd;
public:
    DvdListItem( Dvd dvd );
    void execute(void);
};

#endif
