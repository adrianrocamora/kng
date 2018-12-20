#include <stack>
#include <iostream>
#include <stdexcept>

using namespace std;

class SlowQueue {
public:
	SlowQueue();
	~SlowQueue();

	void enqueue(int);
	int dequeue();
	bool empty();

private:
	stack<int> stackIn;
	stack<int> stackOut;
};

SlowQueue::SlowQueue()
{}

SlowQueue::~SlowQueue()
{}

bool SlowQueue::empty()
{
	if (stackOut.empty() && stackIn.empty()) {
		return true;
	}
	else {
		return false;
	}
}

void SlowQueue::enqueue(int num)
{
	stackIn.push(num);
}

int SlowQueue::dequeue()
{
	if (!stackOut.empty()) {
		int tmp = stackOut.top();
		stackOut.pop();
		return tmp;
	}
	else if (!stackIn.empty()) {
		while (!stackIn.empty()) {
			int tmp = stackIn.top();
			stackOut.push(tmp);
			stackIn.pop();
		}
		int tmp = stackOut.top();
		stackOut.pop();
		return tmp;
	}
	else {
		//+++change this
		throw invalid_argument("a or b negative");
	}
	return 0;
}



int main()
{

	SlowQueue sq;
	
	sq.enqueue(2);
	sq.enqueue(4);
	sq.enqueue(6);

	cout << sq.dequeue() << endl;
	cout << sq.dequeue() << endl;
	cout << sq.dequeue() << endl;

	return 0;
}
