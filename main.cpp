#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include "DSString.h"
#include "linkedlist.h"
#include "linkednode.h"
#include "flight.h"
#include "filemanager.h"
using namespace std;

int main(int argc, char* argv[])
{
    if(argc >= 1 && strcmp(argv[1], "-t") == 0)
    {
        // global setup...

        int result = Catch::Session().run();

        // global clean-up...

        return ( result < 0xff ? result : 0xff );
    }
    FileManager a(argv[1]);
    a.buildCities();
    a.buildRFlights(argv[2]);
    a.print(argv[3]);
    return 0;
}
