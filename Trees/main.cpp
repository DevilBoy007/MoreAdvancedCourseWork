#include <iostream>
#include <iomanip>
using namespace std;
#include "tree.h"

int main() {
    Tree<int> intTree;
    int insertVal[10]={50,25,75,12,33,67,88,6,13,68};

    for (int x=0; x<10; x++) {
	intTree.insertNode(insertVal[x])
    }
    cout << "preorder: " << intTree.preOrder() << endl;
    cout << "inorder: " << intTree.inOrder() << endl;
    cout << "postorder: " << intTree.postOrder() << endl;

    return 0;
}
