#include <iostream>

class Complex {
public:
	Complex(double real, double imag) : real_(real), imag_(imag) {}
	Complex operator+(const Complex other);
	double getReal() { return real_;}
	double getImag() { return imag_;}
private:
	double real_;
	double imag_;
};
Complex Complex::operator+(const Complex other){
	double res_real = real_ + other.real_;
	double res_imag = imag_ + other.imag_;
	return Complex(res_real, res_imag);
}
int main(){
	Complex a(1,2);
	Complex b(11,22);
	Complex c = a + b;
	std::cout << c.getReal() << " " << c.getImag() << std::endl;
}
