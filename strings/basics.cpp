#include <iostream>
#include <cstring>
#include <string>

using namespace std;

/*
 * string class methods
 * length(): returns the length of the string
 * empty(): returns a boolean value indicating whether the string is empty
 * clear(): erases the contents of the string
 * append(): appends a string or character to the end of the string
 * push_back(): appends a character to the end of the string
 * insert(): inserts a string or character into the string at a specified position
 * erase(): removes a portion of the string
 * replace(): replaces a portion of the string with another string or character
 * substr(): returns a substring of the string
 * copy(): copies a portion of the string into a character array
 * find(): searches the string for a specified substring or character
 * rfind(): searches the string for a specified substring or character, starting from the end of the string
 * compare(): compares the string to another string or character array
 */

int main () {

// this is the c style way, using <cstring>
//
   char str1[10] = "Hello";
   char str2[10] = "World";
   char str3[10];
   int  len ;

   // copy str1 into str3
   strcpy( str3, str1);
   cout << "strcpy( str3, str1) : " << str3 << endl;

   // concatenates str1 and str2
   strcat( str1, str2);
   cout << "strcat( str1, str2): " << str1 << endl;

   // total lenghth of str1 after concatenation
   len = strlen(str1);
   cout << "strlen(str1) : " << len << endl;

// this using the <string> library and makes string obj
//
   string str1 = "Hello";
   string str2 = "World";
   string str3;
   string str4("\nI was made with a constructor\n");
   int  len ;

   // copy str1 into str3
   str3 = str1;
   cout << "str3 : " << str3 << endl;

   // concatenates str1 and str2
   str3 = str1 + str2;
   cout << "str1 + str2 : " << str3 << endl;

   // total length of str3 after concatenation
   len = str3.size();
   cout << "str3.size() :  " << len << endl;
   cout << str4 << endl;

   return 0;
}
