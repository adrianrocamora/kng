#include <iostream>
#include <vector>
using namespace std;

int main() {
	std::vector<int> v{2,4,6,8,10};
	for (auto x : v) {
		cout << x << " ";
	}
 	cout << endl;
	{ 
		auto&& r = (v);
		for (auto b = begin(r), e = end(v); b != e; ++b) {
			auto x = *b;
			cout << x << " ";
		}
	}
 	cout << endl;
}
