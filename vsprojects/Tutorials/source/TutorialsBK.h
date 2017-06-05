#pragma once

//http://northrop.com.au/careers
//http://www.azillionmonkeys.com/qed/hash.html
//https://www.panix.com/~elflord/cpp/list_howto/
//https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
//http://www.eternallyconfuzzled.com/tuts/datastructures/jsw_tut_andersson.aspx
//http://web.eecs.umich.edu/~sugih/courses/eecs281/f11/lectures/12-AAtrees+Treaps.pdf

template<typename T> struct Node {
    T value;
    int level;
    Node * prev;
    Node * next;

    Node() : Node(0, nullptr., nullptr, 0) {};
    Node(T value) : Node(value, nullptr, nullptr, 0) {};
    Node(T value, int level) : Node(value, nullptr, nullptr, level) {};
    Node(T value, Node * prev, Node * next, int level)
    {
        this->prev = prev;
        this->next = next;
        this->level = level;
        this->value = value;
    }
};


template<typename T> class Tree
{
    Node<T> * m_root;
public:
    Tree() { this->_init(); };
    ~Tree() { this->clear(); }
    Tree(const Tree & other) { this->_init(); this->_copy(other) };
    void operator=(const Tree & other) { this->clear(); this->_copy(other); };

    void clear()
    {
        
    };
    bool isEmpty()
    {
        // check if nodes are emtpy
        return this->head == nullptr;
    }
    void insert(const T & value) { this->m_root = this->_insert(this->m_root, value); }
    void remove(const T & value) {}
    Node<T> * find (const T & value) {}
private:
    void _init()
    {
        this->m_root = nullptr;
    }
    Node<T> * _copy(Node<T> * other)
    {
        // check if empty
        if (other == nullptr) return nullptr;
        // create node copy
        Node<T> * temp = new Node<T>(other->value);
        temp->next = this->_copy(other->next);
        temp->prev = this->_copy(other->prev);
        // return node
        return temp;
    }
    Node<T> * _insert(Node<T> * node, const T & value)
    {
        // check if empty
        if (node == nullptr) return new Node<T>(value);
        // search the number
        if (value > node->value)
        {
            // insert on the right branch
            node->next = this->_insert(node->next, value);
        }
        else
        {
            // insert on the left branch
            node->prev = this->_insert(node->prev, value);
        }
        // return the node
        return node;
    }
    // remove double red's
    Node<T> * _split(Node<T> * node)
    {
        // temporary values
        Node<T> * temp1 = node;
        Node<T> * temp2 = temp1->next;
        Node<T> * temp3 = temp2->next;
        // rotate between temp1 and temp2
        temp1->next = temp2.prev;
        temp2->prev = temp1;

        // temp3 = black

        return temp2;
    }
    // remove left horizontal link
    Node<T> * _skew(Node<T> * node)
    {
        // temporary values
        Node<T> * temp1 = node;
        Node<T> * temp2 = node->prev;
        // rotate between temp1 and temp2
        temp1->prev = temp2.next;
        temp2->next = temp1;

        // temp1 = red
        // temp2 = black

        return temp2;
    }
    
};