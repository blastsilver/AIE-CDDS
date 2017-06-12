#pragma once

namespace util
{
	template <typename T> class LinkedList
	{
		// variables
		unsigned int m_size;
		Iterator<T> * m_head;
		Iterator<T> * m_tail;
	public:
		// public defaults
		inline LinkedList()
		{
			// initialize variables
			this->m_size = 0;
			this->m_head = nullptr;
			this->m_tail = nullptr;
		}
		inline ~LinkedList()
		{
			// clear the list
			this->clear();
		}
		inline LinkedList(const LinkedList & other) : LinkedList()
		{
			// initialize variables
			this->m_size = 0;
			this->m_head = nullptr;
			this->m_tail = nullptr;
			// insert new values
			for (Iterator<T> * i = other.m_head; i; i = i->next())
			{
				this->pushBack(i->value);
			}
		}
		// public functions
		inline void clear()
		{
			// delete list nodes
			for (unsigned int i = 0; i < this->m_size; i++)
			{
				this->popBack();
			}
			// re-initialize variables
			this->m_size = 0;
			this->m_head = nullptr;
			this->m_tail = nullptr;
		}
		inline void insert(const T & value)
		{
			// push back value
			this->pushBack(value);
		}
		inline void remove(const T & value)
		{
			Iterator<T> * temp1 = m_head;
			// keep searching list
			while (true)
			{
				// check if empty
				if (temp1 == nullptr) return;
				// check if value
				if (temp1->value() == value)
				{
					// check if empty
					if (this->m_size == 0) return;
					// store temp1 node
					Iterator<T> * temp2 = temp1;
					// re-link the list
					if (temp1->next() != nullptr) temp1->next()->prev() = temp1->prev(); else this->m_tail = temp1->prev();
					if (temp1->prev() != nullptr) temp1->prev()->next() = temp1->next(); else this->m_head = temp1->next();
					temp1 = temp1->next();
					// delete removed node
					delete temp2;
					// decrement list size
					this->m_size--;
				}
				else
				{
					// keep searching
					temp1 = temp1->next();
				}
			}
		}
		inline bool isEmpty()
		{
			// check size is zero
			return this->m_size == 0;
		}
		inline void popBack()
		{
			// check if empty
			if (this->m_size == 0) return;
			// store tail node
			Iterator<T> * temp = this->m_tail;
			// re-link the list
			this->m_tail = this->m_tail->prev();
			this->m_tail->next() = nullptr;
			// check tail if empty
			if (this->m_tail == nullptr) this->m_head = nullptr;
			// delete removed node
			delete temp;
			// decrement list size
			this->m_size--;
		}
		inline void popFront()
		{
			// check if empty
			if (this->m_size == 0) return;
			// store head node
			Iterator<T> * temp = this->m_head;
			// re-link the list
			this->m_head = this->m_head->next();
			this->m_head->prev() = nullptr;
			// check head if empty
			if (this->m_head == nullptr) this->m_tail = nullptr;
			// delete removed node
			delete temp;
			// decrement list size
			this->m_size--;
		}
		inline void pushBack(const T & value)
		{
			// create node
			Iterator<T> * node = new Iterator<T>(value, this->m_tail, nullptr);
			// re-link the list
			if (this->m_size == 0) this->m_head = node;
			if (this->m_tail != nullptr) this->m_tail->next() = node;
			// add node to tail
			this->m_tail = node;
			// increment list size
			this->m_size++;
		}
		inline void pushFront(const T & value)
		{
			// create node
			Iterator<T> * node = new Iterator<T>(value, nullptr, this->m_head);
			// re-link the list
			if (this->m_size == 0) this->m_tail = node;
			if (this->m_head != nullptr) this->m_head->prev() = node;
			// add node to head
			this->m_head = node;
			// increment list size
			this->m_size++;
		}
		inline unsigned int size() { return this->m_size; };
		inline Iterator<T> * & head() { return this->m_head; };
		inline Iterator<T> * & tail() { return this->m_tail; };
		// public operator overloading
		inline void operator=(const LinkedList & other)
		{
			// clear list
			this->clear();
			// insert new values
			for (Iterator<T> * i = other.m_head; i; i = i->next())
			{
				this->pushBack(i->value);
			}
		}
	};
}