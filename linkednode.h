#ifndef LINKEDNODE_H
#define LINKEDNODE_H
#include <iostream>


template <class T>
class LinkedNode
{
private:
    //allow Linked List to acces private variable
    template <class U> friend class LinkedList;
    //actual information wanted to store
    T data;
    //pointer to the next node in sequence
    LinkedNode<T>* next;
    //point to previous node in sequence
    LinkedNode<T>* prev;
public:
    LinkedNode();
    LinkedNode(T, LinkedNode* , LinkedNode*);
    LinkedNode(T);
    LinkedNode(const LinkedNode&);

    LinkedNode& operator=(const LinkedNode&);

    void setPrev(LinkedNode*);
    void setNext(LinkedNode*);
    T getData() const;
    ~LinkedNode();

    template <class U>
    friend std::ostream& operator << (std::ostream&, const LinkedNode<U>&);
};

template <class T>
LinkedNode<T>::LinkedNode()
{
    data = NULL;
    next = nullptr;
    prev = nullptr;
}

template <class T>
LinkedNode<T>::LinkedNode(T in)
{
    data = in;
    next = nullptr;
    prev = nullptr;
};

template <class T>
LinkedNode<T>::LinkedNode(T a,  LinkedNode<T>* n, LinkedNode<T>* p)
{
    data = a;
    next = n;
    prev = p;
}

template <class T>
LinkedNode<T>::LinkedNode(const LinkedNode<T> & rhs)
{
    this->data = rhs.data;
    this->next = rhs.next;
    this->prev = rhs.prev;
}

template <class T>
LinkedNode<T>& LinkedNode<T>::operator=(const LinkedNode<T>& rhs)
{
    data = rhs.data;
    next = rhs.next;
    prev = rhs.prev;

}

template <class T>
void LinkedNode<T>::setPrev(LinkedNode<T>* back)
{
    prev = back;
}

template <class T>
void LinkedNode<T>::setNext(LinkedNode<T> * n)
{
    next  = n;
}

template <class T>
T LinkedNode<T>::getData() const
{
    return data;
}

template <class T>
LinkedNode<T>::~LinkedNode()
{

}

template <class T>
std::ostream& operator<< (std::ostream& o, const LinkedNode<T>& in)
{
    o << in.getData();
    return o;
}

#endif // LINKEDNODE_H
