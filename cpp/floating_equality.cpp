#include <iostream>
#include <cmath>
int main() {
	std::cout << std::fabs(3.5) << std::endl;
	double a = 3.5;
	float b = 3.4;
	std::cout << "Equality test: " << (((a - b) == 0.1) ?  "Naively expected" : "Unexpected") << std::endl;
	return 0;
}

