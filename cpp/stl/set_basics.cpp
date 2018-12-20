#include <set>
#include <iostream>

int main() {
    std::set<int> s= {1,2,3,4,5};
    for (int x : s ) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    s.insert(7);
    for (int x : s ) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    s.erase(3);
    for (int x : s ) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

