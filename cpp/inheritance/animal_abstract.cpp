#include <iostream>
using namespace std;

class Animal {
public:
	virtual void makeSound() { cout << "The Animal says grrr" << endl;}
};

class Cat : public Animal { 
public:
	void makeSound() { cout << "The cat says meow" << endl;}
};

class Dog : public Animal {
public:
	void makeSound() { cout << "The dog says woof" << endl;}
};

class Car { 
public:
	virtual int getNumWheels() = 0;
	virtual int getNumDoors() = 0;
};

class StationWagon : public Car {
public:
	int getNumWheels() { cout << "Station Wagon has 4 wheels" << endl;}
	int getNumDoors() { cout << "Station Wagon has 4 doors" << endl;}
	StationWagon() {}
	~StationWagon();
};

int main() {
	Car *stationWagon = new StationWagon();
	stationWagon->getNumWheels();
	
	return 0;
}
