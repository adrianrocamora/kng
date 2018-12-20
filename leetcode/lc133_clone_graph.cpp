#include <iostream>
#include <vector>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node) {
		if (node == nullptr) { return node; }
		UndirectedGraphNode *res = new a;

		return node;
	}
};

int main() {

	UndirectedGraphNode a(0);;

	Solution sol;
}
