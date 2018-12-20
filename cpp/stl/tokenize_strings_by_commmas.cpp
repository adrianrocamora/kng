#include <string>
#include <iostream>
#include <sstream>

int main() {
    std::string s = "testing, one, two three";
    std::istringstream is(s);
    std::string part;
    while (getline(is, part, ',')) {
        std::cout << part << std::endl;
    }
    // Output:
    //testing
    // one
    // two three
}

