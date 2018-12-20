#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    long long sum = std::accumulate(v.begin(), v.end(), (long long)0);
    std::cout << "Sum: " << sum << std::endl;
    // Output:
    //   1 2 3 4 5 6 7 8 9 10 
    //   Sum: 55
}
