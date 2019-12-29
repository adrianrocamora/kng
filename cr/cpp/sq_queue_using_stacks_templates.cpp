#include <iostream>
#include <stack>
#include <exception>
template <typename T>
class Queue {
private:
	std::stack<T> stackIn;
	std::stack<T> stackOut;
public:
	void push(T val) {
		stackIn.push(val);
	}
	void pop() {
		if (this->empty()) { throw std::exception();}
		if (!stackOut.empty()) {
			stackOut.pop();
		} else {
			while (!stackIn.empty()) {
				T tmp = stackIn.top();
				stackIn.pop();
				stackOut.push(tmp);
			}
			stackOut.pop();
		}
	}
	T top() {
		if (this->empty()) { throw std::exception();}
		if (!stackOut.empty()) {
			return stackOut.top();
		} else {
			while (!stackIn.empty()) {
				T tmp = stackIn.top();
				stackIn.pop();
				stackOut.push(tmp);
			}
			return stackOut.top();
		}
	}
	bool empty() {
		return stackIn.empty() && stackOut.empty();
	}
};

int main() {
	Queue<double> q1;
	//q1.top();

	q1.push(1);
	q1.push(2);
	q1.push(3);

	std::cout << q1.top() << std::endl;
	q1.pop();
	std::cout << q1.top() << std::endl;
	q1.pop();
	std::cout << q1.top() << std::endl;

	return 0;
}


