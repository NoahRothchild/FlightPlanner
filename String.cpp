#include "DSString.h"
#include <cstring>
#include <iostream>

using namespace std;


String::String()
{
    len = 0;
    arr = new char[1];
}

String::String(const char* address)
{
    this->len = strlen(address);
    arr = new char[len+1];
    strcpy(arr, address);
    arr[len] = '\0';
}

String::String(const String& rhs)
{
    this->len = rhs.len;
    arr = new char[len+1];
    strcpy(arr, rhs.arr);
    arr[len] = '\0';
}

bool String::operator>(const String& rhs)
{
    String lowerLHS = lowerCaser();
    String lowerRHS = rhs;
    lowerRHS = lowerRHS.lowerCaser();
    bool temp = false;
    for(int x  = 0; x < len; x++)
    {

        if(lowerLHS[x] < lowerRHS[x])
        {
            temp = true;
            break;
        }
        if(lowerLHS[x] > lowerRHS[x])
            break;
    }
    return temp;
}

bool String::operator<(const String& rhs)
{
    String lowerLHS = this->lowerCaser();
    String lowerRHS = rhs;
    lowerRHS = lowerRHS.lowerCaser();
    bool temp = false;
    for(int x  = 0; x < len; x++)
    {

        if(lowerLHS[x] > lowerRHS[x])
        {
            temp = true;
            break;
        }
        if(lowerLHS[x] < lowerRHS[x])
            break;
    }
    return temp;
}


String& String::operator= (const char* rhs)
{
    delete[] arr;
    len = strlen(rhs);
    arr = new char[len+1];
    strcpy(arr, rhs);
    arr[len] = '\0';
    return *this;
}


String& String::operator= (const String& rhs)
{
    delete[] arr;
    this->len = rhs.len;
    arr = new char[len+1];
    strcpy(arr, rhs.arr);
    arr[len] = '\0';
    return *this;
}

//MEF: + should not modify the envoking object. Should return
//a new string that is the concatenation of the two operands.
//This is kind of like +=
String String::operator+ (const String& rhs)
{
    //check to see if first string is empty
    if (len == 0)
    {
        String temp = rhs;
        return temp;
    }

    //add both strings together
    int olen = len;
    len = olen + rhs.size();
    String temp = *this;
    delete[] arr;
    //MEF: Added a +1 here
    arr = new char[len + 1];
    for(int x  = 0; x < olen; x++)
        arr[x] = temp[x];
    for (int x = olen; x < len; x ++)
        arr[x] = rhs.arr[x-olen];
    //MEF: Null Terminate
    arr[len] = '\0';
    return *this;
}

String String::operator-(char rhs)
{
    int num = 10;
    int* positions = new int[num];
    int counter = 0;
    for(unsigned int x  = 0; x < strlen(arr); x++)
    {
        if(arr[x] == rhs)
        {
            positions[counter] = x;
            counter++;
            if(counter == num -1)
            {
                num = num + num;
                int* posReplace = new int[num];
                for(int x  = 0; x < counter; x++)
                    posReplace[x] = positions[x];
                delete[] positions;
                positions = posReplace;
            }
        }
    }
    char* temp = new char[strlen(arr) - counter];
    int counter2 = 0;
    for(unsigned int x = 0; x < strlen(arr); x++)
    {
        if(x == positions[counter2])
        {
            counter2++;
        }
        else
        {
            temp[x - counter2] = arr[x];
        }
    }
    String returner(temp);
    delete[] temp; // assuming the constructor makes a deep copy
    delete[] positions;
    return returner;
}



bool String::operator== (const char* rhs)
{
    String copy = rhs;
    if (len != copy.size())
        return false;
    for (int x = 0; x < len; x++)
        if (arr[x] != copy.arr[x])
            return false;
    return true;
}

bool String::operator== (const String& rhs)
{
    if (len != rhs.size())
        return false;
    for (int x = 0; x < len; x++)
        if (arr[x] != rhs.arr[x])
            return false;
    return true;
}

char& String::operator[] (const int subscript)
{

    if(subscript < 0)
    {
        return arr[(len + subscript)];
    }
    return arr[subscript];
}

int String::toInt()
{
    return atoi(c_str());
}

String String::symbolRemover()
{
    //    lowerCaser();
    bool nonLoN = true;
    while(nonLoN)
    {
        char temp = arr[0];
        if(temp > 122 || (temp < 97 && temp > 89) || (temp < 65 && temp > 57) ||  temp < 48)
            *this = substring(1,len);
        else
            nonLoN = false;
    }
    nonLoN = true;
    while(nonLoN)
    {
        char temp = arr[len - 1];
        if(temp > 122 || (temp < 97 && temp > 89) || (temp < 65 && temp > 57) ||  temp < 48)
            *this = substring(0,len-1);
        else
            nonLoN = false;
    }

    return *this;
}

String String::lowerCaser()
{
    String temp;
    for(int x = 0; x < len; x++)
    {
        if (arr[x] > 64 && arr[x] < 91 )
            arr[x] = arr[x] + 32;
    }
    temp = arr;
    return temp;
}

String String::UpperCaser()
{
    String temp;
    for(int x = 0; x < len; x++)
    {
        if (arr[x] > 96 && arr[x] < 123 )
            arr[x] = arr[x] - 32;
    }
    temp = arr;
    return temp;

}

String String::substring(int start, int end)
{
    String returning;
    if(start<0)
    {
        start  = len + start +1;
    }

    if(end < 0)
        end  = len + end+1;


    int tempLen = (end - start);
    char* tempArr = new char[tempLen+1];


    for (int x = start; x < end; x++)
        tempArr[x-start] = arr[x];


    tempArr[tempLen] = '\0';

    returning = tempArr;

    return returning;

}

int String::size() const
{
    return len;
}

char *String::c_str() const
{
    return arr;
}

String::~String()
{
    delete[] arr;
}

std::ostream& operator<< (std::ostream& o, const String& str)
{
    //    for(int )
    o << str.c_str();
    return o;
}


