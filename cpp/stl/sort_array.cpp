#include <algorithm>
#include <iostream>

int main() {
    int data[] = {1,4,2,5,6,3,0,7,9,8};
    for (int i = 0; i < 10; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    std::sort(&data[0], &data[10]);
    for (int i = 0; i < 10; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

