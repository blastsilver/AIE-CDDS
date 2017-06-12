#pragma once

namespace util
{
	template <typename T> class HashMap
	{
		// variables
		AATree<HashComparable<T>> m_buffer;
	public:
		// public defaults
		inline HashMap() {};
		inline ~HashMap() {};
		inline HashMap(const HashMap & other) { this->m_buffer = other.m_buffer; };
		// pulic functions
		inline T & get(char * key) { return this->m_buffer.find(HashComparable<T>(key)).value(); }
		inline void erase() { this->m_buffer.erase(); }
		inline void remove(char * key) { this->m_buffer.remove(HashComparable<T>(key)); }
		inline void insert(char * key, const T & value) { this->m_buffer.insert(HashComparable<T>(key, value)); }
		inline Iterator<HashComparable<T>> * & root() { return this->m_buffer.root(); };
	};
}