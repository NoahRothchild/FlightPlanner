#ifndef FLIGHTOPTIONS_H
#define FLIGHTOPTIONS_H

#include "stack.h"
#include "flight.h"
#include "airport.h"
#include "DSVector.h"
#include "DSString.h"

//flight options is useful for connecting flights together
class flightOptions
{
private:
    //number of flights
    int number;
    //total cost
    int cost;
    //total time
    int time;
    //a vector of flights that connect together
    Vector<Flight> trail;

public:
    flightOptions();
    flightOptions(const flightOptions&);

    flightOptions& operator=(const flightOptions&);

    void addFlight(Flight);
    void addCost();
    void addTime();

    //return the  trail of flights
    Vector<Flight> getFlights();
    int getCost();
    int getTime();
    int getLen();

    friend std::ostream& operator<< (std::ostream&, flightOptions&);

    ~flightOptions();
};

#endif // FLIGHTOPTIONS_H
