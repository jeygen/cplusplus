// Homemade searches

#include <bits/stdc++.h> // all std libs, gcc only tho
using namespace std;

// O(n)
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// O(logn)
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
		// mid calc prevents overflow
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int my_bin_search(int a[], int l, int r, int target) {
	if (l <= r) {
		int mid = l + (r - l) / 2;
		if (target == a[mid]) 
			return mid;
		if (target > a[mid]) 
			return my_bin_search(a, mid + 1, r, target);	
		if (target < a[mid]) 
			return my_bin_search(a, l, mid - 1, target);	
	}
	return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = linearSearch(arr, n, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    int result = binarySearch(arr, n, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;


// can use algorithm library for these as well
	// find() for linear

    vector<int> v = {2, 3, 4, 10, 40};
    int x2 = 10;

    auto it = find(v.begin(), v.end(), x2);
    if (it != v.end())
        cout << "Element found at index " << distance(v.begin(), it) << "\n";
    else
        cout << "Element not found\n";

	// binary_search()
		// returns boolean if found in seq
		// lower_b() returns iterator of location or i of location where should be
		// these functions only work with sorted content

	    if (binary_search(v.begin(), v.end(), x)) {
        auto it = lower_bound(v.begin(), v.end(), x);
        cout << "Element found at index " << distance(v.begin(), it) << "\n";
    } else {
        cout << "Element not found\n";
    }



    return 0;
}

