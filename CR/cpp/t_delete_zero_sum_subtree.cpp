#include <iostream>

class TreeNode
{
public:
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int data) { this->data = data; this->left = nullptr; this->right = nullptr;}
};

void delete_tree(TreeNode *root)
{
	if (root != nullptr) {
		delete_tree(root->left);
		delete_tree(root->right);
		delete root;
		root = nullptr;
	}
}

int sum_subtree(TreeNode *root)
{
	if (root == nullptr) {
		return 0;
	} else {
		return root->data + sum_subtree(root->left) + sum_subtree(root->right);
	}
}


void delete_zero_sum_subtree(TreeNode *root)
{
	if (root == nullptr) {
		return;
	}
	if (sum_subtree(root->left) == 0) {
		delete root->left;
		root->left = nullptr;
	}
	if (sum_subtree(root->right) == 0) {
		delete root->right;
		root->right = nullptr;
	}
}

void print_tree_preorder(TreeNode *root)
{
	if (root != nullptr) {
		std::cout << root->data << std::endl;
		print_tree_preorder(root->left);
		print_tree_preorder(root->right);
	}
}

int main()
{
	TreeNode *tmpA = new TreeNode(5);
	TreeNode *tmpB = new TreeNode(2);
	TreeNode *tmpC = new TreeNode(-3);
	TreeNode *tmpD = new TreeNode(1);
	TreeNode *tmpE = new TreeNode(7);


	TreeNode *root;
	root = tmpA;
	root->left = tmpB;
	root->left->left = tmpC;
	root->left->right = tmpD;
	root->right = tmpE;

	std::cout << "Printing tree (pre-order)" << std::endl;
	print_tree_preorder(root);

	std::cout << "Applying delete_zero_sum_subtree to tree" << std::endl;
	delete_zero_sum_subtree(root);

	std::cout << "Printing tree (pre-order)" << std::endl;
	print_tree_preorder(root);

	std::cout << "Deleting tree" << std::endl;
	delete_tree(root);
	return 0;
}
