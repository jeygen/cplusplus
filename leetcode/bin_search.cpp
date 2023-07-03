#include <vector>

// return index or -1 if not found
int bin_search(std::vector<int>& nums, int target) {
	int l =  0;
	int r = nums.size()-1;
	int mid = 0;

	// use r>=l or l<=r	
	while(r >= l) {
		mid = l + (r-l) / 2;
		if(nums[mid] == target) return mid;
		else if (nums[mid] < target) 
			l = mid+1;
		else
			r = mid-1;
	}

	return -1;
}


