#include <iostream>
#include <cstdint>
#include <string>
using namespace std;

void fb1(int32_t n) {
	if (n <= 0) return;
	uint32_t counter = 1;
	cout<<"1"<<endl;
	while(counter < n) {
		counter++;
		if (counter % 3 == 0 && counter % 5 == 0 ) {
			cout<<"fizzbuzz"<<endl; 
			continue;
		}
		if (counter % 3 == 0) {
		    cout<<"fizz"<<endl; 
			continue;
		}
		if (counter % 5 == 0 ) {
		    cout<<"buzz"<<endl; 
			continue;
		}
		cout<<counter<<endl; 
	}
}

void fb2(int32_t n) {
	if (n <= 0) return;

    fb2(n - 1);

    if (n % 3 == 0 && n % 5 == 0) {
        std::cout << "FizzBuzz" << std::endl;
    } else if (n % 3 == 0) {
        std::cout << "Fizz" << std::endl;
    } else if (n % 5 == 0) {
        std::cout << "Buzz" << std::endl;
    } else {
        std::cout << n << std::endl;
    }
}


int main(int argc, char** argv) {
	//int32_t n = static_cast<int32_t>(argv[1]);	
	int32_t n = stoi(argv[1]);
	fb1(n);
	cout<<endl;
	fb2(n);
	return 0;
}
