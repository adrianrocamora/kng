#include <chrono>
#include <thread>
#include <iostream>

int main() {
	std::cout << "About to wait for 3 seconds" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "Done" << std::endl;

}
