#include <iostream>
#include <boost/range/irange.hpp>

int main() {
    for (int x : boost::irange(11,20)) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    // Output:
    // 11 12 13 14 15 16 17 18 19 
    for (int x : boost::irange(20,10,-1)) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
