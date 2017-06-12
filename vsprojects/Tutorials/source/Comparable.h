#pragma once

namespace util
{
	template <typename T> class Comparable
	{
	protected:
		// variables
		T m_value;
	public:
		// public defaults
		inline Comparable() {};
		inline Comparable(const T & value) { this->m_value = value; };
		inline Comparable(const Comparable & other) { this->m_value = other.m_value; };
		// public functions
		virtual inline T & value() { return this->m_value; };
		// public operator overloading
		template<typename T> operator T() { return (T) this->m_value; };
		inline void operator=(const T & other) { this->m_value = other; };
		inline void operator=(const Comparable & other) { this->m_value = other.m_value; };
		inline bool operator>(const Comparable & other) { return this->m_value > other.m_value; };
		inline bool operator<(const Comparable & other) { return this->m_value < other.m_value; };
		inline bool operator>=(const Comparable & other) { return this->m_value >= other.m_value; };
		inline bool operator<=(const Comparable & other) { return this->m_value <= other.m_value; };
		inline bool operator==(const Comparable & other) { return this->m_value == other.m_value; };
		inline bool operator!=(const Comparable & other) { return this->m_value != other.m_value; };
	};
}