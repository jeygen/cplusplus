/*
543. Diameter of Binary Tree
Easy
12.3K
772
Companies

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:

Input: root = [1,2]
Output: 1

 

Constraints:

    The number of nodes in the tree is in the range [1, 104].
    -100 <= Node.val <= 100


*/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int current_max = 0;  // Initialize with 0 instead of -1
        depth(root, current_max);
        return current_max;
    }

    int depth(TreeNode* root, int &current_max) {
        if (!root) { return 0; }

        int l = depth(root->left, current_max);
        int r = depth(root->right, current_max);

        current_max = std::max(current_max, l + r);

        return std::max(l, r) + 1;
    }
};

