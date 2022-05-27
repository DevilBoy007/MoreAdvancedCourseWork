#ifndef CUCKOO_H
#define CUCKOO_H
#include <iostream>
using namespace std;
#include "HashTable.h"

class Cuckoo : public HashTable {
    private:
        int size;
        int max;
        int* cuck1;
        int* cuck2;
    public:
        Cuckoo(int s = 10);
        virtual ~Cuckoo();
        
        virtual int insert(int value);
        virtual int search(int value); //virtual just added for clarity
        virtual int remove(int value);
        virtual int load();
        int rehash();
        virtual void print();
};

#endif