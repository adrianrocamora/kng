#include <iostream>

class Animal {
public:
    virtual void eat() {std::cout << "Nom Nom!" << std::endl;};
};

class Mammal : public virtual Animal {
public:
    virtual void breathe() {std::cout << "Huff puff" << std::endl;};
};

class WingedAnimal : public virtual Animal {
public:
    virtual void flap() {std::cout << "Flap flap" << std::endl;};
};
// A bat is a winged mammal
class Bat : public Mammal, public WingedAnimal {
};

int main() {
    Bat bat;
    bat.eat();          
}
