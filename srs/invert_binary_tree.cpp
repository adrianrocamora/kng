
class TreeNode {
private:
    double data_;
    TreeNode *left_;
    TreeNode *right_;
public:
    TreeNode(int data) : data_(data), left_(nullptr), right_(nullptr){};
    friend TreeNode* invert_binary_tree(TreeNode* root);

};

TreeNode* invert_binary_tree(TreeNode *root) {
    if (root != nullptr) {
        TreeNode *tmpLeft = root->left_;
        root->left_ = invert_binary_tree(root->right_);
        root->right_ = invert_binary_tree(tmpLeft);
    }
    return root;
}

int main() {
    TreeNode *a = new TreeNode(12);
    TreeNode *b = invert_binary_tree(a);
}

