#include <string>
#include <regex>
#include <cctype>

bool is_palindrome(std::string s) {
	// R for rawstring, ignores escape seq or special chars
	std::regex pattern(R"([^\w|_]+)");
	// replace non-alphanumeric with nothing ""
	std::string processed_s = std::regex_replace(s, pattern, "");	
	// could do stack or array
	int mid = processed_s.length() / 2;

	for (char& c : processed_s) {
		c = std::toupper(c);
	}
	
	for(int i=0; i<mid; i++) {
		if (processed_s[i] != processed_s[processed_s.length()-1]) 
			return false;
	}
	return true;
}
	
bool isPalindrome(std::string s) {
  // turn all into lowercase
  // ignore or remove non-alpha numeric
  std::regex regex("[^a-zA-Z0-9]+"); // <regex>
  s = std::regex_replace(s, regex, "");

  for (char& c: s) {
    c = std::tolower(c); // <cctype>

  return std::equal(s.begin(),s.begin() + s.length() / 2, s.rbegin());
}

// better way
#include <string>
#include <algorithm>
#include <cctype>

bool is_palindrome(std::string s) {
    s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) { return !std::isalnum(c); }), s.end());

    int len = s.size();
    for(int i=0; i<len/2; i++) {
        if (std::toupper(s[i]) != std::toupper(s[len-i-1])) {
            return false;
        }
    }
    return true;
}



