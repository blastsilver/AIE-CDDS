#pragma once

//https://www.panix.com/~elflord/cpp/list_howto/
//http://www.azillionmonkeys.com/qed/hash.html

template<typename T> struct Node {
    T value;
    Node * prev;
    Node * next;
    Node(T value, Node * prev, Node * next)
    {
        this->prev = prev;
        this->next = next;
        this->value = value;
    }
};

template<typename T> class LinkedList
{
public:
    LinkedList() { this->_init(); };
    ~LinkedList() { this->clear(); }
    LinkedList(const LinkedList & other) { this->_init(); this->_copy(other) };
    void operator=(const LinkedList & other) { this->_copy(other); };

    void clear()
    {
        // check if empty
        while (!this->empty())
        {
            // delete front node
            this->popFront();
        }
    };
    bool empty()
    {
        // check if nodes are emtpy
        return this->head == nullptr;
    }
    void popBack()
    {
        Node<T> * temp = this->tail;
        // check if empty
        if (temp == nullptr) return;
        // set tail to the next
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
        // check if tail is empty
        if (this->tail == nullptr) this->head = nullptr;
        // delete the node
        delete temp;
    }
    // remove node from head
    void popFront()
    {
        Node<T> * temp = this->head;
        // check if empty
        if (temp == nullptr) return;
        // set head to the next
        this->head = this->head->next;
        this->head->prev = nullptr;
        // check if head is empty
        if (this->head == nullptr) this->tail = nullptr;
        // delete the node
        delete temp;
        temp = nullptr;
    }
    void pushBack(const T & value)
    {
        Node<T> * temp = new Node<T>(value, this->tail, nullptr);
        // check if head is empty
        if (this->head == nullptr) this->head = temp;
        // check if tail is not empty
        if (this->tail != nullptr) this->tail->next = temp;
        // add node to tail
        this->tail = temp;
    }
    void pushFront(const T & value)
    {
        Node<T> * temp = new Node<T>(value, nullptr, this->head);
        // check if tail is empty
        if (this->tail == nullptr) this->tail = temp;
        // check if head is not empty
        if (this->head != nullptr) this->head->prev = temp;
        // add node to head
        this->head = temp;
    }
    Node<T> * end() { return nullptr; };
    Node<T> * last() { return this->tail; };
    Node<T> * first() { return this->head; };

private:
    Node<T> * head;
    Node<T> * tail;
    void _init() {
        // initialize values
        this->head = nullptr;
        this->tail = nullptr;
    }
    void _copy(const LinkedList & other)
    {
        // clear list
        this->clear();
        // copy nodes to the back
        for (Node<T> * i = other.head; i != nullptr; i = i->next)
        {
            // add to back
            this->pushBack(i->value);
        }
    }
};