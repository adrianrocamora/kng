#include <iostream>
#include <memory>

using namespace std;

class Simple {
public:
	void output() { cout << "Hello from simple" << endl; }
	~Simple() {
		cout << "Closing Simple" << endl;
	}
};


int main() {
	{
		auto simpleUniquePtr = make_unique<Simple>();
		simpleUniquePtr->output();
		unique_ptr<Simple> simpleUniquePtr2 = move(simpleUniquePtr);
		simpleUniquePtr2->output();
		unique_ptr<Simple> simpleUniquePtr3(move(simpleUniquePtr2));
		simpleUniquePtr3->output();
	}
	cout << endl;
	{
		auto simpleSharedPtr = make_shared<Simple>();
		simpleSharedPtr->output();
		shared_ptr<Simple> simpleSharedPtr2(simpleSharedPtr);
		simpleSharedPtr2->output();
		shared_ptr<Simple> simpleSharedPtr3 = simpleSharedPtr;
		simpleSharedPtr3->output();
	}
	cout << "End of main" << endl;
}
