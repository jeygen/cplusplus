#include <iostream>

// Define the structure for tree nodes
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    // Constructor to create a new node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

int main() {
    // Create nodes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Now we have a binary tree structured like this:
    //     1
    //    / \
    //   2   3
    //  / \ / \
    // 4  5 6  7

    // Example: Accessing values in the binary tree
    std::cout << "Root value: " << root->value << std::endl;
    std::cout << "Left child of root: " << root->left->value << std::endl;
    std::cout << "Right child of root: " << root->right->value << std::endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
