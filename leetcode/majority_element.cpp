/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

// mine
class Solution {
public:
  int majority_element(vector<int>& nums) {
    int maj_num = (nums.size() + 1) / 2;
    std::unordered_map<int, int> um{};
    for (int& n : nums) {
      um[n]++;
      if (um[n] >= maj_num) { return n; }
    }
    return -1;
  }
}

// chatgpt
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::unordered_map<int, int> counts;
        int majorityElement = nums[0];
        for (const int num : nums) {
            ++counts[num];
            if (counts[num] > nums.size() / 2) {
                majorityElement = num;
                break;
            }
        }
        return majorityElement;
    }
};
