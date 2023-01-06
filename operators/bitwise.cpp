#include <iostream>
#include <bitset> // package for binary
using namespace std;

int main() {

	// a = 5(00000101), b = 9(00001001)
	int a = 5, b = 9;

	// The result is 00000001
	cout << "a = " << a <<","<< " b = " << b <<endl;
	cout << "a & b = " << (a & b) << endl; // bitwise AND
	cout << bitset<8>(a & b) << endl; // to display binary
	
	// kinda unrelated
	cout << hex << 15 << endl; // to display hex or octal (use oct)

	// The result is 00001101
	cout << "a | b = " << (a | b) << endl; // bitwise OR

	// The result is 00001100
	cout << "a ^ b = " << (a ^ b) << endl; // bitwise XOR (no ands)

	// The result is 11111010
	cout << "~a = " << (~a) << endl; // bitwise NOT

	// The result is 00010010
	cout << "b << 1" <<" = "<< (b << 1) << endl; // bitwise left shift

	// The result is 00000100
	cout << "b >> 1 "<<"= " << (b >> 1 ) << endl; // bitwise right shift

	return 0;
}
