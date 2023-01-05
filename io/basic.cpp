#include <iostream>
using namespace std;

/*
 * \n more common than endl
 * \t, \\, \" other escape sequences
 * 
 * */

int main() {
	cout << "Sup, i need code for newline";
	cout << "new line like \n this\n";
	cout << "or like this" << endl;

	int x;
	cout << "\nInput a number: \n";
	cin >> x; // >> extraction operator
	cout << "\nUr num is: " << x << "\n";

	return 0;
}
