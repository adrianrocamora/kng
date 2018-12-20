#include <iostream>


template <typename M, typename N>
auto multiply(M const& m, N const& n) -> decltype(m * n);

auto main() -> int {
    std::cout << "Testing trailing return type for main()" << std::endl;
}


