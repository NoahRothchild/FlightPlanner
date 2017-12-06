#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include "linkedlist.h"
#include "DSString.h"

//Flights are objects that hold to locations and the cost and time to take this path
class Flight
{
private:
    //
    String origin;
    String dest;
    int cost;
    int min;


public:
    Flight();
    Flight(char *, char *, int, int);
    Flight(const Flight&);

    Flight& operator=(const Flight&);
    bool operator==(const Flight&);

    String getOrigin();
    String getDest();
    int getCost();
    int getMin();

    void setOrigin(char*);
    void setDest(char*);
    void setCost(int);
    void setMin(int);

    ~Flight();

};

#endif // FLIGHT_H
