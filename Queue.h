#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H
// declaring Node struct for our Queue class
template<class DType>
struct Node
{
    DType data;
    Node <DType> *next, *prev;
};
//queue class
template <class DType>
class Queue
{
private:
    // decalare head pointer and tail pointer
    Node<DType> *head;
    Node<DType> *tail;
    int count;
    
public:
    // all functions that will be needed in implementation
    Queue();
    Queue(const Queue<DType> &q);
    ~Queue();
    const Queue<DType>& operator=(const Queue<DType> &rhs);
    Node <DType> *CopyList(const Node<DType> *ptr);
    void push_back(const DType &item);
    void push_front(const DType& item);
    DType pop_front();
    DType pop_back();
    void Clear();
    bool isEmpty();
};
 //constructor, declaring variables to NULL
template <class DType>
Queue<DType>::Queue()
{
    count = 0;
    head = nullptr;
    tail = nullptr;
}
// function for the copy constructor
template <class DType>
Node <DType> *CopyList(const Node<DType> *ptr)
{
    if (ptr == nullptr)
    {
        return nullptr;
    }
    else
    {
        Node<DType> * copyFront = new Node<DType>;
        copyFront->item = ptr->item;
        copyFront->next = CopyList(ptr->next);
        return copyFront;
    }
}
//copy constructor
template <class DType>

Queue<DType>::Queue(const Queue<DType> &q)
{
    head = CopyList(q.head);
    tail = head;
    while (tail != nullptr && tail->next != nullptr)
    {
        tail = tail->next;
    }
}
// to delete everything from the queue
template <class DType>
void Queue<DType>::Clear()
{
    Node <DType> *P;
    P = head;
    while (P != nullptr)
    {
        head = head->next;
        delete P;
        P = head;
        count = 0;
        tail = nullptr;
    }
}
// check if queue is empty or not
template <class DType>
bool Queue<DType>::isEmpty()
{
    return (head == nullptr);
}
//destructor
template <class DType>

Queue<DType>::~Queue()
{
    while (!isEmpty())
    {
        Clear();
    }
}
// overloaded assigment operator
template<class DType>

const Queue<DType>& Queue<DType>::operator=(const Queue<DType> &rhs)
{
    if (this != &rhs)
    {
        if (!isEmpty())
        {
            Clear();
        }
        head = CopyList(rhs.head);
        tail = head;
        while (tail != nullptr && tail->next != nullptr)
        {
            tail = tail->next;
        }
    }
    return *this;
}
// function to push variable into front of the queue
template<class DType>
void Queue<DType>::push_front(const DType& item)
{
    if (count == 0)
    {
        head = new Node <DType>;
        head->data = item;
        head->next = head->prev = nullptr;
        tail = head;
        count = 1;
    }
    else
    {
        head->prev = new Node<DType>;
        head->prev->next = head;
        head->data = item;
        head = head->prev;

        head->prev = nullptr;
        count++;
    }

}
// push value into back of the queue
template <class DType>
void Queue<DType>::push_back(const DType &item)
{
    if (count == 0)
    {
        push_front(item);
    }
    else
    {
        tail->next = new Node<DType>;
        tail->next->prev = tail;
        tail = tail->next;
        tail->data = item;
        tail->next = nullptr;
        count++;
    }
}
// pop the front value from the queue
template<class DType>
DType Queue<DType>::pop_front()
{
    Node<DType> *P = head;
    DType item = head->data;
    head = head->next;
    delete P;
    count--;
    if (count == 0)
    {
        tail = nullptr;
    }
    return item;
}
// pop last value from the queue
template<class DType>
DType Queue<DType>::pop_back()
{
    Node<DType> *P = tail;
    DType item = tail->data;
   tail = tail->prev;
    delete P;
    count--;
    if (count == 0)
    {
        head = nullptr;
    }
    return item;
}

#endif