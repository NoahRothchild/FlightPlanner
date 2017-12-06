#include "flightoptions.h"

flightOptions::flightOptions()
{
    cost = 0;
    time = 0;
    number = 0;
}

flightOptions::flightOptions(const flightOptions & rhs)
{
    cost  = rhs.cost;
    time = rhs.time;
    number = rhs.number;
    trail = rhs.trail;
}

flightOptions& flightOptions::operator=(const flightOptions& rhs)
{
    number = rhs.number;
    cost  = rhs.cost;
    time = rhs.time;
    trail = rhs.trail;
    return *this;
}

void flightOptions::addFlight(Flight insert)
{
    trail.addElement(insert);
    number++;
    cost+=insert.getCost();
    time+=insert.getMin();
}

void flightOptions::addCost()
{
    for(int x  = 0; x < number; x++)
    {
        cost += trail[x].getCost();
    }
}

void flightOptions::addTime()
{
    for(int x  = 0; x < number; x++)
    {
        time += trail[x].getMin();
    }
}

Vector<Flight> flightOptions::getFlights()
{
    return trail;
}

int flightOptions::getCost()
{
    return cost;
}

int flightOptions::getTime()
{
    return time;
}

int flightOptions::getLen()
{
    return number;
}

std::ostream& operator<< (std::ostream& o,  flightOptions& out)
{
    o << out.getFlights()[0].getOrigin();
    for(int x = 0; x < out.getLen(); x++)
    {
        o <<  " -> " << out.getFlights()[x].getDest();
    }
    o << ". Time: " << out.getTime() << " Cost: " << out.getCost();

    return o;
}

flightOptions::~flightOptions()
{

}



