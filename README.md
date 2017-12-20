The flight data information file should be formatted with the number of flights in the first line.
Each line after that should look like this: location|location|cost|time
The flgihts work on the assumption that each flight has an opposite counterpart going and does not factor in lay-overs
Example:
4
CVG|DFW|100|150
DFW|MCO|120|170
MCO|JFK|250|100
JFK|CVG|200|135

The requested flights file should also start with the number of requests
Each line after should look like this: origin|destination|(T or C base on what to sort by)
Example:
2
CVG|MCO|T
DFW|JFK|C
