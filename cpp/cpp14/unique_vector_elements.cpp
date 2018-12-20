#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	vector<int> v{1,2,3,2,6,3,6,1,3,5,7,4,3,2,9,0,3,2,1,7,6,5,4,3,6,7};
	sort(v.begin(), v.end());
	auto last = unique(v.begin(), v.end());
	v.erase(last, v.end());
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
}
