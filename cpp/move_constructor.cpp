#include <algorithm>

class X {
private:
	int* data;
public:
	X() : data(new int[1'000'000]) {}
	~X() { delete[] data;}
	X(const X& other) : data(new int[1'000'000]) {
		std::copy(other.data, other.data + 1'000'000, data);
	}
	X(X&& other) : data(other.data) {
		other.data = nullptr;
	}
};

int main() {
}
