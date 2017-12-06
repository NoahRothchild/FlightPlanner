#ifndef DSSTRING_H
#define DSSTRING_H

#include <iostream>
#include <cstring>
#include "stdlib.h"

class String
{
private:
    int len;
    char* arr;

public:
    String();
    String(const char*);
    String(const String&);

    bool operator>(const String&);
    bool operator<(const String&);
    String& operator=(const char*);
    String& operator=(const String&);
    String operator+(const String&);
    String operator-(const char);
    bool operator==(const char*);
    bool operator==(const String&);
    char& operator[](const int);

    int toInt();
    String symbolRemover();
    String lowerCaser();
    String UpperCaser();
    String substring(int, int);
    int size() const;
    char* c_str() const;

    ~String();

    friend std::ostream& operator<< (std::ostream&, const String&);


};

#endif // DSSTRING_H
