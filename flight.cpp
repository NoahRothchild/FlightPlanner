#include "flight.h"

Flight::Flight()
{
}

Flight::Flight(char* ori, char* des, int cos, int time)
{
    origin = ori;
    dest = des;
    cost = cos;
    min = time;
}

Flight::Flight(const Flight & rhs)
{
    origin  = rhs.origin;
    dest = rhs.dest;
    cost = rhs.cost;
    min = rhs.min;
}


Flight& Flight::operator=(const Flight& rhs)
{
    origin  = rhs.origin;
    dest = rhs.dest;
    cost = rhs.cost;
    min = rhs.min;
    return *this;
}

//if any of the variable aren't equal, return false;
bool Flight::operator==(const Flight& rhs)
{
    if(!(origin == rhs.origin))
        return false;
    if(!(dest == rhs.dest))
        return false;
    if(cost != rhs.cost)
        return false;
    if(min != rhs.min)
        return false;
    return true;
}

String Flight::getOrigin()
{
    return origin;
}

String Flight::getDest()
{
    return dest;
}

int Flight::getCost()
{
    return cost;
}

int Flight::getMin()
{
    return min;
}

void Flight::setOrigin(char* ori)
{
    origin = ori;
}

void Flight::setDest(char* destination)
{
    dest  = destination;
}

void Flight::setCost(int co)
{
    cost = co;
}

void Flight::setMin(int mi)
{
    min = mi;
}

Flight::~Flight()
{

}
