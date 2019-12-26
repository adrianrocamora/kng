#include <iostream>
#include <queue>

using namespace std;

// Stack using queues
class SlowStack 
{
public:
	SlowStack();
	~SlowStack();

	void push(int);
	int pop();
	bool empty();

private:
	queue<int> *queuePush;
	queue<int> *queuePop;
	void swapQueues();
};

SlowStack::SlowStack()
{
	queuePush = new queue<int>;
	queuePop = new queue<int>;
}

SlowStack::~SlowStack()
{
	delete queuePush;
	delete queuePop;
}

void SlowStack::push(int num)
{
	queuePush->push(num);
}

int SlowStack::pop()
{
	if (queuePush->empty()) {
		throw new exception;
	}
	// Push all items in the push queue except the last one to the other
	// pop queue
	while (queuePush->size() != 1) {
		int tmp = queuePush->front();
		queuePush->pop();
		queuePop->push(tmp);
	}
	int tmp = queuePush->front();
	queuePush->pop();
	swapQueues();

	return tmp;
}

bool SlowStack::empty()
{
	return queuePush->size() + queuePop->size() == 0;
}

void SlowStack::swapQueues()
{
	queue<int> *tmp;
	tmp = queuePush;
	queuePush = queuePop;
	queuePop = tmp;
}

int main()
{
	SlowStack stackTest;
	stackTest.push(2);
	stackTest.push(4);
	stackTest.push(6);
	cout << "Test on windows" << endl;
	cout << "Is the stack empty? " << (stackTest.empty() ? "Yes" : "No") << endl;
	cout << stackTest.pop() << endl;
	cout << stackTest.pop() << endl;
	cout << stackTest.pop() << endl;

	return 0;
}
