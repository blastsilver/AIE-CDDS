//#pragma once
//
//namespace tutorials
//{
//    template <typename T> class HashMap
//    {
//        // variables
//        AATree<HashPair<T>> m_buffer;
//    public:
//        // initialization
//        inline HashMap() {};
//        inline ~HashMap() { this->erase(); }
//        // public functions
//        inline T * & find(char * key)
//        {
//            // check if exists
//            if (this->findPair(key) != nullptr) throw "HashMap :: key not found!";
//            // find the hash pair
//            return this->findPair(key)->value->value;
//        };
//        inline void erase()
//        {
//            // erase the buffer
//            this->m_buffer.erase();
//        }
//        inline void remove(char * key)
//        {
//            // remove a pair
//            HashPair<T> pair(key);
//            this->m_buffer.remove(&pair);
//        };
//        inline void insert(char * key, const T & value)
//        {
//            // check if exists
//            if (this->findPair(key) != nullptr) throw "HashMap :: key already found!";
//            // insert new hash pair
//            //this->m_buffer.insert(HashPair<T>(key, value));
//        };
//    private:
//        // private functions
//        inline Node<HashPair<T>> * & findPair(char * key)
//        {
//            // find a pair
//            HashPair<T> pair(key);
//            return this->m_buffer.find(pair);
//        }
//    };
//}
//
///*
//inline unsigned int hashCRC(unsigned char key)
//{
//    unsigned int hash = 0;
//    unsigned int highorder = hash & 0xf8000000;
//    hash = hash << 5;
//    hash = hash ^ (highorder >> 27);
//    hash = hash ^ (unsigned int)key;
//    return hash;
//};
//*/