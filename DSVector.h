#ifndef DSVECTOR_H
#define DSVECTOR_H

#include <iostream>
using namespace std;

template <class T>
class Vector
{
private:
    int len;    //number of elements
    int arrLen; //number of allocated memory
    T* arr;     //arr
    bool cleared; //checks if the vector has been cleared

public:
    Vector<T>();
    Vector<T>(const Vector<T>&);

    T& operator[] (const int) const;
    bool operator> (const Vector&);
    bool operator< (const Vector&);
    bool operator== (Vector&);
    Vector<T>& operator=(const Vector<T>&);

    void empty();
    int findValue(T);
    bool inVector(T);
    void sort();
    void incrementLength();
    void addElement(T);
    void addElement(T, int);
    void removeElement();
    void removeElement(int);
    void swapElements(int, int);

    int getLength();

    ~Vector();

};

template<class T>
Vector<T>::Vector()
{
    arrLen = 5;
    len = 0;
    cleared = false;

}

//copy constructor
template<class T>
Vector<T>::Vector(const Vector<T>& rhs)
{
    this->arrLen  = rhs.arrLen;
    this->len = rhs.len;
    arr = new T[len];
    for(int x = 0; x < len; x ++)
        arr[x] = rhs.arr[x];
    cleared = rhs.cleared;
}

//add element at end of array
template<class T>
void Vector<T>::addElement(T a)
{
    if(len == 0)
        arr = new T[arrLen];
    incrementLength();
    arr[len - 1] = a;
}

//add element at certin position
template<class T>
void Vector<T>::addElement(T a, int pos)
{
    incrementLength();

    //test if it is the first element
    if(len == 1 && pos == 0)
        arr[0] = a;

    //store original in a temporary array
    //interate and add the original back
    //insert the new element at its postion
    //finish off putting the rest of the array back
    else
    {
        T* temp = new T[len-1];
        for(int x  = 0; x < len; x++)
            temp[x] = arr[x];
        delete[] arr;
        arr = new T[len];
        if(pos == 0)
        {
            arr[0] = a;
            for(int y = 1; y < len; y++)
            {
                arr[y] = temp[y-1];

            }

        }
        else
        {
            for(int x  = 0; x < pos-1; x++)
                arr[x] = temp[x];
            arr[pos-1] = a;
            for(int x  = pos; x < len; x++)
                arr[x] = temp[x];
        }
    }
}

//remove element at end of array
template<class T>
void Vector<T>::removeElement()
{
    Vector<T> temp;
    for(int x = 0; x < len-1; x++)
        temp.addElement(arr[x]);
    len--;
    delete[] arr;
    arr = new T[arrLen];
    for(int x  = 0; x < len; x++)
        arr[x] = temp[x];
}

//remove element at certain position
template<class T>
void Vector<T>::removeElement(int pos)
{
    //if position is the last element just call the other function
    if(pos == len -1)
        removeElement();

    //rebuild original array skipping removed element
    else
    {
        T* temp = new T[arrLen];
        for(int x  = 0; x < pos; x++)
            temp[x] = arr[x];
        for(int x = pos; x < len-1; x++)
            temp[x] = arr[x+1];
        len= len -1;
        arr = temp;
    }
}

//empty out the vector
template<class T>
void Vector<T>::empty()
{
    while(len > 0)
        removeElement();
    cleared = true;

}

//swap position of two elements
template<class T>
void Vector<T>::swapElements(int first, int second)
{
    T x  = arr[first];
    T y  = arr[second];
    arr[first] = y;
    arr[second] = x;
}

//return element at certain position
template<class T>
T& Vector<T>::operator[](const int subscript) const
{
    if(subscript < 0)
    {
        return arr[(len + subscript)];
    }
    return arr[subscript];
}

//compare two vectors to find if our this vector is greater assuming they are both sorted
template<class T>
bool Vector<T>::operator> (const Vector& rhs)
{
    bool temp = false;
    for(int x  = 0; x < len; x++)
    {

        if(arr[x] > rhs.arr[x])
        {
            temp = true;
            break;
        }
        if(arr[x] < rhs.arr[x])
            break;
    }
    return temp;
}

//compare two vectors to find if our this vector is greater assuming they are both sorted
template<class T>
bool Vector<T>::operator< (const Vector& rhs)
{
    bool temp = false;
    for(int x  = 0; x < len; x++)
    {

        if(arr[x] < rhs.arr[x])
        {
            temp = true;
            break;
        }
        if(arr[x] > rhs.arr[x])
            break;
    }
    return temp;
}

//compare two vectors to see if they are equivalent assuming they are sorted
template<class T>
bool Vector<T>::operator== ( Vector& rhs)
{
    if (len != rhs.getLength())
        return false;
    for (int x = 0; x < len; x++)
        if (arr[x] != rhs.arr[x])
            return false;
    return true;
}

//asign a vector to be equal to another vector
template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
{
    if(len != 0)
        delete[] arr;
    len  = rhs.len;
    arrLen = rhs.arrLen;
    arr = new T[rhs.arrLen];
    for(int x  = 0; x < len; x++)
        arr[x] = rhs.arr[x];
    cleared = rhs.cleared;
    return *this;

}


//sort the vector in ascending order with a selection sort
template<class T>
void Vector<T>::sort()
{
    for(int x  = 0; x < len - 1; x++)
    {
        for(int y  = x + 1; y < len; y++)
        {
            if(arr[x] > arr[y])
            {
                T temp;
                temp = arr[x];
                arr[x] = arr[y];
                arr[y] = temp;
            }
        }
    }

}

//increase length of memory and check
template<class T>
void Vector<T>::incrementLength()
{
    {
        len = len + 1;
        if(len > arrLen)
        {
            arrLen = arrLen + arrLen;
            T* temp = new T[arrLen];
            for(int x = 0; x < len-1; x++)
                temp[x] = arr[x];
            //
            delete[] arr;
            arr = temp;
        }

    }
}

//return length
template<class T>
int Vector<T>::getLength()
{
    return len;
}


template<class T>
Vector<T>::~Vector()
{
    if(len > 0 || cleared == true)
        delete[] arr;
}


#endif // DSVECTOR_H
