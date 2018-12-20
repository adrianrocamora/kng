#include <iostream>
#include <memory>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
struct BTNode {
	T data;
	unique_ptr<BTNode<T>> left, right;
};

int main() {
	//      3
	//    2   5
	//  1    4 6
	auto tree = make_unique<BTNode<int>>(BTNode<int>{3});
	tree->left = make_unique<BTNode<int>>(BTNode<int>{2});
	tree->left->left = make_unique<BTNode<int>>(BTNode<int>{1});
	tree->right = make_unique<BTNode<int>>(BTNode<int>{5});
	tree->right->left = make_unique<BTNode<int>>(BTNode<int>{4});
	tree->right->right = make_unique<BTNode<int>>(BTNode<int>{6});

	vector<int> res;
	//vector<int> res = inorder_traversal(tree);
	vector<int> expected_res = {1,2,3,4,5,6};
	assert(equal(expected_res.begin(), expected_res.end(), res.begin(), res.end()));
	return 0;
}

