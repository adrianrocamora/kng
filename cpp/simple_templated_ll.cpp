#include <iostream>

template <typename T>
class ElementNode {
public:
	ElementNode(T data) : data_(data), next_(nullptr){};

	T getData() { return data_;}
	void setData(T data) { data_ = data; }

private:
	T	data_;
	ElementNode* next_;
};

int main() {
	class ElementNode<int> intList(3);
	std::cout << intList.getData() << std::endl;
	intList.setData(5);
	std::cout << intList.getData() << std::endl;

	return 0;
}
