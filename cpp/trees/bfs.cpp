#include <iostream>
#include <queue>

class TreeNode
{
public:
	double data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(double data) { this->data = data; this->left = nullptr; this->right = nullptr;}
};

void breadth_first_search(TreeNode *root)
{
	std::queue<TreeNode *> queue;
	if (root != nullptr){
		queue.push(root);
		while (!queue.empty()) {
			TreeNode *node = queue.front();
			queue.pop();
			std::cout << node->data << std::endl;
			if (node->left != nullptr) { queue.push(node->left);}
			if (node->right != nullptr) { queue.push(node->right);}
		}
	}
}


int main() {
	return 0;
}
