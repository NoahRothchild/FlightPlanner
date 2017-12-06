#include "rflights.h"

rFlights::rFlights()
{
    real = true;
}

rFlights::rFlights(char* ori, char* des, char t)
{
    origin  = ori;
    dest = des;
    type = t;
    setReal(true);
}

void rFlights::setOrigin(char* ori)
{
    origin  = ori;
}

void rFlights::setDest(char* des)
{
    dest  = des;
}

void rFlights::setType(char t)
{
    type = t;
}

void rFlights::setReal(bool in)
{
    real = in;
}

String rFlights::getOrigin()
{
    return origin;
}

String rFlights::getDest()
{
    return dest;
}

char rFlights::getType()
{
    return type;
}

bool rFlights::getReal()
{
    return real;
}

rFlights::~rFlights()
{

}
