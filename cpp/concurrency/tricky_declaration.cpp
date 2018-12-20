#include <iostream>
#include <thread>

class Counter {
public:
	Counter() {}
	void operator() () const { /* ... */}
};

int main() {
	std::thread t1{Counter{}};
	// The following line won't work
	//std::thread t2(Counter());
	std::thread t3((Counter()));
	t1.join();
	//t2.join();
	t3.join();
}
