#include<iostream>
#include<string>
using namespace std;

//	https://colinch4.github.io/2020-01-12/allocation/
class Car {
	int speed;
	int gear;
	string color;
public:
	Car(int s = 0, int g = 1, string c = "white") : speed(s), gear(g), color(c) {

	}

	void print() {
		cout << "속도: " << speed << " 기어: " << gear << " 색상: " << color << endl;
	}
};

int main() {
	//	정적 메모리 할당으로 객체 생성
	Car myCar;
	myCar.print();

	//	동적 메모리 할당으로 객체 생성
	Car* pCar = new Car(0, 1, "blue");
	pCar->print();
	return 0;
}