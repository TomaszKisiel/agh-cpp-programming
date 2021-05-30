#include "dvd.hpp"

Dvd::Dvd( Dvd * that ) {
    this->id = that->getId();
    this->title = that->getTitle();
    this->description = that->getDescription();
    this->rating = that->getRating();
    this->duration = that->getDuration();
}

Dvd::Dvd( string title, string desc = "", float rating = 0, int duration = 0 ) {
    this->id = this->generateId();
    this->title = title;
    this->description = desc;
    this->rating = rating;
    this->duration = duration;
}

Dvd::Dvd( int id, string title, string desc = "", float rating = 0, int duration = 0 ) {
    this->id = id;
    this->title = title;
    this->description = desc;
    this->rating = rating;
    this->duration = duration;
}

int Dvd::generateId() {
   static int ID = 0;
   return ++ID;
}

int Dvd::getId( void ) {
    return this->id;
}

string Dvd::getTitle( void ) {
    return this->title;
}

string Dvd::getDescription( void ) {
    return this->description;
}

float Dvd::getRating( void ) {
    return this->rating;
}

int Dvd::getDuration( void ) {
    return this->duration;
}

void Dvd::setTitle( string title ) {
    this->title = title;
}

void Dvd::setDescription( string desc ) {
    this->description = desc;
}

void Dvd::setRating( float rating ) {
    this->rating = rating;
}

void Dvd::setDuration( int duration ) {
    this->duration = duration;
}

string Dvd::serialize(void) {
    return to_string( this->id ) + ";" +
        this->title + ";" +
        this->description + ";" +
        to_string( this->rating ) + ";" +
        to_string( this->duration );
}
