// gpt style

#include <vector>

using namespace std;

void invertBinaryTree(vector<int>& tree) {
    for (int i = 0; i < tree.size(); i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < tree.size() && right < tree.size()) {
            swap(tree[left], tree[right]);
        }
    }
}

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

