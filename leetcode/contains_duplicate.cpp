// first attempt

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> s{};
        for(int i=0; i<nums.size(); i++) {
            s.insert(nums[i]);
        }
        return (s.size() != nums.size());
    }
};

// set is nlogn, use hash map for n

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> uniqueSet{};
        for (const auto& num : nums) {
            if (uniqueSet.count(num) > 0) {
                return true;  // Found a duplicate
            }
            uniqueSet.insert(num);
        }
        return false;  // No duplicates found
    }
};

