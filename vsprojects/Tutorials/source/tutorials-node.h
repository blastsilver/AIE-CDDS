#pragma once

namespace tutorials
{
	template<typename T> struct Node
	{
        // variables
		T value;
		Node * left;
		Node * right;
        unsigned int level;
		// initialization
        inline Node() : Node(nullptr, nullptr) {};
		inline Node(const T & value) : Node(value, nullptr, nullptr) {};
        inline Node(Node * left, Node * right)
        {
            // initialize values
            this->level = 0;
            this->left = left;
            this->right = right;
        }
		inline Node(const T & value, Node * left, Node * right)
		{
			// initialize values
            this->level = 0;
			this->left = left;
			this->right = right;
			this->value = value;
		};
		// public functions
		inline bool hasReferences()
        {
            // check if has children
            return !(this->right == nullptr && this->left == nullptr);
        };
        // public operator overloading
        inline void operator=(const T & other) { this->value = other; };
        inline bool operator<(const Node<T> & other) { return this->value < other.value; };
        inline bool operator>(const Node<T> & other) { return this->value < other.value; };
        inline bool operator==(const Node<T> & other) { return this->value == other.value; };
        inline bool operator!=(const Node<T> & other) { return this->value != other.value; };
        inline bool operator<=(const Node<T> & other) { return this->value <= other.value; };
        inline bool operator>=(const Node<T> & other) { return this->value >= other.value; };
        inline friend bool operator<(const T & value, const Node<T> & node) { return value < node.value; };
        inline friend bool operator==(const T & value, const Node<T> & node) { return value == node.value; };
        inline friend bool operator==(const Node<T> & node, const T & value) { return node.value == value; };
        inline friend bool operator!=(const T & value, const Node<T> & node) { return value != node.value; };
        inline friend bool operator!=(const Node<T> & node, const T & value) { return node.value != value; };
	};
}