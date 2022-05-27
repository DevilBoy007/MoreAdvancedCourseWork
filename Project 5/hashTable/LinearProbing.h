#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include <iostream>
using namespace std;
#include "HashTable.h"

class LinearProbing : public HashTable {
    private:
        int size;
        int table[];
    public:
        LinearProbing(int s = 10);
        virtual ~LinearProbing();
        
        virtual int insert(int value);
        virtual int search(int value); //virtual just added for clarity
        virtual int remove(int value);
        virtual int load();
        virtual int get(int value); 
        virtual void print();
};

#endif