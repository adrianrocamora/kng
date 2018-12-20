#include <iostream>

class Something {
public:
	const int array_[6];
	Something() : array_{1,2,3,4,5,6} {}

};

int main() {
	Something s;
	for (auto x : s.array_) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}
