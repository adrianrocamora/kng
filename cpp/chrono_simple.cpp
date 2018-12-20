#include <chrono>
#include <iostream>
#include <thread>

void wait(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

int main() {
    std::cout << "Hi, waiting 3 seconds:" << std::endl;
    wait(3);
    std::cout << "Done!" << std::endl;
}
