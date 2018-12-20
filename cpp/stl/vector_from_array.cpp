#include <iostream>
#include <vector>

int main() {
    int data[] = {1, 2, 3, 4, 5};
    std::vector<int> v(data, data + sizeof(data)/sizeof(data[0]));
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
