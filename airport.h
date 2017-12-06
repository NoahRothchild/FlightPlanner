#ifndef AIRPORT_H
#define AIRPORT_H

#include "linkedlist.h"
#include "fstream"
#include <iostream>
#include "DSString.h"
#include "flight.h"
#include "DSVector.h"


//Airport Objects hold a cities name and the possible flights out of the city
//Airports are very instrumental in backtracking
class Airport
{
    //linked lists of flights out of the city
    LinkedList<Flight> dests;

    //name of the city
    String city;

    //iterator used to go throught the flights
    int nextCounter;

    //boolean used to identify if a flight is valid to go on
    bool avail;

public:
    Airport();
    Airport(const char*);
    Airport(String);

    Airport &operator=(const Airport&);
    bool operator==(const Airport&);

    //returns if a flight is in the airport
    bool noFlight(Flight);

    void setNextCounter(int);
    int getNextCounter();
    void incrementNext();
    void decrementNext();
    Flight getNext();

    //make an airport unavailable
    void close();

    //make an airport available
    void open();

    bool getAvail();
    int getLength();
    String getCity();

    //insert a flight into the Airport's LinkedList
    void insert(Flight);

    //return the flight at a certain position in the Airports' LinkedList
    Flight operator[](int);
    ~Airport();
};

#endif // AIRPORT_H
