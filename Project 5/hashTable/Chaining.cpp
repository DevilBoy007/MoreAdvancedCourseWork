#include <sstream>
#include <iomanip>
#include <fstream>
#include "Chaining.h"

//Constructor
Chaining::Chaining(int s) {
    size = s;
    table = new list<int>[s];
    
    for (int i = 0; i < s; i++) {
        table[i] = {};
    }
}

//Destructor
Chaining::~Chaining() {
    for (int i = 0; i < size; i++){
        table[i].empty();
    }
    delete [] table;
}

//Insert Function
int Chaining::insert(int val) {
    if(search(val) == 1) {
        cout << "item already in list | operation unsuccessful!" << endl;
        return 0;
    }

    int pos = val % size;
    cout << "INSERTING: " << val << endl;
    table[pos].push_back(val);
    return 1;
}

//Search Function
int Chaining::search(int value) {
    for(int i = 0; i < size; i++) {
        for (list<int>::iterator it = table[i].begin(); it != table[i].end(); it++) {
            //cout << *it << " " << endl;
            if (*it == value) {
                cout << "found " << value << " in array " << i << " of " << size << endl;
                return 1;
            }
        }
    }
    return 0;
}

//Remove Function
int Chaining::remove(int value) {
    if (value == -1) {
        for (int i = 0; i < size; i++) {
            table[i] = {};
        }
        return 1;
    }
    if (search(value) == 0) {
        cout << "value not in table | operation unsuccessful!" << endl;
        return 1;
    }
    for(int i = 0; i < size; i++){
        for (list<int>::iterator it = table[i].begin(); it != table[i].end(); it++) {
            if (*it == value) {
                table[i].erase(it);
                return 1;
            }
        }
    }
    cout << "unknown error | operation unsuccessful!";
    return 0;
}

//Load Function
int Chaining::load() {
    // delete table;
    for (int i = 0; i < size; i++) {
        table[i] = {};
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
void Chaining::print() {
    for(int i = 0; i < size; i++){
        cout << i << ": [ ";
        for (list<int>::iterator it = table[i].begin(); it != table[i].end(); it++){
            cout << *it << " -> ";
        }
        cout << " ]" << endl;
    }
}