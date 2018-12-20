#include <iostream>
#include "test.h"

int main() {
	int a = 12;
	std::cout << "Hello World" << std::endl;
	std::cout << "Hello 2" << std::endl;
	a = a + 12;
	a = 3;
	std::cout << a << std::endl;
	print_goodbye();
	return 0;
}
