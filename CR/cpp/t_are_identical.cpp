#include <iostream>

class TreeNode
{ 
public:
	double data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(double data) { this->data = data; this->left = nullptr; this->right = nullptr;}
};

bool are_identical(TreeNode *root1, TreeNode *root2)
{
	if (root1 == nullptr && root2 == nullptr) {
		return true;
	}
	if (root1 != nullptr && root2 != nullptr) {
		return (root1->data == root2->data &&
				are_identical(root1->left, root2->left) &&
				are_identical(root1->right, root2->right));
	}
	return false;
}

int main()
{
	TreeNode a(12);
	TreeNode b(32);
	TreeNode c(12);
	TreeNode d(32);

	// Shoul return 0
	std::cout << "Expecting 0: " << are_identical(&a, &b) << std::endl;
	// Should return 1
	std::cout << "Expecting 1: " << are_identical(&a, &c) << std::endl;

	a.left = &b;
	std::cout << "Expecting 0: " << are_identical(&a, &c) << std::endl;
	c.left = &d;
	std::cout << "Expecting 1: " << are_identical(&a, &c) << std::endl;

	return 0;
}
