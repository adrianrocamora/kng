#include <random>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	vector<int> v{1,2,3,4,5,6,7,8,9,10};
	random_device rd;
	mt19937 g(rd());
	shuffle(v.begin(), v.end(), g);
	cout << accumulate(v.begin(), v.end(), string{}, [] (const string& a, int b) {
				return a.empty() ? to_string(b) : (a + ", " + to_string(b));
				}) << endl;
}

