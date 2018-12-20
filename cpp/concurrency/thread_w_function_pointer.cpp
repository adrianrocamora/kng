#include <thread>
#include <iostream>

using namespace std;

void counter(int id, int numIterations) {
	for (int i = 0; i < numIterations; ++i) {
		cout << "Counter " << id << " has value ";
		cout << i << endl;
	}
}

// On Mac OS you get interleaved characters with this code
int main() {
	thread t1(counter, 1, 6);
	thread t2(&counter, 2, 4);
	// Block until the corresponding threads are done
	// Otherwise the application will exit in this case
	// before the threads are done
	t1.join();
	t2.join();
}
