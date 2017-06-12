#pragma once

namespace util
{
	template <typename T> class HashComparable : public Comparable<int>
	{
	protected:
		// variables
		T m_object;
	public:
		// public default
		inline HashComparable() {}
		inline HashComparable(char * key) { this->m_value = this->hashELF(key); }
		inline HashComparable(char * key, const T & object) { this->m_object = object; this->m_value = this->hashELF(key); }
		// public functions
		virtual inline T & value() { return this->m_object; };
		virtual inline int & hash() { return this->m_value; };
		// public operator overloading
		template<typename T> operator T() { return (T) this->m_object; };
	private:
		// private functions
		inline static int hashELF(char * data)
		{
			// variables
			int x = 0;
			int hash = 0;
			// iterate through the data
			for (int i = 0; data[i]; ++i)
			{
				hash = (hash << 4) + data[i];
				if ((x = hash & 0xF0000000L) != 0)
				{
					hash ^= (x >> 24);
					hash &= ~x;
				}
			}
			// return the hash
			return (hash & 0x7FFFFFFF);
		};
	};
}