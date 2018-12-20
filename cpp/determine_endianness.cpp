#include <iostream>

int main() {
    int i = 1;
    char *zeroIfLittleEndian = (char*)&i;
    if (*zeroIfLittleEndian) {
        std::cout << "Little endian" << std::endl;
    } else {
        std::cout << "Big endian" << std::endl;
    }
}

