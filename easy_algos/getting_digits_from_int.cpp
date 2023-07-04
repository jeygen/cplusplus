// Count num of digits in an integer
// Print integer a digit at a time




































#include <vectors>
#include <iostream>

int main() {
	int countme = 243;
	int counter = 0;
	vector<int> v = {};
	while (countme != 0) {
		v.push_back(countme % 10);	
		counter++;
		countme /= 10;
	}
	cout<<counter<<endl;
	for (auto e : v) {
		cout<<e;
	}
	return 0;
}

#include <iostream>
#include <stack>

int main() {
    int num = 12345;
    std::stack<int> digits;

    while (num != 0) {
        digits.push(num % 10);  // Push the remainder when num is divided by 10 onto the stack
        num /= 10;  // Remove the last digit from num
    }

    // Print the digits by popping them off the stack
    while (!digits.empty()) {
        std::cout << digits.top() << " ";
        digits.pop();
    }

    return 0;
}

