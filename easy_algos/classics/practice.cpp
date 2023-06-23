#include <string>
#include <iostream>
#include <algorithm>

std::string rev1(const std::string& s) {
	std::string rev = s;
	int len = s.length() -1;
	int k = len;
	for(int i = 0; i < s.length()/2; i++) {
		std::swap(rev[i], rev[k]);
		k--;
	}
	return rev;
}

int main(int argc, char** argv) {
	std::cout << rev1(argv[1]) << std::endl;
	std::string input = argv[1];
	std::reverse(input.begin(), input.end());
	std::cout << input << std::endl;
	return 0;
}

