// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }
    
    int checkBalance(TreeNode* node) {
        if (!node) return 0;

        int leftHeight = checkBalance(node->left);
        if (leftHeight == -1) return -1;  // left subtree is not balanced

        int rightHeight = checkBalance(node->right);
        if (rightHeight == -1) return -1;  // right subtree is not balanced

        if (abs(leftHeight - rightHeight) > 1) return -1;  // current node is not balanced

        return max(leftHeight, rightHeight) + 1;  // return the height of the current node
    }
};
