#include <iostream>
#include <cmath>

bool isEqual(double a, double b, double eps = 0.0001) {
	return std::abs(a - b) < eps;
}

int main() {
	std::cout << (isEqual(2.3, 2.3001, 0.1) ? ("Equal") : ("Different")) << std::endl;
}

