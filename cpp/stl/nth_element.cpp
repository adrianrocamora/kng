#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};
    for (auto x : v) { cout << x << " "; } cout << endl;

    nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
    cout << "The median is " << v[v.size() / 2] << endl;
    for (auto x : v) { cout << x << " "; } cout << endl;

    nth_element(v.begin(), v.begin() + 1, v.end(), greater<int>());
    cout << "The second largest element is " << v[1] << endl;
    for (auto x : v) { cout << x << " "; } cout << endl;
}
