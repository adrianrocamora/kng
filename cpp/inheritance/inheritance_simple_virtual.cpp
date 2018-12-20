#include <iostream>
using namespace std;

class Base {
public:
    // Without the virtual keyword ~Derived will not be called
    virtual ~Base() {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived()  {
        std::cout << "Derived  destructor" << std::endl;
    }
};

int main() {
    Base *p = new Derived();
    delete p;
}
