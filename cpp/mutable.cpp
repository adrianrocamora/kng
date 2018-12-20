#include <iostream>

class Something {
private:
	bool flag_;
	mutable int accessCount_;
public:
	bool getFlag() const{
		accessCount_++;
		return flag_;
	}

};

int main() {
	Something s;
	std::cout << s.getFlag() << std::endl;
}
