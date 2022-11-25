#include<iostream>
#include<string>
#include"car2.h"
using namespace std;

class Car {
private:
	int speed;
	int gear;
	string color;
public:
	int getSpeed();
	void setSpeed(int s);
	int getGear();
	void setGear(int g);
	string getColor();
	void setColor(string c);
};

//	내부 정의와 외부정의 차이
//	클래스 내부에 정의 되면 자동적으로 인라인(inline) 함수가 된다. 따라서 멤버 함수 호출이 멤버 함수의 코드로 대치된다.
//	클래스 외부에 정의되면 일반적인 함수와 동일하게 호출된다. 스택에 인수들을 저장하고 복귀 주소를 저장한 후에
//	멤버 함수로 제어가 이동한다.
#pragma region 멤버 함수의 외부 정의
int Car::getSpeed() {
	return speed;
}

void Car::setSpeed(int s) {
	speed = s;
}

int Car::getGear() {
	return gear;
}

void Car::setGear(int g) {
	gear = g;
}

string Car::getColor() {
	return color;
}

void Car::setColor(string c) {
	color = c;
}
#pragma endregion

int main() {
	Car myCar;

	myCar.setSpeed(100);
	myCar.setGear(3);
	myCar.setColor("red");

	cout << "차의 속도: " << myCar.getSpeed() << endl;
	cout << "차의 기어: " << myCar.getGear() << endl;
	cout << "차의 색상: " << myCar.getColor() << endl;

	Car2 myCar2;

	myCar2.setSpeed(80);
	cout << "현재 차의 속도: " << myCar2.getSpeed() << endl;

	return 0;
}