#include <iostream>

class Animal {
public:
    virtual void eat() {std::cout << "Nom Nom!" << std::endl;};
};

class Mammal : public Animal {
public:
    virtual void breathe() {std::cout << "Huff puff" << std::endl;};
};

class WingedAnimal : public Animal {
public:
    virtual void flap() {std::cout << "Flap flap" << std::endl;};
};
// A bat is a winged mammal
class Bat : public Mammal, public WingedAnimal {
};

int main() {
    Bat bat;
    //bat.eat();          // Compile error! This is ambiguous
	static_cast<Mammal&>(bat).eat();
	Mammal &m = static_cast<Mammal&>(bat);
	m.eat();
	m.breathe();
	Animal &a = static_cast<Mammal&>(bat);
	a.eat();
	//a.breathe();		// Error
	bat.Mammal::eat();

}
