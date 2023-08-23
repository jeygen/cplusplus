/*
926. Maximum Dot Product of Two Lists

Difficulty: Medium

Problem:

Given two lists of integers nums1 and nums2, each list may contain both positive and negative integers. We can pair up these two lists to form pairs of integers, with each element from both lists used exactly once. Return the maximum possible sum of dot products of the pairs formed. If it's not possible to form any pairs, return 0.

The dot product of two lists of length n is equal to the sum of their respective elements multiplied together: dotProduct = sum(nums1[i] * nums2[i]) for all 0 <= i < n.

Note:

The lengths of both lists are the same.
The pairs should be formed such that every element is used exactly once.
Example 1:

vbnet
Copy code
Input: nums1 = [1,3,5], nums2 = [2,4,6]
Output: 44
Explanation: We can form the following pairs: (1,2), (3,4), and (5,6) to get the dot product sum of 1*2 + 3*4 + 5*6 = 2 + 12 + 30 = 44.
Example 2:

vbnet
Copy code
Input: nums1 = [-1,-2,-3], nums2 = [-4,-5,-6]
Output: 32
Explanation: We can form the following pairs: (-1,-6), (-2,-5), and (-3,-4) to get the dot product sum of -1*-6 + -2*-5 + -3*-4 = 6 + 10 + 12 = 28.
Example 3:

vbnet
Copy code
Input: nums1 = [2,3,4], nums2 = [-1,-1,-1]
Output: -2
Explanation: The maximum dot product we can achieve is by taking the pair (2,-1) = -2. Taking any other pair will reduce the dot product.
Constraints:

1 <= nums1.length, nums2.length <= 1000
-1000 <= nums1[i], nums2[i] <= 1000
*/
