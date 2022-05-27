#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <random>
#include <string>
#include <time.h>

using namespace std;
#include "HashTable.h"
#include "LinearProbing.h"
#include "Chaining.h"
#include "Cuckoo.h"

int main() {
    int size;
    ifstream hashvalues("HashOut.txt");
    hashvalues >> size;
    hashvalues.close();

    char menu(char cOne);
    char subMenu(char cTwo);

	char choiceTwo;
	char choiceOne;

    choiceOne = menu(choiceOne);
 
    while (choiceOne != '0') {
        if (choiceOne == '1') {
            LinearProbing probetable(size);
            while (choiceTwo != '0') {
                choiceTwo = subMenu(choiceTwo);
                if (choiceTwo == '1') {
                    probetable.load();
				}
                if (choiceTwo == '2') {
                    int insertVal;
                    cout << "Enter a value to insert:";
                    cin >> insertVal;
                    probetable.insert(insertVal);
				}
				if (choiceTwo == '3') {
                    int searchVal;
                    cout << "Enter a value to search for: ";
                    cin >> searchVal;
                    cout << "Searching... " << endl;
                    probetable.search(searchVal);
				}
                if (choiceTwo=='4') {
                    int delVal;
                    cout << "Enter a value to delete (-1 to remove all): ";
                    cin >> delVal;
                    cout << "Deleting... " << endl;
                    probetable.remove(delVal);
                }
                if (choiceTwo == '5') {
                    probetable.print();
				}
            }
			return 0;
        }
        else if (choiceOne == '2') {
            Chaining chaintable(size);
			while (choiceTwo != '0') {
				choiceTwo = subMenu(choiceTwo);
				if (choiceTwo == '1') {
					cout << "Loading table from file... " << endl;
                    chaintable.load();
                }
                if (choiceTwo == '2') {
                    int insertVal;
                    cout << "Enter a value to insert: ";
                    cin >> insertVal;
                    chaintable.insert(insertVal);
                }
                if (choiceTwo == '3') {
                    int searchVal;
                    cout << "Enter a value to search for: ";
                    cin >> searchVal;
                    chaintable.search(searchVal);
                }
                if (choiceTwo == '4') {
                    int delVal;
                    cout << "Enter a value to delete (-1 to remove all): ";
                    cin >> delVal;
                    cout << "Deleting... " << endl;
                    chaintable.remove(delVal);
                }
                if (choiceTwo == '5') {
                    chaintable.print();
                }
			}
			return 0;
		}
        else if (choiceOne == '3') {
            Cuckoo cucktable(size);
			while (choiceTwo != '0') {
				choiceTwo = subMenu(choiceTwo);
				if (choiceTwo == '1') {
					cout << "Loading table from file... " << endl;
                    cucktable.load();
                }
                if (choiceTwo == '2') {
                    int inVal;
                    cout << "Enter value to insert:  " << endl;
                    cin >> inVal;
                    cout << "INSERTING: " << inVal << "..." << endl;
                    cucktable.insert(inVal);
                }
                if (choiceTwo == '3') {
                    int searchVal;
                    cout << "Enter value to search for:  " << endl;
                    cin >> searchVal;
                    cout << "SEARCHING..." << endl;
                    cout << (cucktable.search(searchVal) == 1 ? "found it" : "value not in table") << endl;
                }
                if (choiceTwo == '4') {
                    int deleteVal = 0;
                    cout << "Enter value to delete: " << endl;
                    cin >> deleteVal;
                    cucktable.remove(deleteVal);
                }
                if (choiceTwo == '5') {
                    cucktable.print();
                }
            }
			return 0;
		}
		else {
			cout << "Not a valid choice.." << endl;
			cout << "Please enter your choice: ";
    		cin >> choiceOne;
			choiceOne = menu(choiceOne);
		}
    }
    return 0;
}

char menu(char cOne) {
    cout << "\n\n************************************************************" << endl;
    cout << "Welcome to the Anglo-Saxon Castle <insert pithy phrase here>\n" << endl;
    cout << "1) Linear Probing" << endl;
    cout << "2) Separate Chaining" << endl;
    cout << "3) Cuckoo Hashing" << endl;
    cout << "0) Quit\n" << endl;

    cout << "Please enter your choice: ";
    cin >> cOne;
    return cOne;
}

char subMenu(char cTwo) {
    cout << "\n\n************************************************************" << endl;
    cout << "\t1) Load Table From File" << endl;
    cout << "\t2) Insert" << endl;
    cout << "\t3) Search" << endl;
    cout << "\t4) Delete" << endl;
    cout << "\t5) Print Hash Table" << endl;
    cout << "\t0) Quit\n" << endl;

    cout << "Please enter your choice: ";
    cin >> cTwo;
    return cTwo;
}