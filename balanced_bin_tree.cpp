/*
110. Balanced Binary Tree
Easy
9.6K
543
Companies

Given a binary tree, determine if it is
height-balanced
.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:

Input: root = []
Output: true
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        
    }
};



////
    bool isBalanced(TreeNode* root) {
          return (get_depth(root) != -1);
    }

    int get_depth(TreeNode* node) {
        if (!node) return 0;

        int l = get_depth(node->left);
        if (l == -1) return -1;  // Propagate unbalanced status up.

        int r = get_depth(node->right);
        if (r == -1) return -1;  // Propagate unbalanced status up.

        if (std::abs(l - r) > 1) return -1;  // Current node is unbalanced.

        return std::max(l, r) + 1; 
    }


/////
//

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        std::stack<std::pair<TreeNode*, int>> s;
        std::unordered_map<TreeNode*, int> depth;

        s.push({root, 0});

        while (!s.empty()) {
            auto [node, state] = s.top();

            if (!node || depth.find(node) != depth.end()) {
                s.pop();
                int l = depth[node->left];
                int r = depth[node->right];
                if (std::abs(l - r) > 1) {
                    return false;
                }
                depth[node] = 1 + std::max(l, r);
            } else {
                s.top().second = 1;  // mark as visited
                if (node->right) s.push({node->right, 0});
                if (node->left) s.push({node->left, 0});
                if (!node->left && !node->right) {
                    depth[node] = 1;
                }
            }
        }
        return true;
    }
};

