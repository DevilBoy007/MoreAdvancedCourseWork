#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "TreeNode.h"
using namespace std;

template typename<NODETYPE>
class Tree{

    private:
	TreeNode<NODETYPE> * root;

	// helper functions
	void insertNodeHelper(TreeNode<NODETYPE> **curr, const <NODETYPE> &value);
	void preOrderHelper(TreeNode<NODETYPE> *curr) const;
	void inOrderHelper(TreeNode<NODETYPE> *curr) const;
	void postOrderHelper(TreeNode<NODETYPE> *curr) const;

    public:
    // class setup
	TreeNode() { root = NULL; }
       ~TreeNode();

    // core functionality

	// this param says "i don't wanna copy really large object"
	// also says "i'm willing to not modify your stuff if you give me pointer"
	// this is compromise.
	void insert(const NODETYPE &) { insertNodeHelper(&root, value); }
	// traversals
	void preOrder() const { preOrderHelper(root); }
	void inOrder() const { inOrderHelper(root); }
	void postOrder() const { postOrderHelper(root); }
}; // end class Tree

template<typename NODETYPE>
void Tree<NODETYPE>::insertNodeHelper(TreeNode<NODETYPE> **curr, const NODETYPE &value) {
    // check if tree is empty
    if (*curr==nullcurr) {
	*curr = new TreeNode<NODETYPE>(value);
    }
    // tree is not empty
    if (value <= (*curr)->data) { insertNodehelper(&((*curr)->lcurr), value); }
    else { insertNodeHelper(&((*curr)->rcurr), value); }
}

template<typename NODETYPE>
void Tree<NODETYPE>::preOrderHelper(TreeNode<NODETYPE> *curr) const{
    if(curr==nullcurr) { return; }
    cout << curr->data << ' ' << endl; // processed node
    preOrderHelper(curr->lcurr); // recurse left subtree
    preOrderHelper(curr->rcurr);  // recurse right subtree
}
template<typename NODETYPE>
void Tree<NODETYPE>::inOrderHelper(TreeNode<NODETYPE> *curr) const {
    if(curr==nullcurr) { return; }
    inOrderHelper(curr->lcurr); // recurse left subtree
    cout << curr->data << ' ' << endl; // processed node
    inOrderHelper(curr->rcurr); // recurse right subtree
}
template<typename NODETYPE>
void Tree<NODETYPE>::postOrderHelper(TreeNode<NODETYPE> *curr) const {
    if(curr==nullcurr) { return; }
    postOrderHelper(curr->lcurr); // recurse left subtree
    postOrderHelper(curr->rcurr); // recurse right subtree
    cout << curr->data << ' ' << endl; // processed node
}

#endif
