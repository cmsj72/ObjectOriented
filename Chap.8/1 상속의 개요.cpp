#include<iostream>
#include<string>
using namespace std;

//	���(inheritance)
//	������ �����ϴ� ������ Ŭ�����κ��� �Ӽ��� ������ �̾�ް�
//	�ڽſ��� �ʿ��� ����� �߰��ϴ� ���
//	�θ� Ŭ���� == ���� Ŭ���� == ���̽� Ŭ����
//	�ڽ� Ŭ���� == ���� Ŭ���� == �Ļ��� Ŭ����

//	����� is-a ����
//	ex)
//	�ڵ����� Ż���̴�.(Car is a Vehicle)
//	����,��,����̴� �����̴�.
//	���� "~�� ~�� ������ �ִ�"�� ���� has-a(����) ���谡 �����Ǹ� �� ����� ������� �𵨸��ϸ� �� �ȴ�.
//	ex)
//	�������� å�� ������ �ִ�(Library has a book)
//	�Ž��� ���ĸ� ������ �ִ�.
class Car {
public:
	int speed;
	int gear;
	string color;

	void setGear(int newGear) {
		gear = newGear;
	}
	void speedUp(int increament) {
		speed += increament;
	}
	void speedDown(int decrement) {
		speed -= decrement;
	}
};

class SportsCar : public Car {
	bool turbo;
public:
	void setTurbo(bool newValue) {
		turbo = newValue;
	}
};

int main() {
	SportsCar c;
	c.color = "Red";
	c.setGear(3);
	c.speedUp(100);
	c.speedDown(30);
	c.setTurbo(true);
	return 0;
}