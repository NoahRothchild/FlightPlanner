#include "airport.h"

Airport::Airport()
{
    avail = true;
    nextCounter = -1;
}

Airport::Airport(const char* rhs)
{
    city = rhs;
    avail = true;
    nextCounter = -1;

}

Airport::Airport(String rhs)
{
    city = rhs;
    avail = true;
    nextCounter = -1;
}

Airport& Airport::operator =( const Airport& rhs)
{
    dests = rhs.dests;
    city  = rhs.city;
    nextCounter = rhs.nextCounter;
    avail = rhs.avail;
    return *this;
}

//an airport is the same if it is in the same city
bool Airport::operator ==(const Airport& rhs)
{
    if(!(city == rhs.city))
        return false;
    return true;
}

bool Airport::noFlight(Flight finder)
{
    for(int x  = 0; x < dests.getLength(); x++)
        if(dests[x] == finder)
            return true;
    return false;
}

void Airport::setNextCounter(int in)
{
    nextCounter = in;
}


int Airport::getNextCounter()
{
    return nextCounter;
}

void Airport::incrementNext()
{
    nextCounter += 1;
}

void Airport::decrementNext()
{
    nextCounter--;
}

Flight Airport::getNext()
{
    if((nextCounter + 1) >= dests.getLength())
        return dests[nextCounter];
    return dests[nextCounter + 1];
}


void Airport::close()
{
    avail = false;
}

void Airport::open()
{
    avail = true;
}

bool Airport::getAvail()
{
    return avail;
}

int Airport::getLength()
{
    return dests.getLength();
}

String Airport::getCity()
{
    return city;
}

void Airport::insert(Flight rhs)
{
    dests.insert(rhs);

}

Flight Airport::operator[](int subscript)
{
    return dests[subscript];
}

Airport::~Airport()
{

}
