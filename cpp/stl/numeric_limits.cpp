#include <limits>
#include <iostream>
#include <cstdint>
#include <string>

int main() {
    std::cout << std::to_string(std::numeric_limits<int8_t>::min()) << std::endl;  // -128
    std::cout << std::to_string(std::numeric_limits<int8_t>::lowest()) << std::endl;  // -128
    std::cout << std::to_string(std::numeric_limits<int8_t>::max()) << std::endl;  //  127
    std::cout << std::to_string(std::numeric_limits<uint8_t>::min()) << std::endl; //    0
    std::cout << std::to_string(std::numeric_limits<uint8_t>::lowest()) << std::endl; //    0
    std::cout << std::to_string(std::numeric_limits<uint8_t>::max()) << std::endl; //  255
}
