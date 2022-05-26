#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "TreeNode.h"
using namespace std;

template typename<NODETYPE>
class Tree{

    private:
	TreeNode<NODETYPE> * root;

	// Typedef: this allows for us to substitute a new name for a variable type
	typedef TreeNode<NODETYPE> * TreeNodePtr;

	// helper functions
	void insertNodeHelper(TreeNodePtr *curr, const NODETYPE &value);
	void preOrderHelper(TreeNode<NODETYPE> *curr) const;
	void inOrderHelper(TreeNode<NODETYPE> *curr) const;
	void postOrderHelper(TreeNode<NODETYPE> *curr) const;
	void depthHelper(TreeNodePtr, int &total int &current) const;
	TreeNodePtr deleteNodeHelper(TreeNodePtr & curr, const NODETYPE &value);

    public:
    // class setup
	TreeNode() { root = NULL; }
       ~TreeNode();

    // core functionality

	// this param says "i don't wanna copy really large object"
	// also says "i'm willing to not modify your stuff if you give me pointer"
	// this is compromise.
	void insert(const NODETYPE &) { insertNodeHelper(root, value); }
	void deleteNode(const NODETYPE &) { deleteNodeHelper(root, value); }
	// traversals
	void preOrder() const { preOrderHelper(root); }
	void inOrder() const { inOrderHelper(root); }
	void postOrder() const { postOrderHelper(root); }
	int depth() const {
	    int total = 0, current = 0;
    	    depthHelper(root,0,0);
	    return total;
	}
}; // end class Tree
// part one is to FIND the node we wish to delete
template<typename NODETYPE>
void Tree<NODETYPE>::deleteNodeHelper(TreeNodePtr &curr, const NODETYPE &value){
// subtree is empty
    if (curr == nullptr) { return curr; }
    else if (value < curr->data) {curr->lptr = deleteNodeHelper(curr->lptr, value); }
    else if (value > curr->data) { deleteNodeHelper(curr->rptr, value); }
    else {
    // case 1 doomed node has no children
	if ((curr->lptr)== nullptr && (curr->rptr)== nullptr){
	    delete curr;
	    curr = nullptr;
	}
    }
}

template<typename NODETYPE>
void Tree<NODETYPE>::depthHelper(TreeNodePtr curr, int &total, int &current) const {
// empty tree
    if (curr == nullptr) { return; }

    curr++;
    if (curr > total) { total = curr; }

// tree is not empty
    depthHelper(curr->lptr, total, current);
    depthHelper(curr->rptr, total, current);

// use the typedef bc typedef is good shit
template<typename NODETYPE>
void Tree<NODETYPE>::insertNodeHelper(TreeNodePtr *curr, const NODETYPE &value) {
    // check if tree is empty
    if (curr==nullptr) {
	curr = new TreeNode<NODETYPE>(value);
    }
    // tree is not empty
    if (value <= (curr)->data) { insertNodehelper(curr->lcurr), value); }
    else { insertNodeHelper(curr->rcurr, value); }
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
