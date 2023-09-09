/*
Longest Palindrome
Easy

Given a string s which consists of lowercase or uppercase letters, return 
the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        int odd_flag = 0;
        int counter = 0;
        std::unordered_map<char, int> um;

        // Count occurrences of each character
        for (char& c : s) {
            um[c]++;
        }

        for (auto& [key, value] : um) {
            if (value % 2 == 1) {
                odd_flag++;
            }
            counter += (value / 2) * 2; // add even part
        }

        // If there's at least one odd count, we can use one character as the center of the palindrome
        if (odd_flag > 0) {
            counter++;
        }

        return counter;
    }
};


// better version of mine

class Solution {
public:
    int longestPalindrome(string s) {
         std::unordered_map<char, int> um;
         int total_sum = 0;
         int odd_flag = 0;

         for (auto& c : s) {
          um[c]++;
         }

         for (auto i = um.begin(); i != um.end(); i++) {
          if (i->second % 2 == 0) {
            total_sum += i->second;
          } else {
            total_sum += (i->second - 1);
            odd_flag = 1;
          }
         }

         return odd_flag ? total_sum + 1 : total_sum;
    }
};

// chat_gpt
class Solution {
public:
    int longestPalindrome(string s) {
        std::unordered_set<char> odd_chars;
        int counter = 0;

        for (char c : s) {
            if (odd_chars.count(c)) {
                counter += 2; // found a pair
                odd_chars.erase(c);
            } else {
                odd_chars.insert(c);
            }
        }

        // If there's at least one character left in odd_chars, we can use one as the center
        if (!odd_chars.empty()) {
            counter++;
        }

        return counter;
    }
};

