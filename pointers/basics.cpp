// Same as C, but with more features

#include <iostream>

using namespace std;

int main () {
   int  var = 20;   // actual variable declaration.
   int  *ip;        // pointer variable 

   ip = &var;       // store address of var in pointer variable

   cout << "Value of var variable: ";
   cout << var << endl;

   // print the address stored in ip pointer variable
   cout << "Address stored in ip variable: ";
   cout << ip << endl;

   // access the value at the address available in pointer
   cout << "Value of *ip variable: ";
   cout << *ip << endl;
   
  // --------- can use auto and constant with pointers ------
  
  // auto lets compiler deduce type, for readability i think
  
  // Declare a pointer to an int using auto
  int x = 10;
  auto p = &x; // p has type "int*", just like if we had written "int* p = &x;"

  // const can make pointer constant or point to a constant
  // all to the same affect i think
  
  // Declare a constant pointer to an int
  const int y = 20;
  const int* q = &y; // q is constant pointer, cant deref/mod y

	  // *q = 15;  // This line would cause a compile-time error

  // Declare a pointer to a constant int
  int z = 30;
  int const* r = &z;

  // r has type "int const*", and we cannot use it to modify z
  // *r = 25;  // This line would cause a compile-time error

  // Declare a constant pointer to a constant int
  const int w = 40;
  const int* const s = &w;

  // s has type "const int* const", and we cannot use it to modify w
  // *s = 35;  // This line would cause a compile-time error
  // s = &z;  // This line would also cause a compile-time error


  // smart pointers -------------------------------------------
  //
  // see own file, smart pointers wrap raw pointers and auto manage mem
 
  
  

   return 0;
}
