#include <iostream>
#include <queue>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void bfs(TreeNode* root) {
    if (root == nullptr) { return; }
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* tmp = q.front();
        q.pop();
        if (tmp != nullptr) {
            q.push(tmp->left);
            q.push(tmp->right);
            std::cout << tmp->val << " ";
        }
    }
    std::cout << std::endl;
}

void dfs_rec(TreeNode* root) {
    if (root == nullptr) { return; }
    std::cout << root->val << " ";
    dfs_rec(root->left);
    dfs_rec(root->right);
}
void dfs(TreeNode* root) {
    if (root == nullptr) { return; }
    dfs_rec(root);
    std::cout << std::endl;
}
void print_preorder(TreeNode* root) {
    if (root == nullptr) { return; }
    std::cout << root->val << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}
void print_inorder(TreeNode* root) {
    if (root == nullptr) { return; }
    print_inorder(root->left);
    std::cout << root->val << " ";
    print_inorder(root->right);
}
void print_postorder(TreeNode* root) {
    if (root == nullptr) { return; }
    print_postorder(root->left);
    print_postorder(root->right);
    std::cout << root->val << " ";
}

int main() {
    TreeNode a(1), b(2), c(3), d(4), e(5), f(6), g(7);
    a.left = &b;
    b.left = &c;
    b.right = &d;
    a.right = &e;
    e.left = &f;
    e.right = &g;
    dfs(&a);
    bfs(&a);
}
