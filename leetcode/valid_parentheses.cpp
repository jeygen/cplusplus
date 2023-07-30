/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

*/

class Solution {
public:            
  bool isValid(string s) {
    std::stack<char> stk;          
    for (char& c : s) { 
      switch (c) {                     
        case '(': stk.push(')'); break;       
        case '{': stk.push('}'); break;    
        case '[': stk.push(']'); break;                     
        case ')': case '}': case ']':
          if (stk.empty() || stk.top() != c) return false;
          else stk.pop();
          break;
        default: return false;  // In case any other characters are present in the string.
      }
    }
    return stk.empty();  // If stack is empty after all operations, the string is valid.
  }
};

