// could also add vector elements to set then compare sizes but slower
// best method
//
//

if (root == nullptr) 
    return nullptr;

invertTree(root->left);
invertTree(root->right);

std::swap(root->left, root->right);
