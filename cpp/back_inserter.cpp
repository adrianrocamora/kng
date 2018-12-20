#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	vector<int> a{1,2,3,4,5,    8};
	vector<int> b{  2  ,4,5,6,7};
	vector<int> res;
	//set_intersection(
	//set_difference(
	set_symmetric_difference(
			a.begin(), a.end(), 
			b.begin(), b.end(), 
			back_inserter(res));
	for (auto x : a) { cout << x << " ";} cout << endl;
	for (auto x : b) { cout << x << " ";} cout << endl;
	for (auto x : res) { cout << x << " ";} cout << endl;
}
