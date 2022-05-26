#include <iostream>
#include <string>
using namespace std;

//Types of Polymorphism
// 1) Virtual member functions
// 2) Name overloading --an entity that shares the name, but not the parameters
// 3) Operator overloading -- an operator has a different implementation based on context
//	operator +(int param);
//	   ^ actually works !!!
// const as a identifier/qualifier is used in a million different ways
//   -- helps to make sure you're not changing variables you aren't supposed to be changing

void printArray(const int * const a, const int size){
// The const in front of size prevents size rom being modified in the function
// const in front of int * has
// const 
   for(int x = 0; x<size; x++){
	cout << a[x] << "";
	cout << endl;
   }
}// end printArray
void printArray(string * a, const int size){
//   cout << "string me up" << endl;
   for(int x = 0; x<size; x++){
	cout << a[x] << "";
	cout << endl;
   }
}
int main(){
   int b[4] = {2,4,6,8};
   string c[4] = {"two","four","six", "eight"};
   int s = 4;
   printArray(b,s);
   printArray(c,s);
   return 0;
}

//Auxiliary Notes
// 1) if you have a virtual function in a class, you MUST have a virtual destructor as well.
// 2) Pure Virtual Function -- a virtual function where you want to REQUIRE derived classes to redefine
//   -- virtual int area () = 0;
// 3) A Pure Abstract Class is a class that contains ONLY pure virtual functions
//   -- for example, if we created a Shape class, from which Recangle, Square, and Triangle are inherited,
//	it would make sense for Shape to be a pure virtual class
// 4) You cannot create virtual constructors .. duh
