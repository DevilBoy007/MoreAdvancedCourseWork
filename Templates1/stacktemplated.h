#ifndef STACK_H
#define STACK_H


template<typename T>
class Stack{
   private:
	int size;  // # of elements in the stack
	T * data; //pointer to the internal array for the stack
	int top;  // this int tells me which array position in data is at top of stack

   public:
	Stack(int = 10);  //the default constructor, with a default stack size of 10
	~Stack();  	  //we will have to specify this (destructor)

	// this const usage means that the function cannot change ANTYHING in the class.
	bool isEmpty() const {return top == -1;}
	bool isFull() const {return top == size -1;}

	// The actual meaty functions
	bool pop(T &);  // pop an element off the stack, put it in the parameter, and designate success
	bool push(const T &);  // push an element onto the stack
}; //end stack  (templated)
#endif
