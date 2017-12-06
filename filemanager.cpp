#include "filemanager.h"
#include <cstring>
#include "string.h"


FileManager::FileManager()
{
    number = 0;
}

//read in flight data file
FileManager::FileManager(const char* input)
{
    //open text file
    ifstream flightData;
    flightData.open(input, ifstream::in);
    if (!flightData) {
        cerr << "open failed" << endl;
        exit(1);
    }

    //read in the number of flights
    char* numBuf = new char[15];
    flightData.getline(numBuf,15,'\n');
    String tempNum = numBuf;
    number = tempNum.toInt();
    delete[] numBuf;

    for(int x  = 0; x < number; x++)
    {
        //get flight line
        Flight insert;

        //get origin location
        char* origin = new char[40];
        flightData.getline(origin, 40, '|');
        insert.setOrigin(origin);
        delete[] origin;

        //get destination location
        char* dest = new char[40];
        flightData.getline(dest, 40, '|');
        insert.setDest(dest);
        delete[] dest;

        //get cost
        char* cost = new char[15];
        flightData.getline(cost, 15, '|');
        tempNum = cost;
        insert.setCost(tempNum.toInt());
        delete[] cost;

        //get time
        char* time = new char[15];
        flightData.getline(time, 15, '\n');
        tempNum = time;
        insert.setMin(tempNum.toInt());
        delete[] time;

        //push flight onto list
        flights.insert(insert);

    }

    //close the text file
    flightData.close();
}

//build the adjacency list
void FileManager::buildCities()
{
    //build airport objects based on origins
    for(int x  = 0; x < number; x++)
    {
        Airport temp = flights[x].getOrigin();

        //check to make sure the airport doesn't already exsist
        if(findAirport(flights[x].getOrigin()) > -1)
        {
            cities[findAirport(flights[x].getOrigin())].insert(flights[x]);
        }

        //the airport already exsists, just tack the flight onto it
        else
        {
            cities.addElement(temp);
            cities[findAirport(flights[x].getOrigin())].insert(flights[x]);
        }
    }

    //build airport objects based on destinations
    for(int x  = 0; x < number; x++)
    {
        Flight temp;
        temp.setOrigin(flights[x].getDest().c_str());
        temp.setDest(flights[x].getOrigin().c_str());
        temp.setCost(flights[x].getCost());
        temp.setMin(flights[x].getMin());

        Airport tempAir(temp.getOrigin().c_str());

        //check to make sure the airport doesn't already exsist
        if(findAirport(temp.getOrigin()) > -1)
        {
            cities[findAirport(temp.getOrigin())].insert(temp);
        }

        //the airport already exsists, just tack the flight onto it
        else
        {
            cities.addElement(tempAir);
            cities[findAirport(temp.getOrigin())].insert(temp);
        }
    }

}

//fine the subscript of an airport in the adj list
int FileManager::findAirport(String rhs)
{
    for(int x  = 0; x < cities.getLength(); x++)
        if(cities[x].getCity() == rhs)
            return x;
    return -1;
}

//build a vector of the requested flights
void FileManager::buildRFlights(char* input)
{
    //open the file and make sure it exsists
    ifstream flightPlan;
    flightPlan.open(input, ifstream::in);
    if (!flightPlan) {
        cerr << "open failed" << endl;
        exit(1);
    }

    //get the number of requested flights
    char* numBuf = new char[15];
    flightPlan.getline(numBuf, 15, '\n');
    String tempNum = numBuf;
    rNumber= tempNum.toInt();
    delete[] numBuf;

    for(int x  = 0; x < rNumber; x++)
    {
        rFlights insert;

        //get origin location
        char* origin = new char[40];
        flightPlan.getline(origin, 40, '|');
        insert.setOrigin(origin);
        delete[] origin;


        //get destination location
        char* dest = new char[40];
        flightPlan.getline(dest, 40, '|');
        insert.setDest(dest);
        delete[] dest;


        //get sort type
        char* tp = new char[2];
        flightPlan.getline(tp, 2, '\n');
        insert.setType(tp[0]);

        if(tp[0] == '\0')
            insert.setReal(false);

        delete[] tp;

        //set internal bool equal to true


        //push the requested flights to the reqFlights vector
        reqFlights.insert(insert);

    }
    flightPlan.close();

}

//build your flight options
void FileManager::findOptions(rFlights input)
{
    if(findAirport(input.getOrigin()) == -1)
        return;
    if(findAirport(input.getDest()) == -1)
        return;

    //stack used for iterative backtracking
    Stack<Airport> places;

    //index location of the origin location in the adj list
    int origin  = findAirport(input.getOrigin());
    Airport location(cities[origin]);
    location.close();

    //make the origin city unavailable in the adj city
    cities[origin].close();
    places.push(location);
    while(!places.isEmpty())
    {
        //make copy of ariport on the end of stack
        Airport temp = cities[findAirport(places.peek().getCity())];
        //increment the nextCounter of the airport in the Adj list that is last on the stack
        cities[findAirport(places.peek().getCity())].incrementNext();

        //if temp airport is the same as the destimation and the length of the stack is greater than one
        //copy the stack to options for later
        if(temp.getCity() == input.getDest() && places.getLength() > 1)
        {
            options.addElement(places);
            cities[findAirport(input.getDest())].open();
            cities[findAirport(input.getDest())].setNextCounter(-1);
            places.pop();
        }

        //if the temp airport's indexs are as long it can access
        //pop the temp airport and reset it so it can be checked later
        else if(temp.getNextCounter()+1 >= temp.getLength())
        {
            Airport reset = places.pop();
            cities[findAirport(reset.getCity())].open();
            cities[findAirport(reset.getCity())].setNextCounter(-1);
        }

        //if the next next flight is available to fly to push it and make it unavailable
        else if(cities[findAirport(temp.getNext().getDest())].getAvail() == true)
        {
            places.push(cities[findAirport(temp.getNext().getDest())]);
            cities[findAirport(temp.getNext().getDest())].close();
        }

    }

    //reset the nextCounter and availability of my adj list items
    for(int x  = 0; x < cities.getLength(); x++)
    {
        cities[x].setNextCounter(-1);
        cities[x].open();
    }

}

//print your sorted flight paths
void FileManager::print(const char* output)
{
    //check to see if the file opened
    fstream outFile;
    outFile.open(output, ifstream::out);
    if (!outFile) {
        cerr << "open failed" << endl;
        exit(1);
    }

    for(int x  = 0; x < rNumber; x++)
    {
        //get the possible flights for this requested flight
        findOptions(reqFlights[x]);

        //build our sortable objects
        for(int y = 0; y < options.getLength(); y++)
        {
            Vector<Flight> sorter;
            createSortOptions(options[y]);
        }

        //sort the sortable objects
        sortOptions(reqFlights[x].getType());

        //read out to the file and check to see if they asked for more flights than they gave
        if(reqFlights[x].getReal() == true)
        {
            //print initital information
            outFile << "Flight " << x + 1<<  ": " << reqFlights[x].getOrigin() << ", " << reqFlights[x].getDest() << " (";
            if(reqFlights[x].getType() == 'C')
                outFile << "Cost)" << endl;
            else if(reqFlights[x].getType() == 'T')
                outFile << "Time)" << endl;

            //check if there are connecting flights
            if(sortableOptions.getLength() == 0)
                outFile << "          no flights" << endl;

            for(int y  = 0; y < sortableOptions.getLength(); y++)
            {
                if(y == 3)
                    break;
                outFile << "Path " << y +1 << ": ";
                outFile << sortableOptions[y];
                outFile << endl;
            }
        }

        //if the requested flight wasn't ever made, continue the loop
        else
            continue;

        //reset our options and sortable options vectors
        options.empty();
        sortableOptions.empty();
        outFile << endl;
    }
    outFile.close();
}

//create vectors to allow you to sort
void FileManager::createSortOptions(Stack<Airport> in)
{
    flightOptions sorter;
    for(int x  = 0; x < in.getLength()-1; x++)
    {
        Flight temp = findFlights(in[x].getCity(),in[x+1].getCity());
        sorter.addFlight(temp);

    }
    sortableOptions.addElement(sorter);

}

//sort the sortable vectors in ascending order
void FileManager::sortOptions(char sT)
{
    for(int x = 0; x < options.getLength()-1; x++)
    {
        for(int y  = x+1; y < options.getLength(); y++)
        {
            //sort by cost
            if(sT == 'C')
            {
                if(sortableOptions[x].getCost() > sortableOptions[y].getCost())
                    sortableOptions.swapElements(x,y);
                else if(sortableOptions[x].getCost() == sortableOptions[y].getCost()
                        && sortableOptions[x].getTime() > sortableOptions[y].getTime())
                    sortableOptions.swapElements(x,y);
            }
            //sort by time
            else if(sT == 'T')
            {
                if(sortableOptions[x].getTime() > sortableOptions[y].getTime())
                    sortableOptions.swapElements(x,y);
                else if(sortableOptions[x].getTime() == sortableOptions[y].getTime()
                        && sortableOptions[x].getCost() > sortableOptions[y].getCost())
                    sortableOptions.swapElements(x,y);
            }
        }
    }
}

//find the index of a flight in an airport
Flight FileManager::findFlights(String ori, String des)
{
    int airPlace = findAirport(ori);
    for(int x  = 0; x < cities[airPlace].getLength(); x++)
    {
        if(cities[airPlace][x].getDest() == des)
            return cities[airPlace][x];
    }
    return cities[airPlace][0];
}


FileManager::~FileManager()
{

}
