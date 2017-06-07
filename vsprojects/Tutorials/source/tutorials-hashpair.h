#pragma once

namespace tutorials
{
    template <typename T> struct HashPair
    {
        // variables
        int hash;
        T * value;
        char * key;
        // initialization
        inline HashPair() {};
        inline HashPair(char * key)
        {
            // initialize values
            this->key = key;
            this->hash = this->hashELF(key);
        }
        inline HashPair(char * key, const T * & value)
        {
            // initialize values
            this->key = key;
            this->hash = this->hashELF(key);
            this->value = value;
        }
        // public operator overloading
        inline void operator=(const T & other) { this->value = other; };
        inline bool operator>(const HashPair & other) { return this->hash > other.hash; };
        inline bool operator<(const HashPair & other) { return this->hash < other.hash; };
        inline bool operator!=(const HashPair & other) { return this->key != other.key; };
        inline bool operator==(const HashPair & other) { return this->key == other.key; };
        inline bool operator<=(const HashPair & other) { return this->hash <= other.hash; };
        inline bool operator>=(const HashPair & other) { return this->hash >= other.hash; };
        inline friend bool operator==(const T & p2, const HashPair & p1) { return p2 == p2->value; };
        inline friend bool operator==(const HashPair & p1, const T & p2) { return p1->value == p2; };
        inline friend bool operator!=(const T & p2, const HashPair & p1) { return p2 != p2->value; };
        inline friend bool operator!=(const HashPair & p1, const T & p2) { return p1->value != p2; };
    private:
        // private functions
        inline unsigned int hashELF(char * data)
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