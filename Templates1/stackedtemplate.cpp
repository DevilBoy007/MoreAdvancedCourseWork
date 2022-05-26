#include "stacktemplated.h"

/*
template<typename T>
Stack<T>::Stack(int s){
   if (s > 0)
	size = s;
   else
	size = 10;
   top = -1;
   data = new T[size];
}
*/
template<typename T>
Stack<T>::Stack() : top(-1), size(10), data(new T[size]) {}
// alternate definition to constructor above using different syntax (parameter intitialization)
template<typename T>
Stack<T>::Stack(int s) : top(-1), size(s>0?s:10), data(new T[size]) {}
//destructor (specified)
template<typename T>
Stack<T>::~Stack() { delete [] data; }

//begin push
template<typename T>
bool Stack<T>::push(const T & pushValue){
   if(isFull()) return false;
   data[++top] = pushValue;
   return true;
} // end push

//begin pop
// this function uses lazy deletion, which is a key CS concept
template<typename T>
bool Stack<T>::pop(T & popLocation){
   if(isEmpty()) return false;
   popLocation = data[top--];
   return true;
} // end pop
