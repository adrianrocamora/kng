#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::string res = std::accumulate(v.begin(), v.end(), std::string{}, 
        [] (const std::string& a, int b) {
            return a.empty() ? std::to_string(b)
                : a + '-' + std::to_string(b);
        });
    std::cout << res << std::endl;
    // Output:
    //   1-2-3-4-5-6-7-8-9-10
}
