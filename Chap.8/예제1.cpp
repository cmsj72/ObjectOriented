#include<iostream>
using namespace std;
enum BREED { YORKIE, POODLE, BULLDOG };

class Animal {
protected:
	int age;
	int weight;
public:
	Animal();
	~Animal();

	void speak() const;
	void sleep() const;
	void eat() const;
};
Animal::Animal() {
	cout << "Animal ������\n" << endl;
}
Animal::~Animal() {
	cout << "Animal �Ҹ���\n" << endl;
}
void Animal::speak() const{
	cout << "Animal speak()\n" << endl;
}
void Animal::sleep() const {
	cout << "Animal sleep()\n" << endl;
}
void Animal::eat() const {
	cout << "Animal eat()\n" << endl;
}

class Dog :public Animal {
private:
	BREED breed;
public:
	Dog();
	~Dog();

	void wag();
	void bite();
	void speak() const;
};

Dog::Dog() {
	cout << "Dog ������\n";
}
Dog::~Dog() {
	cout << "Dog �Ҹ���\n";
}
void Dog::wag() {
	cout << "Dog wag()\n";
}
void Dog::bite() {
	cout << "Dog bite()\n";
}
void Dog::speak() const {
	cout << "Dog speak()\n";
}

int main() {
	Dog dog;
	dog.eat();
	dog.sleep();
	dog.speak();
	dog.wag();

	return 0;
}
