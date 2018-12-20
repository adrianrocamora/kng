#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::sort(v.begin(), v.end(), std::greater<int>());
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::sort(v.begin(), v.end(), std::less<int>());
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
