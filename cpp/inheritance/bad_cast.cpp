#include <iostream>
#include <stdexcept>

using namespace std;

class Base {
public:
	virtual ~Base() {}
};

class Derived : public Base {
};

int main() {
	Base b;
	Derived d;
	Base& br1 = d;
	cout << typeid(b).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(br1).name() << endl;
	try {
		Derived& dr1 = dynamic_cast<Derived&>(b);
	} catch (const std::exception& e) {
		cout << "Caught a: " << e.what() << endl;
	}
}
