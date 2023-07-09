/*
 * Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
*/


// my solution
//
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> m{};
        for (char c : magazine) {
            m[c]++;
        }

        for (char c : ransomNote) {
            if (m.find(c) != m.end() && m[c] > 0) {
                m[c]--;
            } else return false;
        }

        return true;
    }
};

// gpt sol is same except doesn't have find(), mine is safer

