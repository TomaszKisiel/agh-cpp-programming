#ifndef DVD_HPP
#define DVD_HPP

#include <string>

using std::string;
using std::to_string;

class Dvd {
    int id;
    string title;
    string description;
    float rating; // 0 - 5 scale
    int duration; // in seconds
    static int generateId();
public:
    Dvd( Dvd * );
    Dvd( string, string, float, int );
    Dvd( int, string, string, float, int );
    int getId( void );
    string getTitle( void );
    string getDescription( void );
    float getRating( void );
    int getDuration( void );
    void setTitle( string );
    void setDescription( string );
    void setRating( float );
    void setDuration( int );
    string serialize(void);
};

#endif
