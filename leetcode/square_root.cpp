/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

    For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
*/

class Solution {
public:
    int mySqrt(int x) {
      if (x < 0) return  -1;
      else if (x == 1 || x == 0) return x;
      else if (x == 2) return 1;
      else {
        for (long i = 2; i < x ; i++) {
          if (i * i > x) return i - 1;
          if (i * i == x) return i;
        }
      }
      return -1;
    }
};

int mySqrt(int x) {
    if (x < 2) {
        return x;
    }

    long start = 0, end = x / 2;

    while (start <= end) {
        long mid = (start + end) / 2;
        if (mid * mid == x) {
            return mid;
        } else if (mid * mid < x) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return end;
}
