#include <iostream>

class TreeNode
{
public:
	double data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(double data) { this->data = data; this->left = nullptr; this->right = nullptr; }
};

void print_preorder(TreeNode *root)
{
	if (root != nullptr) {
		std::cout << root->data << std::endl;
		print_preorder(root->left);
		print_preorder(root->right);
	}
}

void print_inorder(TreeNode *root)
{
	if (root != nullptr) {
		print_inorder(root->left);
		std::cout << root->data << std::endl;
		print_inorder(root->right);
	}
}

void print_postorder(TreeNode *root)
{
	if (root != nullptr) {
		print_postorder(root->left);
		print_postorder(root->right);
		std::cout << root->data << std::endl;
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
	TreeNode *node_11 = new TreeNode(11.0);
	TreeNode *node_12 = new TreeNode(12.0);
	TreeNode *node_13 = new TreeNode(13.0);
	TreeNode *node_14 = new TreeNode(14.0);
	TreeNode *node_15 = new TreeNode(15.0);
	TreeNode *node_16 = new TreeNode(16.0);
	TreeNode *node_17 = new TreeNode(17.0);
	TreeNode *node_18 = new TreeNode(18.0);

	node_11->left = node_12;
	node_11->left->left = node_13;
	node_11->left->right = node_14;
	node_11->right = node_15;
	node_11->right->right = node_16;
	node_11->right->right->left = node_17;
	node_11->right->right->right = node_18;

	std::cout << "PREORDER:" << std::endl;
	print_preorder(node_11);
	
	std::cout << std::endl << "INORDER:" << std::endl;
	print_inorder(node_11);

	std::cout << std::endl << "POSTORDER:" << std::endl;
	print_postorder(node_11);

	delete_tree(node_11);

	return 0;
}


