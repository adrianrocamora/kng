#include <iostream>

class Animal {
public:
    //void eat() { std::cout << "I'm eating generic food" << std::endl; }
    virtual void eat() { std::cout << "I'm eating generic food" << std::endl; }
};
class Cat : public Animal {
public:
    void eat() { std::cout << "I'm eating a rat" << std::endl; }
};
void func(Animal* a) { a->eat(); }

int main() {
    Animal *animal = new Animal;
    Cat *cat = new Cat;
    Animal *animalCat = static_cast<Animal*>(cat);
    animal->eat(); 
    cat->eat();
    animalCat->eat();
    func(animal);
    func(cat);
    func(animalCat);
    delete animal;
    delete cat;
}

