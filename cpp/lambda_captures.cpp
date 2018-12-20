#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
    int divisor = 3;
    vector<int> numbers { 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
    //for_each(numbers.begin(), numbers.end(), [divisor] (int y) {
    //for_each(numbers.begin(), numbers.end(), [&] (int y) {
    for_each(numbers.begin(), numbers.end(), [=] (int y) {
        if (y % divisor == 0) {
            cout << y << endl;
        }
    });
    for_each(numbers.begin(), numbers.end(), [&] (int y) {
		divisor = 12;
        if (y % divisor == 0) {
            cout << y << endl;
        }
    });
}

