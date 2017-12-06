#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include "linkedlist.h"
#include "linkednode.h"
#include "DSString.h"
#include "flight.h"
#include "stack.h"
#include "fstream"
#include "DSVector.h"
#include "airport.h"
#include "rflights.h"
#include "flightoptions.h"

using namespace std;

//This is the flight Planer
//it is used to assemeble the information generate the possible flight paths
class FileManager
{
    //number of original read in flights
    int number;

    //number of requested flights
    int rNumber;

    //List of possible original flights
    LinkedList<Flight> flights;

    //list of requested flights
    LinkedList<rFlights> reqFlights;

    //FILO list of flights
    Stack<Flight> pile;

    //vector of the possible routes that could be taken
    Vector<Stack<Airport>> options;

    //vector of the airports Generated
    //cities also holds the inverse flights
    Vector<Airport> cities;

    //vector of objects that allows us to sort the flights by cost or time
    Vector<flightOptions> sortableOptions;

public:
    FileManager();
    FileManager(const char*);

    //return an int associtated with the index of the city a flight leaves from
    int findAirport(String);

    //builds the cities vectors
    void buildCities();

    //builds the rFlights List
    void buildRFlights(char*);

    //iterativley backtracks to find the possible routes to fly
    void findOptions(rFlights);

    //sort the sortable vecorts by cost or time
    void sortOptions(char );

    //takes in an origin and dest and finds the flight between two ariports in the cities vector
    Flight findFlights(String, String);

    //prints the possible flights to a txt file
    void print(const char*);

    //create the sortable objects vector
    void createSortOptions(Stack<Airport>);

    ~FileManager();
};

#endif // FILEMANAGER_H
