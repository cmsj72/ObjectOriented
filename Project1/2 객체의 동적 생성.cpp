#include<iostream>
#include<string>
using namespace std;

class Car {
public:
	int speed;
	int gear;
	string color;

	void speedUp() {
		speed += 10;
	}

	void speedDown() {
		speed -= 10;
	}

	void show() {
		cout << "================" << endl;
		cout << "속도: " << speed << endl;
		cout << "기어: " << gear << endl;
		cout << "색상: " << color << endl;
		cout << "================" << endl;
	}
};

int main() {
	//	객체 동적 생성
	Car* dynCar = new Car;
	dynCar->speed = 100;
	dynCar->gear = 2;
	dynCar->color = "green";
	dynCar->speedUp();
	dynCar->show();

	//	객체 동적 삭제
	delete dynCar;

	return 0;
}