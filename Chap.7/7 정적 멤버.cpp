#include<iostream>
using namespace std;

//	�ڽ��� ī��Ʈ ������ �����ϰ� �ٸ� ��ü�� ī���� �����鿡�� ����X
//class Car {
//	int count;
//public:
//	Car() {
//		count++;
//	}
//};

//	���� ������ ��ü ������ ������ ����
//int count;
//class Car {
//public:
//	Car() {
//		count++;
//	}
//};

//	���� ����(static variable) : static�� �ٿ��� �����ϴ� ����, Ŭ�������� �ϳ��� ����
//	��, Ŭ������ ��� ��ü�� �ϳ��� ������ �����ϴ� ��
//	ī���� ������ ���� ������ �����ϰ� ������ �ȿ��� ������Ű�� ���ݱ��� ����� �ڵ��� ��ü�� ������ �� �� �ִ�.
//	���� ������ Ŭ���� ������� �Ѵ�.
class Car {
	int speed;
	int gear;
	string color;
	static int count;
public:
	Car(int s = 0, int g = 1, string c = "white") : speed(s), gear(s), color(c) {
		//count = 0;	// �߸��� �ʱ�ȭ
		count++;
	}
	void print() {
		cout << "�ӵ�: " << speed << " ���: " << gear << " ����: " << color << endl;
	}
	~Car() {
		count--;
	}
};

//	���� ������ �ʱ�ȭ�� ���� ������ ����ϰ� Ŭ���� �ܺο��� ����
int Car::count = 0;

int main() {
	Car c1;
	Car c2;
}