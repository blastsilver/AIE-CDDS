#pragma once

namespace tutorials
{
	template <typename T> class List
	{
		Node<T> * m_head;
		Node<T> * m_tail;
	public:
		// initialization
		inline List()
		{
			// init values
			this->init();
		}
		inline ~List()
		{
			// clear values
			this->erase();
		}
		inline List(const List<T> & other)
		{
			// init values
			this->init();
			// copy the list
			this->copyList(other);
		}
		// public functions
		inline void erase()
		{
			// check if empty
			while (this->isEmpty())
			{
				// remove node
				this->popFront();
			}
		}
		inline bool isEmpty()
		{
			// check if empty
			return this->m_head == nullptr;
		}
		inline void popBack()
		{
			// store tail
			Node<T> * temp = this->m_tail;
			// check if empty
			if (temp == nullptr) return;
			// setup the tail
			this->m_tail = this->m_tail->left;
			this->m_tail->right = nullptr;
			// check if tail is empty
			if (this->m_tail == nullptr) this->m_head = nullptr;
			// delete the node
			delete temp;
		}
		inline void popFront()
		{
			// store head
			Node<T> * temp = this->m_head;
			// check if empty
			if (temp == nullptr) return;
			// setup the head
			this->m_head = this->m_head->right;
			this->m_head->left = nullptr;
			// check if head is empty
			if (this->m_head == nullptr) this->m_tail = nullptr;
			// delete the node
			delete temp;
		}
		inline void pushBack(const T & value)
		{
			// create node
			Node<T> * temp = new Node<T>(value, this->m_tail, nullptr);
			// check if head is empty
			if (this->m_head == nullptr) this->m_head = temp;
			// check if tail is not empty
			if (this->m_tail != nullptr) this->m_tail->right = temp;
			// add node to tail
			this->m_tail = temp;
		}
		inline void pushFront(const T & value)
		{
			// create node
			Node<T> * temp = new Node<T>(value, this->m_tail, nullptr);
			// check if tail is empty
			if (this->m_tail == nullptr) this->m_tail = temp;
			// check if head is not empty
			if (this->m_head != nullptr) this->m_head->left = temp;
			// add node to head
			this->m_head = temp;
		}
		inline Node<T> * end()
		{
			// return empty node
			return nullptr;
		}
		inline Node<T> * tail()
		{
			// return tail node
			return this->m_tail;
		}
		inline Node<T> * head()
		{
			// return head node
			return this->m_head;
		}
        // public operator overloading
		inline void operator=(const List<T> & other)
		{
			// clear values
			this->erase();
			// copy the list
			this->copyList(other);
		}
	private:
        // private functions
		inline void init()
		{
			// initialize values
			this->m_head = nullptr;
			this->m_tail = nullptr;
		}
		inline void copyList(const List & other)
		{
			// check if empty
			if (other == nullptr) return;
			// iterate through nodes
			for (Node<T> * i = other.m_head; i != nullptr; i = i->right)
			{
				// insert value
				this->pushBack(i->value);
			}
		};
	};
}