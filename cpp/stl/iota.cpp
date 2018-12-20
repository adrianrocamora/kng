#include <numeric>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v1(10), v2(10);
    std::iota(std::begin(v1), std::end(v1), 0);
    std::iota(v2.begin(), v2.end(), 0);
    for (int x : v1) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    for (int x : v2) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
