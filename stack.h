#ifndef STACK_H
#define STACK_H
#include "linkedlist.h"
#include "DSVector.h"
#include "flight.h"

template <class T>
class Stack
{
    LinkedList<T>  list;

public:
    Stack();


    void push(T);
    T pop();
    T peek();
    bool inStack(T);
    bool isEmpty();
    int getLength();
    void output(Vector<T>&);
    T operator[](int);



    ~Stack();
};

template <class T>
Stack<T>::Stack()
{

}

template <class T>
void Stack<T>::push(T node)
{
    list.insert(node);
}

template <class T>
T Stack<T>::pop()
{
    return list.pop();
}

template <class T>
T Stack<T>::peek()
{
    return list.peek();
}

template <class T>
bool Stack<T>::inStack(T in)
{
    return list.inList(in);
}

template <class T>
bool Stack<T>::isEmpty()
{
    if(getLength() == 0)
        return true;
    else if(getLength() > 0)
        return false;
}

template <class T>
T Stack<T>::operator[](int subscript)
{
    return list[subscript];
}

template <class T>
int Stack<T>::getLength()
{
    return list.getLength();
}

template <class T>
Stack<T>::~Stack()
{

}


#endif // STACK_H
