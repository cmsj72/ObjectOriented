#include<iostream>
#include<string>
using namespace std;

class Car {
public:
	int speed;
	int gear;
	string color;

	//	��� �Լ��� �̸��� ���� ���ʴ� �밳 �ҹ��ڷ� ���۵Ǵ� ���簡 ���� �� ���� ��糪 ����簡 ���� ��.
	//	���� ���, setBackground(), isEmpty(), getData(), isActive() ��
	void speedUp() {
		speed += 10;
	}

	void speedDown() {
		speed -= 10;
	}

	void show() {
		cout << "================" << endl;
		cout << "�ӵ�: " << speed << endl;
		cout << "���: " << gear << endl;
		cout << "����: " << color << endl;
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