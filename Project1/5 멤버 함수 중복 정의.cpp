#include<iostream>
#include<string>
using namespace std;

class Car {
private:
	int speed;
	int gear;
	string color;
public:
	int getSpeed();
	void setSpeed(int s);
	void setSpeed(double s);
};
//	�ߺ� ���ǵ� ��� �Լ��� �Ű� ������ ������ Ÿ�Կ� ���Ͽ� ���� �����ȴ�.
//	but ��ȯ���� ����Ͽ� �������� �ʴ´� �� ��ȯ���� �ٸ��ٰ��ؼ� �ߺ� ������ ���� ����.

void Car::setSpeed(int s) {
	speed = s;
}

void Car::setSpeed(double s) {
	speed = (int)s;
}

int main() {
	Car myCar;

	myCar.setSpeed(80);
	myCar.setSpeed(100.0);

	cout << "���� �ӵ�: " << myCar.getSpeed() << endl;
	return 0;
}
