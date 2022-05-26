#ifndef TREENODE_H
#define TREENODE_H

// forward declaration of class Tree
//	notifies the treeNode class that a class called Tree will exist (soon)
template<typename NODETYPE> class Tree;

template<typename NODETYPE>
class TreeNode {
// any member function of class Tree can access private memebers of TreeNode because it is a friend
    friend class Tree<NODETYPE>;
    private:
	TreeNode<NODETYPE> * lPtr;
	TreeNode<NODETYPE> * rPtr;
	NODETYPE data;
    public:
    // class setup
	TreeNode(const NODETYPE &d) : lPtr(NULL), rPtr(NULL), data(d) {}
    // Access functions
	NODETYPE getData() const { return data; }


}; // end class TreeNode
#endif
