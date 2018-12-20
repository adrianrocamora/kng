#include <iostream>

class TreeNode
{
public:
	double data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(double data) { this->data = data; this->left = nullptr; this->right = nullptr;}
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

// Prints tree (pre-order)
void print_tree(TreeNode *root)
{
	if (root != nullptr) {
		std::cout << root->data << std::endl;
		print_tree(root->left);
		print_tree(root->right);
	}
}

int main()
{
	TreeNode *a = new TreeNode(11);
	TreeNode *b = new TreeNode(12);
	TreeNode *c = new TreeNode(13);

	a->left = b;
	a->right = c;

	std::cout << "Printing tree" << std::endl;
	print_tree(a);

	std::cout << "Deleting tree" << std::endl;
	delete_tree(a);

	return 0;
}
