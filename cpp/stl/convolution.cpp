#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

// Convolution filter to calculate the median value?
int main() {
    std::vector<int> data{0,0,0,1,2,3,3,3,3,2,1,0,0,0};
    int n = int(data.size());
    std::vector<int> convolution_kernel(n);
    for (int i = 0; i < n; i++) {
        convolution_kernel[i] = (i+1) * (n-i);
    }
    double result = double(std::inner_product(data.begin(), data.end(), convolution_kernel.begin(), 0)) / 
                    std::accumulate(convolution_kernel.begin(), convolution_kernel.end(), 0);
    std::cout << "Result: " << result << std::endl;
}
