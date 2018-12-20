#include <iostream>
#include <stack>
#include <utility>
#include <stdexcept>
using namespace std;

template <typename T>
class StackMax {
private:
	stack<pair<T, T>> s_; // Pair of the key, and max_key till then
public:
	bool empty() const { return s_.empty(); }
	//void push(const T& x) {
		//s_.emplace(x, std::max(x, empty() ? x : s_.top().second));
	//}
	void push(const T& x) {
		if (!empty()) {
			T lastMax = s_.top().second;
			if (x < lastMax) {
				s_.emplace(x, lastMax);
			} else if (x == lastMax) {
				s_.emplace(x, lastMax);
			} else {
				s_.emplace(x, x);
			}
		} else {
			s_.emplace(x, x);
		}
	}
	T max() const { 
		if (!empty()) {
			return s_.top().second; 
		}
		throw logic_error("empty stack");
	}
	T pop() {
		if (!empty()) {
			T ret = s_.top().first;
			s_.pop();
			return ret;
		}
		throw logic_error("empty stack");
	}
};

int main() {
	StackMax<int> s;
	//for (int i : {1,2,3,4,5} ) {
		//s.push(i);
	//}
	for (int i : {5,4,3,2,1} ) {
		s.push(i);
	}
	while (!s.empty()) {
		cout << "max = " << s.max() << ", val = " << s.pop() << endl;
	}
}
