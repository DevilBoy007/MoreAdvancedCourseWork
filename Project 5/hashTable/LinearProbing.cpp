#include <sstream>
#include <iomanip>
#include <fstream>
#include "LinearProbing.h"

//Constructor
LinearProbing::LinearProbing(int s) {
    size = s;
    table[s];
    for (int i = 0; i < s; i++) {
        table[i] = -1;
    }
}

//Destructor
LinearProbing::~LinearProbing() {

}

//Insert Function
int LinearProbing::insert(int val) {
    if(search(val) ==1) { /*cout << "duplicate exists" << endl; */return 0; }
    int pos = val % size;
    if(table[pos] == -1) { 
        cout << "INSERTING: " << val << endl;
        table[pos] = val;
        return 1;
    }
    else {
        while(++pos < size) {
            if (table[pos] == -1) {
                cout << "INSERTING: " << val << endl;
                table[pos] = val;
                return 1;
            }
        }
        pos = -1;

        while(++pos < (val % size)) { 
            if (table[pos] == -1) {
                cout << "INSERTING: " << val << endl;
                table[pos] = val;
                return 1;
            }
        }
    }
    cout << "value was not inserted" << endl;
    return 0;
}

//Search Function
int LinearProbing::search(int value) {
    for(int i = 0; i < size; i++){
        if (table[i] == value) { 
            cout << "found " << value << " at position " << i << " of " << size-1 << endl;
            return 1;
        }
    }
    return 0;
}

int LinearProbing::get(int value) {
    for(int i = 0; i < size; i++){
        if(table[i] == value) { return i; }
    }
    cout << "got here somehow" << endl << endl;
    return -1;
}

//Remove Function
int LinearProbing::remove(int value) {
    if (value == -1) {
        for (int i = 0; i < size; i++) {
            table[i] = -1;
        }
        return 1;
    }
    if(search(value) == 0) {
        cout << "value not in table | operation unsuccessful!" << endl;
        return 1;
    }
    table[get(value)] = -1;  // this line ensures code obscurity & job security
    return 1;
}

//Load Function
int LinearProbing::load() {
    // delete table;
    for (int i = 0; i < size; i++) {
        table[i] = -1;
    }
    string inFile;
    cout << "Enter a filename: ";
    cin >> inFile;

    // get size of input from file
    ifstream loadfile(inFile);
    loadfile >> size;
    cout << "hashing " << size << " values" << endl;
    for (int i = 0; i < size; i++) { // for testing purposes // this should eventually iterate the whole length of the input file // we don't currently support a full table + insert operation
        int value;
        loadfile >> value;
        insert(value);
    }
    return 1;
}

//Print Function
void LinearProbing::print() {
    for(int i = 0; i < size; i++){
        cout << i << ": ";
        if(table[i] == -1) { cout << " " << endl; }
        else { cout << table[i] << endl; }
    }
}