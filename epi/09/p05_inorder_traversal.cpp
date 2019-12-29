#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T data;
	Node<T> *left, *right, *parent;
	Node(T dataIn) : data(dataIn), left(nullptr), right(nullptr), parent(nullptr) {}
};

template <typename T>
void inorder_traversal(Node<T>* r) {
	if (!r) { return; }
	Node<T> *prev = nullptr, *curr = r, *next;
	while (curr) {
		if (!prev || prev->left == curr || prev->right == curr) {
			if (curr->left) {
				next = curr->left;
			} else {
				cout << curr->data << endl;
				next = curr->right ? curr->right : curr->parent;
			}
		} else if (curr->left == prev) {
			cout << curr->data << endl;
			next = curr->right ? curr->right : curr->parent;
		} else { // curr->right == prev
			next = curr->parent;
		}
		prev = curr;
		curr = next;
	}
}

int main() {
	Node<int> n1(1);
	Node<int> n2(2);
	Node<int> n3(3);
	Node<int> n4(4);
	Node<int> n5(5);
	Node<int> n6(6);
	Node<int> n7(7);
	Node<int> n8(8);
	Node<int> n9(9);

	Node<int> *root;
	root = &n4;
	root->left = &n2;
	root->left->left = &n1;
	root->left->left->parent = &n1;
	root->left->right = &n3;
	root->right = &n9;
	root->right->left = &n7;

	root->left->parent = &n4;
	root->right->parent = &n4;
	root->left->left->parent = &n2;
	root->left->right->parent = &n2;
	root->right->left->parent = &n9;

	inorder_traversal<int>(root);
}
