#include <iostream>
#include <queue>
using namespace std;

class Stack {
	queue<int> *queue1 = new queue<int>();
	queue<int> *queue2 = new queue<int>();
	void swap_queues() {
		queue<int> *tmpQueue = queue1;
		queue1 = queue2;
		queue2 = tmpQueue;
	}
public:
	void push(int data) {
		queue1->push(data);	
	}

	bool isEmpty() {
		return queue1->empty() && queue2->empty();
	}
	int pop() {
		if (isEmpty()) {
			throw new exception();
		}
		while(queue1->size() > 1) {
			int value = queue1->front();
			queue1->pop();
			queue2->push(value);
		}
		int value =  queue1->front();
		queue1->pop();
		swap_queues();
		return value;
	}
};

int main()
{
	Stack *stack = new Stack();
	//std::cout << stack->isEmpty() << std::endl;

	stack->push(1);
	stack->push(2);
	stack->push(1);
	stack->push(2);
	stack->push(3);

	std::cout << stack->pop() << std::endl;
	std::cout << stack->pop() << std::endl;
	std::cout << stack->pop() << std::endl;
	std::cout << stack->pop() << std::endl;
	std::cout << stack->pop() << std::endl;

	return 0;
}

