#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "linkednode.h"
#include <iostream>
#include "DSVector.h"
using namespace std;

template <class T>
class LinkedList
{
    LinkedNode<T>* root;
    LinkedNode<T>* end;
    int length = 0;
    void linsert(T);

public:
    LinkedList();
    LinkedList(const LinkedList&);

    LinkedList<T> &operator=(const LinkedList&);
    bool operator==(const LinkedList&);
    T operator[](const int);

    void insert(T, int);
    void remove(int);
    bool emptyNext();
    bool inList(T);
    void output(Vector<T>&);
    bool isEmpty();
    int getLength();
    void remove();
    T pop();
    T peek();
    void insert(T);
    void print();
    ~LinkedList();

};

//private insert method
template<class T>
void LinkedList<T>::linsert(T in)
{


    if(root == nullptr)
    {
        LinkedNode<T>* head = new LinkedNode<T>(in);
        head->prev = nullptr;
        head->next = nullptr;
        root = head;
        end  = head;
    }
    else
    {
        LinkedNode<T>* tail = new LinkedNode<T>(in);
        //        LinkedNode<T>* temp = end;
        tail->prev = end;
        tail->next = nullptr;
        end->next = tail;
        end = tail;
    }
}

//default constructor
template <class T>
LinkedList<T>::LinkedList()
{
    root = nullptr;
    length = 0;
    end = nullptr;
}

//copy constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList& rhs)
{
    if(rhs.length == 1)
    {
        root = new LinkedNode<T>(rhs.root->data);
        end = root;
        length = rhs.length;
    }
    else if(rhs.length > 1)
    {
        root = new LinkedNode<T>(rhs.root->data);
        end = rhs.end;
        length = rhs.length;
        LinkedNode<T>* rhsTemp = rhs.root;
        LinkedNode<T>* temp = root;
        LinkedNode<T>* set ;
        int counter = 0;
        while(counter < length-1)
        {
            rhsTemp = rhsTemp->next;
            set = new LinkedNode<T>(rhsTemp->data);
            set->prev = temp;
            temp->next = set;
            temp = set;
            counter++;
        }
        end = set;
        end->next = nullptr;
    }

}

//assignment operator
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& rhs)
{
    if(rhs.length == 1)
    {
        root = new LinkedNode<T>(rhs.root->data);
        end = root;
        length = rhs.length;
    }
    else if(rhs.length > 1)
    {
        root = new LinkedNode<T>(rhs.root->data);
        end = rhs.end;
        length = rhs.length;
        LinkedNode<T>* rhsTemp = rhs.root;
        LinkedNode<T>* temp = root;
        LinkedNode<T>* set ;
        int counter = 0;
        while(counter < length-1)
        {
            rhsTemp = rhsTemp->next;
            set = new LinkedNode<T>(rhsTemp->data);

            set->prev = temp;
            temp->next = set;
            temp = set;
            counter++;
        }
        end = set;
        end->next = nullptr;
    }
    return *this;

}

//public insert operator
template <class T>
void LinkedList<T>::insert(T in)
{
    length++;
    linsert(in);
}

//insert a node at the position given
template <class T>
void LinkedList<T>::insert(T in, int pos)
{
    length++;
    //add node to front of list
    if(pos == 0)
    {
        LinkedNode<T>* head = new LinkedNode<T>(in);
        head->next = root;
        root->prev = head;
        root = head;
        root->prev = nullptr;
    }
    //add node to end of list
    else if(pos == (length - 1))
    {
        insert(in);
    }
    //insert into middle
    else
    {
        LinkedNode<T>* inserter = new LinkedNode<T>(in);
        LinkedNode<T>* tempFront = root;

        for(int x  = 0; x < pos; x ++)
        {
            tempFront = tempFront->next;
        }
        LinkedNode<T>* tempEnd = tempFront->next;
        tempFront->next = inserter;
        inserter->prev = tempFront;
        tempEnd->prev = inserter;
        inserter->next = tempEnd;
    }


}

//equals operator
template <class T>
bool LinkedList<T>::operator==(const LinkedList& rhs)
{
    if(length != rhs.length)
        return false;
    LinkedNode<T>* temp = root;
    LinkedNode<T>* rhsTemp = rhs.root;
    for(int x  = 0; x < length; x++)
    {
        if(temp->data != rhsTemp->data)
            return false;
        temp = temp->next;
        rhsTemp = rhsTemp->next;
    }
    return true;
}

//see if Object T is in the list
template <class T>
bool LinkedList<T>::inList(T in)
{
    LinkedNode<T>* finder = root;
    for(int x = 0; x < length; x++)
    {
        if(finder->getData() == in)
            return true;
        finder = finder->next;
    }
    return false;
}

//data at specific index
template <class T>
T LinkedList<T>::operator[](const int subscript)
{
    LinkedNode<T>* returner = root;
    for(int x = 0; x < subscript; x++)
    {
        returner = returner->next;
    }
    return returner->data;
}

//remove the last node on the list
template <class T>
void LinkedList<T>::remove()
{
    LinkedNode<T>* temp = end->prev;
    end->prev = nullptr;
    delete end;
    end = temp;
    end->next = nullptr;
    length--;
}

//remove the node at position pos
template <class T>
void LinkedList<T>::remove(int pos)
{
    //insert at beginning
    if(pos == 0)
    {
        LinkedNode<T>* head  = root;
        root = root->next;
        head->next = nullptr;
        delete head;
        length--;
    }
    else if(pos != (length-1))
    {
        LinkedNode<T>* temp = root;
        for(int x  = 0; x < pos; x++)
        {
            temp = temp->next;
        }

        LinkedNode<T>* previous = temp->prev;
        LinkedNode<T>* tempNext = temp->next;
        tempNext->prev = previous;
        previous->next = tempNext;
        temp->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        length--;
    }
    else
        remove();

}

//remove the last item on the list and return its contents
template <class T>
T LinkedList<T>::pop()
{
    T returner = end->data;
    LinkedNode<T>* temp = end->prev;
    end->prev = nullptr;
    delete end;
    end = temp;
    if(length > 1)
        end->next = nullptr;
    length--;
    return returner;
}

//view the last object in the list
template <class T>
T LinkedList<T>::peek()
{
    return end->data;
}

//check to see if the list is empty
template <class T>
bool LinkedList<T>::isEmpty()
{
    if(root == nullptr)
        return true;
    else
        return false;
}

//print linked list
template <class T>
void LinkedList<T>::print()
{
    LinkedNode<T>* printer = root;
    for(int x = 0; x < length; x++)
    {
        cout << printer->data << endl;
        printer = printer->next;
    }
}

template <class T>
int LinkedList<T>::getLength()
{
    return length;
}

//destructor
template <class T>
LinkedList<T>::~LinkedList()
{
    //inorder to correctly destruct we must delete each node individually
    LinkedNode<T>* temp = end;
    for(int x  = length; x > 0; x--)
    {
        LinkedNode<T>* prevTemp = temp->prev;
        temp->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        temp = prevTemp;
    }
}

#endif // LINKEDLIST_H
