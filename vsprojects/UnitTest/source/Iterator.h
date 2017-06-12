#pragma once

namespace util
{
	template <typename T> class Iterator
	{
	protected:
		// variables
		T m_value;
		int m_level;
		Iterator * m_prev;
		Iterator * m_next;
	public:
		// public defaults
		inline Iterator() { this->m_prev = nullptr; this->m_next = nullptr; this->m_level = 0; };
		inline Iterator(const T & value) : Iterator(value, nullptr, nullptr) {};
		inline Iterator(const Iterator & other) : Iterator(other.m_value, nullptr, nullptr) {};
		inline Iterator(const T & value, Iterator * prev, Iterator * next) { this->m_prev = prev; this->m_next = next; this->m_value = value; this->m_level = 0; };
		// public functions
		inline T & value() { return this->m_value; }
		inline int & level() { return this->m_level; };
		inline Iterator * & prev() { return this->m_prev; };
		inline Iterator * & next() { return this->m_next; };
		inline Iterator * & left() { return this->prev(); };
		inline Iterator * & right() { return this->next(); };
		// public operator overloading
		template<typename T> operator T() { return (T)this->m_value; };
		inline void operator=(const T & other) { this->m_value = other; };
	};
}