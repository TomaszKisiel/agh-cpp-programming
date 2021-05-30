#ifndef RENT_DVD_HPP
#define RENT_DVD_HPP

#include <iostream>
#include <string>
#include "../manager.hpp"
#include "../entities/dvd.hpp"
#include "../menu/menu_option.hpp"
#include "../repositories/rentals_repository.hpp"

using std::cout;
using std::cin;
using std::endl;

class RentDvd : public MenuOption {
    Dvd dvd;
public:
    RentDvd( Dvd dvd );
    void execute(void);
};

#endif
