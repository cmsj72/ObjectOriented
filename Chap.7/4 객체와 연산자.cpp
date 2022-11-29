#include<iostream>
#include<string>
using namespace std;

class Car {
	int speed;
	int gear;
	string color;
public:
	Car(int s = 0, int g = 1, string c = "white") : speed(s), gear(s), color(c) {}
};

int main() {
	Car c1(0, 1, "white");
	Car c2(0, 1, "red");
	c1 = c2;
	//	c2�� ��� ������ c1���� ����ȴ�.
	//	��ü���� ���� ����, c2�� ������ �ִ� ��� ��� ������ ���� c1���� ����
	//	���� Ÿ���� ��ü������ ���� ������ ����

	//	CarŬ�������� ==�����ڸ� �������� �ʾұ� ������ ������ ���� �߻�
	//	������ �ߺ�(operator overloading)�� �̿��Ͽ� ������ �� �ִ�(Chap.10)
	if (c1 == c2) {
		cout << "�����ϴ�" << endl;
	}
	else {
		cout << "���� �ʽ��ϴ�" << endl;
	}
	return 0;
}