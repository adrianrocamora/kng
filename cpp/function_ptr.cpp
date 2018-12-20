#include <iostream>
using namespace std;

void my_int_func(int x) {
	cout << "Hello from func with val: " << x << endl;
}

int main() {
	void (*foo)(int);
	foo = &my_int_func;
	(*foo)(2);
	foo(3);
	return 0;
}
