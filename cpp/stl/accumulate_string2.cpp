#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    //std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> v(10);
    std::iota(v.begin(), v.begin()+5, 0);

    std::string res = std::accumulate(v.begin(), v.end(), std::string{},
        [] (const std::string& a, int b) {
            return a.empty() ? std::to_string(b) : a + "-" + std::to_string(b);
        });
    std::cout << res << std::endl;


}
