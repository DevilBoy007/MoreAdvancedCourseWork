#ifndef CHAINING_H
#define CHAINING_H
#include <iostream>
#include <list>
using namespace std;
#include "HashTable.h"

class Chaining : public HashTable {
    private:
        int size;
        list<int> *table;
    public:
        Chaining(int s = 10);
        ~Chaining();
        
        virtual int insert(int value);
        virtual int search(int value); //virtual just added for clarity
        virtual int remove(int value);
        virtual int load();
        virtual void print();
};

#endif