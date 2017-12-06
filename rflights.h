#ifndef RFLIGHTS_H
#define RFLIGHTS_H
#include "DSString.h"

//objects that track the requested flights
class rFlights
{
    String origin;
    String dest;
    //type is either C or T indicating the type of sort wanted
    char type;
    //checks if the requ flight is real;
    bool real;
public:
    rFlights();
    rFlights(char*, char*, char);

    void setOrigin(char*);
    void setDest(char*);
    void setType(char);
    void setReal(bool);

    String getOrigin();
    String getDest();\
    char getType();
    bool getReal();

    ~rFlights();
};

#endif // RFLIGHTS_H
