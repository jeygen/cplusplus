#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <queue>
#include <cctype>
#include <regex>
#include <set>

TreeNode* invertTree(TreeNode* root) {
  if (root == nullptr) return nullptr;

  while (root->left && root->right) {
    std::swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
  }

  return root;
}
  
  
  
  



