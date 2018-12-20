#include <random>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    random_device rd;
    mt19937 g(rd());
    vector<int> v{1,2,3,4,5,6,7,8,9,10};

    shuffle(v.begin(), v.end(), g);
    for (auto& x : v) {
        cout << x  << " ";
    }
    cout << endl;


}
