/*
Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:

Input: root = [2,1,3]
Output: [2,3,1]

Example 3:

Input: root = []
Output: []
*/

#include <vector>

using namespace std;

TreeNode* invertTree(TreeNode* root) {
  if (tree == nullptr) {
    return nullptr;
  }

  invertBinaryTree(tree->left);
  invertBinaryTree(tree->right);

  std::swap(tree->left, tree->right);
}




















// gpt style


TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
  
    invertTree(root->left);
    invertTree(root->right);

    std::swap(root->left, root->right);

    return root;
}


#include <vector>

using namespace std;


TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    // swap left and right children
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // invert left and right subtrees
    invertTree(root->left);
    invertTree(root->right);

    return root;
}


TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    // dont need visited array as no cycles in trees
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        // swap left and right children
        TreeNode* temp = current->left;
        current->left = current->right;
        current->right = temp;

        // if not a nullptr 
        if (current->left) {
            q.push(current->left);
        }

        if (current->right) {
            q.push(current->right);
        }
    }

    return root;
}

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* current = s.top();
        s.pop();

        // swap left and right children
        TreeNode* temp = current->left;
        current->left = current->right;
        current->right = temp;

        if (current->left) {
            s.push(current->left);
        }

        if (current->right) {
            s.push(current->right);
        }
    }

    return root;
}

