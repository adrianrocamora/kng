#include <iostream>
#include <stack>
#include <exception>
#include <cppunit/TestCase.h>
class Queue {
public:
	bool empty() {
		return stackIn.empty() && stackOut.empty();
	}
	void push(int val) {
		stackIn.push(val);
	}
	void pop() {
		if (this->empty()) { throw std::exception();}
		if (stackOut.empty()) {
			while (!stackIn.empty()) {
				int tmp = stackIn.top();
				stackOut.push(tmp);
				stackIn.pop();
			}
		}
		stackOut.pop();
	}
	int top() {
		if (this->empty()) { throw std::exception();}
		if (stackOut.empty()) {
			while (!stackIn.empty()) {
				int tmp = stackIn.top();
				stackOut.push(tmp);
				stackIn.pop();
			}
		}
		return stackOut.top();
	}
private:
	std::stack<int> stackIn, stackOut;
};

int main() {
	std::cout << "QUEUE" << std::endl;
	Queue q1;
	q1.push(11);
	q1.push(12);
	q1.push(13);
	std::cout << "pushed" << std::endl;

	std::cout << q1.top()  << std::endl;
	q1.pop();
	std::cout << q1.top()  << std::endl;
	q1.pop();
	std::cout << q1.top()  << std::endl;


	std::cout << "STACK" << std::endl;
	std::stack<int> s1;
	s1.push(11);
	s1.push(12);
	s1.push(13);
	std::cout << "pushed" << std::endl;

	std::cout << s1.top()  << std::endl;
	s1.pop();
	std::cout << s1.top()  << std::endl;
	s1.pop();
	std::cout << s1.top()  << std::endl;


	return 0;
}
