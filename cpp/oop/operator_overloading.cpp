#include <iostream>

class Complex{
private:
	double real_, imag_;
public:
	Complex(double real, double imag) : real_(real), imag_(imag) {};
	Complex operator+(const Complex rhs);

	double getReal() { return real_;}
	double getImag() { return imag_;}
};

Complex Complex::operator+(const Complex rhs) {
	return Complex(real_ + rhs.real_, imag_ + rhs.imag_);
}

int main() {
	Complex a(1,3);
	Complex b(2,4);
	std::cout << "Real: " << (a+b).getReal() << std::endl;
	std::cout << "Imag: " << (a+b).getImag() << std::endl;
}

