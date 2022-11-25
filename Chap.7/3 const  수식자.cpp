#include<iostream>
#include<string>
using namespace std;

class Car {
	//	���� ������ ���� ������� const�� �̿��Ͽ� ����� ����� ���� �ٶ����ϴ�.
	//	���� ��� �ڵ����� �ø��� ��ȣ�� �ڵ��� �����ÿ� �����ǰ� ���� ������� �����Ƿ� ������ �����ϴ� ���� ����.
	const int serial;
	int speed;
	int gear;
	string color;
public:
	Car(int ser, int s = 0, int g= 1, string c = "white") : serial(ser), speed(s), gear(s), color(c){}
	int getSpeed() {
		return speed;
	}
	int setSpeed(int speed) {
		this->speed = speed;
	}

	//	��� �Լ��� const�� ���̸� �� �Լ��� ���Ͽ� ��� ������ ������ �� ���ٴ� �ǹ�
	//	const�� �ٴ� �Լ��� ��� ��� �Լ��� �θ���.
	//	��� ��� �Լ� �ȿ��� ���ȭ���� ���� �Լ��� ȣ���ϸ� ������ �߻�
	void displaySpeed() const {
		cout << "�ڵ����� �ӵ�: " << speed << endl;
		//int tmp = getSpeed(); <- ���� �߻�
	}

	
};

//	�Լ��� �Ű� ���� ���𿡼� ��ü �����ڿ� const�� ���̴� ��찡 ����.
//	�����ڿ� const�� ������ �� �����ڸ� ���ؼ� ��� ������ ���� ������ �� ������, ���ȭ���� ���� �Լ��� ȣ���� �� ����.
void sub(Car& c, const Car& cc) {
	int s1 = c.getSpeed();
	c.setSpeed(100);

	//int s2 = cc.getSpeed();	���� getSpeed()�� ��� ��� �Լ��� ���ǰ� �Ǿ��ְ� setSpeed()�� �Ǿ����� ������ 
	//cc.setSpeed(200);			getSpeed()�� ȣ�� ����
}

int main() {
	Car c1(1, 0, 1, "white");
	Car c2(2, 0, 1, "red");
	Car c3(3, 0, 1, "blue");
	Car c4(4);

	//	��ü�� const�� �ٴ´ٸ� �� ��ü�� ���ؼ��� ��� ������ ���� ������ �� ����.
	//	��� �Լ��� ��쿡�� ��� ��� �Լ��� �ƴϸ� ȣ���� �� ����.
	const Car c5(5, 0, 1, "yellow");
	//int s = c5.setSpeed(5); ���� �߻�, �ڵ��ϼ� �ܰ迡�� ǥ�õ��� ����

	return 0;
}