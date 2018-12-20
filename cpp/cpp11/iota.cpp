#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> v(20); // 20 ints initialized to 0
    std::iota(std::begin(v), std::end(v), 0);
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
