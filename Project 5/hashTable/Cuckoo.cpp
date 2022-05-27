#include <sstream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include "Cuckoo.h"

Cuckoo::Cuckoo(int s) {
    if(s % 2 == 1)
        s++;
    size = s/2; // split our table size for cuckoo hashing
    max = 10;
    cuck1 = new int[size];
    cuck2 = new int[size];

    for(int i = 0; i < (size); i++) {
        cuck1[i] = cuck2[i] = -1;
    }
}

Cuckoo::~Cuckoo() { 
    delete cuck1;
    delete cuck2;
}

int Cuckoo::search(int value) {
    for(int i = 0; i < size; i++) {
        if(cuck1[i]==value) { return 1; }
        if(cuck2[i]==value) { return 1; }
    }
    return 0;
}

int Cuckoo::rehash() {
    cout << "\nExhausted all resources | rehashing...\n" << endl;
    
    delete cuck1;
    delete cuck2;

    size += 3;
    cuck1 = new int[size];
    cuck2 = new int[size];

    for(int i = 0; i < size; i++) {
        cuck1[i] = cuck2[i] = -1;
    }

    return 1;
}

int Cuckoo::insert(int value) {
    if(search(value) == 1) { 
        cout << "value found in table | operation failed!" << endl;
        return 0;
    }
    int count = 0;

    while ((count < max) && (size < 21)) {
        cout << value << " not in table yet| Inserting..." << endl;

        int pos = value % size;
        if (cuck1[pos] == -1) { // check if hashed spot is empty, insert if it is
            cuck1[pos] = value; 
            return 1; 
        }

        int roosted = cuck1[pos];   // if it's not, make it empty
        cuck1[pos] = value; // then insert
        int newPos = fmod(roosted/(size/2), size/2);

        if(cuck2[newPos] == -1) { // check if new hashed spot is empty, insert if it is
            cuck2[newPos] = roosted; 
            return 1; 
        } 

        // if cuck2 position was filled
        value = cuck2[newPos];
        cuck2[newPos] = roosted; //insert if cuck1 pos was full
        count++;
    }

    //cout << "\nExceeded maxloop, rehashing" << endl;
    rehash();
    
    if(size > 21){
        return -2;
        cout << "Table Size Exceeds 21, Aborting" << endl;
    }

    return -1;
}

int Cuckoo::remove(int value) {
    for(int i = 0; i < size; i++) {
        if(cuck1[i] == value) {
            cuck1[i] = -1;
            return 1;
        }
        if(cuck2[i] == value) { 
            cuck2[1] = -1;
            return 1; 
        }
    }
    return 0;
}

int Cuckoo::load() {
    // reset table;
    int fileSize;
    int retry = -1;

    string inFile;
    int insertReturn = 0;
    cout << "Enter a filename: ";
    cin >> inFile;

    while(retry == -1) {
        retry = 0;
        for (int i = 0; i < size; i++) {
            cuck1[i] = -1;
            cuck2[i] = -1;
        }

        // get size of input from file
        ifstream loadfile(inFile);
        loadfile >> fileSize;
        cout << "\nHashing " << fileSize << " values\n" << endl;
        for (int i = 0; i < fileSize; i++) { 
            int value;
            loadfile >> value;
            insertReturn = insert(value) == -1;
            if (insertReturn == -1) { // Rehashing, start the load over 
                retry = -1;
                break;
            }
            else if(insertReturn == -2) { // Exceeded m = 21, terminate process.
                break;
            }
        }
    }
    return 1;
}

void Cuckoo::print() {
    cout << "\tcuck1\t\t\tcuck2" << endl;
    for(int i = 0; i < size; i++) {
        cout << i << ":\t" << cuck1[i] << "\t\t\t" << cuck2[i] << endl;
    }
}