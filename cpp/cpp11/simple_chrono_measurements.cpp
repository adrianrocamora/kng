#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>

int main() {
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now - std::chrono::hours(24));
	std::cout << "24 hours ago, the time was " 
		<< std::put_time(std::localtime(&now_c), "%F %T") << std::endl;
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	std::cout << "Hello World" << std::endl;
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Printing took "
		<< std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()
		<< "us." << std::endl;

	return 0;
}

