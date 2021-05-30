#ifndef RENTAL_HPP
#define RENTAL_HPP

#include <string>

using std::string;
using std::to_string;

class Rental {
    int dvd_id;
    string borrower;
public:
    Rental( Rental * );
    Rental( int, string );
    void setDvdId( int );
    void setBorrower( string );
    int getDvdId(void);
    string getBorrower(void);
    string serialize(void);
};

#endif
