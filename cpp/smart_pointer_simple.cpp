#include <iostream>
#include <memory>

class Node {
public:
	int data;
	std::shared_ptr<Node> next;
	Node(int data) { this->data = data; this->next = nullptr; }
};

int main() {
	std::shared_ptr<Node> n1(new Node(11));
	std::shared_ptr<Node> n2(new Node(12));
	std::shared_ptr<Node> n3(new Node(13));

	n1->next = n2;
	n1->next->next = n3;

	// Valgrind does not detect any memory leaks

	return 0;
}
















































































