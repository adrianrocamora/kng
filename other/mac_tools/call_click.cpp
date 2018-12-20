#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>

void pause_n_seconds(int n) 
{
    std::this_thread::sleep_for(std::chrono::seconds(n));
}

int main() 
{
    std::cout << "Generating click in 3" << std::endl;
    pause_n_seconds(1);
    std::cout << "Generating click in 2" << std::endl;
    pause_n_seconds(1);
    std::cout << "Generating click in 1" << std::endl;
    pause_n_seconds(1);
    system("./click 100 10");
    pause_n_seconds(3);
    system("./click 10 10");
    pause_n_seconds(3);
    system("./click 100 10");
    pause_n_seconds(3);
}
