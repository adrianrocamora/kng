#include <iostream>
#include <chrono>

int main() {
	std::chrono::time_point<std::chrono::system_clock> start_ver1 = std::chrono::system_clock::now();
	// Run some code here
	std::chrono::time_point<std::chrono::system_clock> end_ver1 = std::chrono::system_clock::now();

	auto start_ver2 = std::chrono::system_clock::now();
	// Run some code here
	auto end_ver2 = std::chrono::system_clock::now();
	return 0;
}
