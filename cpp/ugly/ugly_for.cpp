#include <iostream>

int main() {
	int i;
	for (i = 100; i--;);
	std::cout << i << std::endl;
	for (i = 100; --i;);
	std::cout << i << std::endl;
}
