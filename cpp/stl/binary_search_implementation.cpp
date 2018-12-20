#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
using namespace std;

template<class Iter, class T>
Iter binary_find(Iter begin, Iter end, T val) {
    Iter i = std::lower_bound(begin, end, val); // T is not required to be equality comparable
    //if (i != end && !(val < *i)) {
    if (i != end && val == *i) {
        return i;   // found
    } else {
        return end; // not found
    }
}

int main() {
    vector<int> v(50, 0);
    iota(v.begin(), v.end(), 0);
    auto res = binary_find<vector<int>::iterator, int>(v.begin(), v.end(), 10);
    cout << (res == v.end() ? "Element not found" : "Element is " + to_string(*res)) << endl;
}
