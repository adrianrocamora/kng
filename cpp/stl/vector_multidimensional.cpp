#include <vector>
#include <iostream>

int main() {
	std::vector<int> v1(4);
	std::vector<int> v2(4, 9);
	std::vector<std::vector<int>> vv(5, std::vector<int>(6, 42.0));
	for (int x : v1) {
		std::cout << x << " " ;
	}
	std::cout << std::endl;
	for (int x : v2) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	//for (std::vector<int>& v : vv) {
	for (auto& v : vv) {
		for (int x : v) {
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
	
	return 0;
}
