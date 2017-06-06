#pragma once

namespace tutorials
{
	template<typename T> struct Node
	{
		T value;
		Node * next;
		Node * prev;
        unsigned int level;
		// initialization
        Node() : Node(nullptr, nullptr) {};
		Node(const T & value) : Node(value, nullptr, nullptr) {};
        Node(const Node<T> & other) : Node() { this->clone(other) };
        Node(Node * prev, Node * next)
        {
            // initialize values
            this->level = 0;
            this->prev = prev;
            this->next = next;
        }
		Node(const T & value, Node * prev, Node * next)
		{
			// initialize values
            this->level = 0;
			this->prev = prev;
			this->next = next;
			this->value = value;
		};
		// class core methods
        void clone(const Node<T> & other)
        {
            throw "Not Implemented!";
        }
		bool hasReferences()
        {
            // check if has children
            return !(this->next == nullptr && this->prev == nullptr);
        };
        // class operator overloads
        inline void operator=(const T & other) { this->value = other; };
        inline void operator=(const Node<T> & other) { this->clone(other); };
        inline friend bool operator<(const T & value, const Node<T> & node) { return value < node.value; };
        inline friend bool operator<(const Node<T> & node, const T & value) { return node.value < value; };
        inline friend bool operator>(const T & value, const Node<T> & node) { return value > node.value; };
        inline friend bool operator>(const Node<T> & node, const T & value) { return node.value > value; };
        inline friend bool operator>=(const T & value, const Node<T> & node) { return value >= node.value; };
        inline friend bool operator>=(const Node<T> & node, const T & value) { return node.value >= value; };
        inline friend bool operator<=(const T & value, const Node<T> & node) { return value <= node.value; };
        inline friend bool operator<=(const Node<T> & node, const T & value) { return node.value <= value; };
        inline friend bool operator==(const T & value, const Node<T> & node) { return value == node.value; };
        inline friend bool operator==(const Node<T> & node, const T & value) { return node.value == value; };
        inline friend bool operator!=(const T & value, const Node<T> & node) { return value != node.value; };
        inline friend bool operator!=(const Node<T> & node, const T & value) { return node.value != value; };
	};
}