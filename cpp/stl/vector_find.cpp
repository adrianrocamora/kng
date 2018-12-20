#include <vector>
#include <iostream>
#include <algorithm>

int main() {
	std::vector<int> v = {1, 4, 9, 16, 25, 36, 49, 64, 81};
	auto it = find(v.begin(), v.end(), 49);
	if (it == v.end()) {
		std::cout << "Not found" << std::endl;
	} else {
		std::cout << "Found " << *it << " at index " << it - v.begin() << std::endl;
	}
}
