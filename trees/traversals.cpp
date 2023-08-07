/*
    In-Order (Left, Root, Right) start far left, ignore height , go left to right
    Pre-Order (Root, Left, Right) root then left to hit root then left right 
    Post-Order (Left, Right, Root) start far left, dfs
    Level-Order (Breadth-first)
*/

void inOrderRecursive(TreeNode* root) {
    if (!root) return;
    inOrderRecursive(root->left);
    cout << root->val << " ";
    inOrderRecursive(root->right);
}

void inOrderIterative(TreeNode* root) {
    std::stack<TreeNode*> s;
    TreeNode* curr = root;

    while (curr || !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
}

void preOrderRecursive(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preOrderRecursive(root->left);
    preOrderRecursive(root->right);
}

void preOrderIterative(TreeNode* root) {
    if (!root) return;
    std::stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* curr = s.top();
        s.pop();
        cout << curr->val << " ";

        if (curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);
    }
}

void postOrderRecursive(TreeNode* root) {
    if (!root) return;
    postOrderRecursive(root->left);
    postOrderRecursive(root->right);
    cout << root->val << " ";
}

void postOrderIterative(TreeNode* root) {
    if (!root) return;
    std::stack<TreeNode*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        TreeNode* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left) s1.push(curr->left);
        if (curr->right) s1.push(curr->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->val << " ";
        s2.pop();
    }
}

void levelOrder(TreeNode* root) {
    if (!root) return;
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        cout << curr->val << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}


