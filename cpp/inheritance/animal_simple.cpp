#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
	int height;
	int weight;
	string name;
	static int numOfAnimals;
public:
	Animal();
	Animal(int height, int weight, string name){
		this->height = height;
		this->weight = weight;
		this->name = name;
		numOfAnimals++;
	}
	void toString();
	static int getNumOfAnimals();

	void setHeight(int height) { this->height = height;}
	void setWeight(int weight) { this->weight = weight;}
	void setName(string name) { this->name = name;}
	int getHeight() { return height;}
	int getWeight() { return weight;}
	string getName() { return name;}

};
int Animal::numOfAnimals = 0;
Animal::Animal() {
	numOfAnimals++;
}
void Animal::toString() {
	cout << this->name << " is " << this->height << " cms tall and " << this-> weight << " kgs in weight" << endl;
}

int Animal::getNumOfAnimals()
{
	return numOfAnimals;
}


class Dog : public Animal{
private:
	string sound = "Woof!";
public:
	void getSound() { std::cout << sound << std::endl;}
	Dog(int, int, string, string);
	// Declare the default constructor and call the default superclass constructor
	Dog() : Animal() {};
	void toString();
};
// The Dog constructor passes the right attributes to the superclass constructor
// and then handles the attribute bark that remains
Dog::Dog(int height, int weight, string name, string bark) :
	Animal(height, weight, name)
{
	this->sound = bark;
}
void Dog::toString()
{
	// Because the attributes were private in Animal, they must be retrieved
	// by calling the get methods
	cout << this->getName() << " is " << this->getHeight() << 
		" cms tall and " << this->getWeight() << " kgs in weight and says " <<
		this->sound << endl;
}
int main() {
	Animal fred;
	fred.setHeight(33);
	fred.setWeight(10);
	fred.setName("Fred");

	Dog spot(38, 16, "Spot", "Woof");

	cout << "Number of Animals " << Animal::getNumOfAnimals() << endl;
	spot.getSound();

	return 0;
}
