/*
242. Valid Anagram
Easy
10K
319
Companies

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
      std::unordered_map um;
        
    }
};
 
class Solution {
public:
    bool isAnagram(string s, string t) {
      std::unordered_map<char, int> m1;
      std::unordered_map<char, int> m2;
      for(char c : s) {
          m1[c]++;
      }   
      for(char c : t) {
          m1[c]--;
      }   
      return m1 == m2;
    }
};

// chat gpt
#include <unordered_map>
#include <string>

bool isAnagram(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }

    std::unordered_map<char, int> freqMap;

    // Increment character count for string s
    for (char c : s) {
        freqMap[c]++;
    }

    // Decrement character count for string t
    for (char c : t) {
        if (freqMap[c] == 0) {
            return false; // If character count goes negative, t has more of that character than s
        }
        freqMap[c]--;
    }

    // If we reached this point, the two strings are anagrams
    return true;
}

int main() {
    std::string s1 = "anagram", t1 = "nagaram";
    std::string s2 = "rat", t2 = "car";

    std::cout << isAnagram(s1, t1) << std::endl; // true
    std::cout << isAnagram(s2, t2) << std::endl; // false

    return 0;
}

