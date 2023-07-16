#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <queue>
#include <cctype>
#include <regex>
#include <set>

TreeNode* invertTree(TreeNode* root) {

  return root;
}
  

int binary_sort(vector<int>& v, int target) {
  int l, r, mid;
  l = 0;
  r = v.size() - 1;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (target == v[mid]) return mid;
    if (target < v[mid]) r = mid - 1;
    if (target > v[mid]) l = mid + 1;
  }
  return -1;
}  



