#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <queue>
#include <cctype>
#include <regex>
#include <set>

TreeNode* invertTree(TreeNode* root) {
  TreeNode* current = root;
  if (current->left && current ->right) {
      swap(current->left, current->right);
  }
  return current->left;
}
  



int main(int argc, char** argv) {
	int doggy = 1;
	int cat = doggy	
  int doggy
  int dogg

}
