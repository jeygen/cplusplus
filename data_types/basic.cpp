#include <iostream>
using namespace std;

/*
 * Primitives:
 *
 * bool, char, int, float, double, void, wchar_t (wide char, big for unicode, etc)
 *
 * Modifiers:
 *
 * signed, unsigned, short, long
 *
 * Derived:
 *
 * Function, Array, Pointer, References
 *
 * User Defined:
 *
 * Class, Structure, Union, Enum, Typedef
 *
 */

int main() {
   cout << "Size of char : " << sizeof(char) << endl;
   cout << "Size of int : " << sizeof(int) << endl;
   cout << "Size of short int : " << sizeof(short int) << endl;
   cout << "Size of long int : " << sizeof(long int) << endl;
   cout << "Size of float : " << sizeof(float) << endl;
   cout << "Size of double : " << sizeof(double) << endl;
   cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
   

   return 0;
}
