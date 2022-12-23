#include<iostream>
using namespace std;

class Animal {
public:
	virtual void speak() { cout << "Animal speak()" << endl; }
};

class Dog :public Animal {
public:
	void speak() { cout << "멍멍" << endl; }
};

class Cat : public Animal {
public:
	void speak() { cout << "야옹" << endl; }
};

int main() {
	//	참조자도 포인터와 마찬가지로 모든 것이 동일하게 적용된다.
	//	부모 클래스의 참조자로 자식 클래스를 가리킬 수 있으며 가상 함수의 동작도 동일
	Dog d;
	Animal& a1 = d;
	a1.speak();

	Cat c;
	Animal& a2 = c;
	a2.speak();
	return 0;
}