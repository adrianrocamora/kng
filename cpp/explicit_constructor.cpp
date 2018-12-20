#include <iostream>

class Complex {
private:
	double real_;
	double imag_;
public:
	explicit Complex(double real = 0.0, double imag = 0.0) : real_(real), imag_(imag) {}
	bool operator== (Complex rhs) {
		return (real_ == rhs.real_ && imag_ == rhs.imag_) ? true : false;
	}
};

int main() {
	Complex com1(3.0, 0.0);
	if (com1 == 3.0) {
		std::cout << "Same" << std::endl;
	} else { 
		std::cout << "Different" << std::endl;
	}
}
