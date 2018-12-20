#include <iostream>
#include <vector>
#include <random>
#include <chrono>
//#include <ctime>

using namespace std;

int main() {
    // For some reason the following two lines are needed 
    // instead of the one-liner version
    auto now = chrono::system_clock::now().time_since_epoch().count();
    //auto now = time(0);
    auto generator = default_random_engine{now};
    vector<int> v{1,2,3,4,5,6,7,8};
    for (int i = v.size() - 1; i >= 1; i--) {
        uniform_int_distribution<int> distribution(0, i);
        int j = distribution(generator);
        swap(v.at(i), v.at(j));
    }
    for (int i = 0; i < v.size(); ++i) {
        if (i != v.size() - 1) {
            cout << v.at(i) << "-";
        } else {
            cout << v.at(i) << endl;;
        }
    }
}
