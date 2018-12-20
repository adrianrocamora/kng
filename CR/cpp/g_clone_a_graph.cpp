#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

struct Node {
	int data;
	list<Node*> neighbors;
	Node(int d) :data(d) {}
};

Node* clone_rec(Node* root, unordered_map<Node*,Node*>& nodes_completed)
{
	if (root == nullptr) {
		return nullptr;
	}

	Node *pNew = new Node(root->data);
	nodes_completed[root] = pNew;

	for (Node *p : root->neighbors) {
		auto x = nodes_completed.find(p);
		if (x == nodes_completed.end()) {
			pNew->neighbors.push_back(clone_rec(p, nodes_completed));
		} else {
			pNew->neighbors.push_back(x->second);
		}
	}
	return pNew;
}

Node* clone(Node* root) {
	unordered_map<Node*, Node*> nodes_completed;
	return clone_rec(root, nodes_completed);
}

int main()
{
	return 0;
}
