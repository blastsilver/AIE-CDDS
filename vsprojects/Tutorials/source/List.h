#pragma once
#include <memory>

template<typename T> class List
{
public:
    struct Node { T value; Node *prev, *next; };

    List() { this->_init(); };
    ~List() { this->clear(); }
    List(const List & other) { this->_init(); this->_copy(other) };
    void operator=(const List & other) { this->_copy(other) };

    // check if empty
    bool empty() { return !this->head || !this->tail; };
    // delete the list nodes
    void clear() { while (!this->empty()) this->popFront(); this->_init(); };
    // delete value from the tail
    void popBack()
    {
        Node * temp = this->tail;
        // check if empty
        if (temp == nullptr) return;
        // set tail to the prev
        this->tail = this->tail->prev;
        // check if tail is empty
        if (this->tail == nullptr) this->head = nullptr;
        // delete the node
        delete temp;
    };
    // delete value from the head
    void popFront()
    {
        Node * temp = this->head;
        // check if empty
        if (temp == nullptr) return;
        // set head to the next
        this->head = this->head->next;
        // check if head is empty
        if (this->head == nullptr) this->tail = nullptr;
        // delete the node
        delete temp;
    };
    // push new value to the tail
    void pushBack(const T & value)
    {
        Node * temp = new Node{ value, this->tail, nullptr };
        // check if head is empty
        if (this->head == nullptr) this->head = temp;
        // check if tail is not empty
        if (this->tail != nullptr) this->tail->next = temp;
        // add node to tail
        this->tail = temp;
    };
    // push new value to the head
    void pushFront(const T & value)
    {
        Node * temp = new Node{ value, nullptr, this->head };
        // check if tail is empty
        if (this->tail == nullptr) this->tail = temp;
        // check if head is not empty
        if (this->head != nullptr) this->head->prev = temp;
        // add node to head
        this->head = temp;
    };

    Node * end() { return nullptr; };
    Node * last() { return this->tail; };
    Node * first() { return this->head; };

private:
    Node * head;
    Node * tail;

    void _init()
    {
        // initialize values
        this->head = nullptr;
        this->tail = nullptr;
    }
    void _copy(const List & other)
    {
        // clear list
        this->clear();
        // copy nodes to the back
        for (Node * i = other.begin(); i != other.end(); i = i->next)
            this->pushBack(i->data);
    }
};