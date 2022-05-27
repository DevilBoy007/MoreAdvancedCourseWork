#include <iostream>
#include <fstream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>
#include <cstdio>
using namespace std;

void makeFile() {    
    remove("HashOut.txt");
    ofstream outfile;
    outfile.open("HashOut.txt");
    srand(time(0));
    int table_size = rand() % 21;

    int numBer = 0;

    outfile << table_size << '\n'; // Puts the table size at top of file
    for (int i = 0; i < table_size; i++) {
        numBer = rand() % 999;
        outfile << numBer << '\n'; 
    }

    outfile.close();
};

int main() {
    makeFile();
    return 0;
}