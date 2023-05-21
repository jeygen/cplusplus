#include <iostream>
#include <cstdint>

using namespace std;

// can also use #include <algorithm> std::swap() 

void swap1(uint32_t* a, uint32_t* b) {
    uint32_t temp = *a;
    *a = *b;
    *b = temp;
}
        
void swap2(uint32_t* a, uint32_t* b) {
    uint32_t temp = *a;
    *a = *b;
    *b = temp;
}

void swap3(uint32_t& a, uint32_t& b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

// Passing by ref makes it very easy, no pointers
void swap4(uint32_t& a, uint32_t& b) {
    int temp = a;
    a = b;
    b = temp;
}


int main() {
    uint32_t x = 0xBEEFCAFE;
    uint32_t y = 0xAAAABBBB;
    uint32_t* xp = &x;        
    uint32_t* yp = &y;
    
    cout << hex << *xp << endl;
    cout << hex << *yp << endl;
    
	// One level lower if using pointer
    swap1(xp, yp);
    
    cout << hex << *xp << endl;
    cout << hex << *yp << endl;

	// Pass address
	swap2(&x, &y);

	cout << hex << x << endl;
	cout << hex << y << endl;

	swap3(x, y);
    
	cout << hex << x << endl;
	cout << hex << y << endl;

	swap4(x, y);
    
	cout << hex << x << endl;
	cout << hex << y << endl;

    return 0;
}

