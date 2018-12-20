#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

template <typename T>
bool binary_search_fun(const vector<T>& v, T key) {
    int l = 0, m, r = v.size() - 1;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (v[m] < key) {
            l = m + 1;
        } else if (v[m] == key) {
            return true;
        } else {
            r = m - 1;
        }
    }
    return false;
}

int main() {
	vector<int> test{1,2,2,5,6,8,12,15,16,20};
	assert(binary_search_fun<int>(test, -3) == false);
	assert(binary_search_fun<int>(test, 1) == true);
	assert(binary_search_fun<int>(test, 3) == false);
	assert(binary_search_fun<int>(test, 2) == true);
	assert(binary_search_fun<int>(test, 7) == false);
	assert(binary_search_fun<int>(test, 12) == true);
	assert(binary_search_fun<int>(test, 20) == true);
	assert(binary_search_fun<int>(test, 37) == false);
}

