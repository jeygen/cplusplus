/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

 

Example 1:

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
Example 2:

Input: n = 1, bad = 1
Output: 1
*/

///////// my sol
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
           if (!isBadVersion(n)) return n + 1;
           return firstBadVersion(n-1);
    }
};

////////// gpt sol
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (isBadVersion(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};

// debug

using namespace std;
  
 bool isBadVersion(int n) {
   return n > 3 ? true : false;
 }
  
 int firstBadVersion(int n) {
     int left = 1;
     int right = n;
     
     while (left <= right) {
         int mid = left + (right - left) / 2;
         cout << "mid: " << mid << endl;
         
         if (isBadVersion(mid)) {
             right = mid - 1;
             cout << "right: " << right << endl;
         } else {
             left = mid + 1;
             cout << "left: " << left << endl;
         }
     }
     
     return left;
 }
  
 int main() {
   firstBadVersion(5);
   return 0;
 }


