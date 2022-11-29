#include<iostream>
#include<string>
using namespace std;

class Car {
	int speed;
	int gear;
	string color;
public:
	Car(int s = 0, int g = 1, string c = "white") : speed(s), gear(s), color(c) {}
	void print() {
		cout << "속도: " << speed << " 기어: " << gear << " 색상: " << color << endl;
	}
};

Car createCar() {
	Car tmp(0, 1, "metal");
	return tmp;
}

int main() {
	string s1 = "Hello";
	string s2 = "World";
	const char* p = (s1 + s2).c_str();//	(1). (s1 + s2)에서 임시 객체가 생성된다.

	//	(s1 + s2)은 s1 과 s2를 합한 문자열 객체(임시 객체)가 생성되고
	//	c_str()은 이 임시 객체가 가지고 있는 문자 배열의 주소를 반환한다
	//	하지만 임시 객체는 (1)의 문장이 끝나면 소멸되기 때문에 p가 가지고 있었던 주소는 잘못된 주소가 된다.
	//	해결 방법은 정상적인 객체를 하나 더 만드는 것
	string s3 = s1 + s2;
	const char* p = s3.c_str();
	cout << p;

	//	함수가 객체를 반환하면 임시 객체가 생성
	//	createCar()가 반환하는 tmp의 값이 임시 객체에 복사되는 것
	createCar().print();

	//	임시 객체는 명시적으로 생성가능→생성자를 명시적으로 호출

	Car(0, 1, "gray");
	//	위 문장은 임시 객체를 생성하지만 어딘가에 저장하지 않기 때문에 
	//	임시 객체가 만들어지고 다음 문장으로 넘어가면서 바로 소멸

	const Car& r = Car(0, 1, "gray");
	//	책에는 const가 없는데 오류 나는걸 보니 최근은 const를 붙여야 하는듯
	//	Car(0, 1, "gray")는 문장이 끝나면 사라질 임시객체(rvalue)이기 때문에
	//	const가 있어야 할듯(const가 붙지 않은 참조자의 초기값은 lvalue를 받아야함)
	
	Car c = Car(0, 1, "gray");
	return 0;
}