#include<iostream>
#include<string>
using namespace std;

class Car {
public:
	int speed;
	int gear;
	string color;

	//	멤버 함수의 이름을 짓는 관례는 대개 소문자로 시작되는 동사가 먼저 온 다음 명사나 형용사가 오는 것.
	//	예를 들어, setBackground(), isEmpty(), getData(), isActive() 등
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
	Car myCar, yourCar;

	myCar.speed = 100;
	myCar.gear = 3;
	myCar.color = "red";

	yourCar.speed = 10;
	yourCar.gear = 1;
	yourCar.color = "blue";

	myCar.speedUp();
	yourCar.speedUp();

	myCar.show();
	yourCar.show();

	return 0;
}