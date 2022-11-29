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

//	매개변수 c1과 c2는 red와 blue의 내용을 복사한 별개의 객체이기 때문에 
//	swapObjects에서 내용이 교환되어도 red와 blue에는 변화가 없다
void swapObjects(Car c1, Car c2) {
	Car tmp;
	tmp = c1; c1 = c2; c2 = tmp;
}

//	변수의 주소를 추출하여 매개 변수로 전달하여
//	포인터가 전달되는 경우에는 객체의 내용이 교환
void swapObjects(Car* p1, Car* p2) {
	Car tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//	참조자 : 변수에다가 하나의 이름을 더 주는 것
//	참조자를 통하여 변수의 값을 변경하면 원본 변수를 변경하는 것과 마찬가지(객체도 마찬가지)
//	객체를 값으로 전달하는 것 보다 객체의 참조자를 전달하는 편이 더 효율적
//	→ 객체의 크기가 큰 경우에 객체를 복사하는 시간이 많이 걸리기 때문
void swapObjects2(Car& r1, Car& r2) {
	Car tmp;
	tmp = r1; r1 = r2; r2 = tmp;
}

//	함수안에서 정의된 tmp의 내용이 복사되는 것이다.
Car createCar() {
	Car tmp(0, 1, "metal");
	return tmp;
}

int main() {
	Car red(0, 1, "red");
	Car blue(30, 2, "blue");

	Car metal = createCar();
	Car wood(10, 1, "wood");
	swapObjects(red, blue);
	red.print();
	blue.print();
	swapObjects(&red, &blue);
	swapObjects(metal, wood);

	metal.print();
	wood.print();
	return 0;
}