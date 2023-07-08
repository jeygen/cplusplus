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
 
        
        
};

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        // swap left and right children
        TreeNode* temp = current->left;
        current->left = current->right;
        current->right = temp;

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

