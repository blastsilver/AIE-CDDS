#pragma once

namespace tutorials
{
	template<typename T> class Tree
	{
		int m_balance;
		Node<T> * m_root;
	public:
		// initialization
		inline Tree()
		{
			// init values
			this->_init();
		}
		inline ~Tree()
		{
			// clear values
			this->clear();
		}
		inline Tree(const Tree<T> & other)
		{
			// init values
			this->_init();
			// copy the tree
			this->_copy(this->m_root, other.m_root);
		}
		inline void operator=(const Tree<T> & other)
		{
			// clear values
			this->clear();
			// copy the tree
			this->_copy(this->m_root, other.m_root);
		}
		// class core methods
		inline void clear()
		{

		}
		inline void insert(const T & value)
		{
			// insert value
			this->m_root = this->_insert(this->m_root, value);
		}
		inline void remove(const T & value)
		{
			// remove value
			// this->_remove(this->m_root, value);
		}
		inline bool isEmpty()
		{
			// check if empty
			return this->m_root == nullptr;
		}
		inline Node<T> * end()
		{
			// return empty node
			return nullptr;
		}
		inline Node<T> * root()
		{
			// return root node
			return this->m_root;
		}
		inline Node<T> * find(const T & value)
		{
			// find value
			return this->_find(this->m_root, value);
		}
	private:
		inline void _init()
		{
			// initialize values
			this->m_balance = 0;
			this->m_root = nullptr;
		}
		inline void _copy(Node<T> * node, Node<T> * other)
		{
			// check if empty
			if (other == nullptr) return;
			// store the value
			node = new Node<T>(other->value);
			// copy nested nodes
			this->_copy(node->next, other->next);
			this->_copy(node->prev, other->prev);
		};
		inline void _balance()
		{
			
		}
		inline Node<T> * _insert(Node<T> * node, const T & value)
		{
			// check if empty
			if (node == nullptr) node = new Node<T>(value);
			// keep searching nodes
			else
			{
				// check the value
				if (value > node->value)
				{
					// insert on right node
					node->next = this->_insert(node->next, value);
				}
				else
				{
					// insert on left node
					node->prev = this->_insert(node->prev, value);
				}
			}
			// return the node
			return node;
		}
		inline Node<T> * _remove(Node<T> * node, const T & value)
		{

		}
		inline Node<T> * _search(Node<T> * node, const T & value)
		{
			// check the value
			if (node == nullptr) return nullptr;
			if (node->value == value) return node;
			// keep searching nodes
			return this->_search(value > node->value, node->next : node->prev, value);
		}
		inline Node<T> * _searchLeft(Node<T> * node)
		{

		}
		inline Node<T> * _searchRight(Node<T> * node)
		{

		}
	};
}