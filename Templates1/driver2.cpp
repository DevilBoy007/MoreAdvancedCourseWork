#include <iostream>
#include <string>
using namespace std;

template<typename T>
void printArray(const T * const a, const int size) {
   for(int x = 0; x<size; x++){
        cout << a[x] << " ";
   }
}//end printArray (templated)
/*
void printArray(const int * const a, const int size){ 
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
void printArray(double * a, const double size){
   for(int x = 0; x<size; x++){
        cout << a[x] << "";
        cout << endl;
   }
}//end printArray
*/
int main(){
   int b[4] = {2,4,6,8};
   string c[4] = {"two","four","six", "eight"};

   printArray(b,4);
   cout << endl;
   printArray(c,4);
   return 0;
}
