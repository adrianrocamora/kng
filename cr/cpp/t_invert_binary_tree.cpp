#include <iostream>


class TreeNode
{
public:
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int data) { this->data = data; this->left = nullptr; this->right = nullptr; }
};

TreeNode* invert_binary_tree(TreeNode *root)
{
	if (root == nullptr) {
		return root;
	} else {
		TreeNode *tmp = root->left;
		root->left = invert_binary_tree(root->right);
		root->right = invert_binary_tree(tmp);
		return root;
	}
}

void print_tree_preorder(TreeNode *root)
{
	if (root !=nullptr) {
		std::cout << root->data << std::endl;
		print_tree_preorder(root->left);
		print_tree_preorder(root->right);
	}
}

void delete_tree(TreeNode *root)
{
	if (root != nullptr) {
		delete_tree(root->left);
		delete_tree(root->right);
		delete root;
		root = nullptr;
	}
}

int main()
{
	TreeNode *a = new TreeNode(5);
	TreeNode *b = new TreeNode(2);
	TreeNode *c = new TreeNode(-3);
	TreeNode *d = new TreeNode(1);
	TreeNode *e = new TreeNode(7);

	TreeNode *root;
	root = a;
	root->left = b;
	root->left->left = c;
	root->left->right = d;
	root->right = e;


	print_tree_preorder(root);

	std::cout << "Inverting tree" << std::endl;
	invert_binary_tree(root);

	print_tree_preorder(root);

	delete_tree(root);

	return 0;
}








































































































































































































