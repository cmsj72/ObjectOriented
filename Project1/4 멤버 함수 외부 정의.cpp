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

//	���� ���ǿ� �ܺ����� ����
//	Ŭ���� ���ο� ���� �Ǹ� �ڵ������� �ζ���(inline) �Լ��� �ȴ�. ���� ��� �Լ� ȣ���� ��� �Լ��� �ڵ�� ��ġ�ȴ�.
//	Ŭ���� �ܺο� ���ǵǸ� �Ϲ����� �Լ��� �����ϰ� ȣ��ȴ�. ���ÿ� �μ����� �����ϰ� ���� �ּҸ� ������ �Ŀ�
//	��� �Լ��� ��� �̵��Ѵ�.
#pragma region ��� �Լ��� �ܺ� ����
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

	cout << "���� �ӵ�: " << myCar.getSpeed() << endl;
	cout << "���� ���: " << myCar.getGear() << endl;
	cout << "���� ����: " << myCar.getColor() << endl;

	Car2 myCar2;

	myCar2.setSpeed(80);
	cout << "���� ���� �ӵ�: " << myCar2.getSpeed() << endl;

	return 0;
}