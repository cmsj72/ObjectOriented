#include<iostream>
#include<string>
using namespace std;

//	�����Ҵ� �����Ҵ� ���� ���� ����Ʈ
//	https://colinch4.github.io/2020-01-12/allocation/
class Car {
	int speed;
	int gear;
	string color;
public:
	Car(int s = 0, int g = 1, string c = "white") : speed(s), gear(g), color(c) {

	}

	void print() {
		cout << "�ӵ�: " << speed << " ���: " << gear << " ����: " << color << endl;
	}
};

int main() {
	//	���� �޸� �Ҵ����� ��ü ����
	//	������ �Լ�, �迭 ���� ���������ν� �޸𸮿� �Ҵ��� ��, �޸𸮿��� �� ũ�⸦ �˷��־�
	//	�޸� ������ �ʿ䷮�� �˷���
	Car myCar;
	myCar.print();

	//	���� �޸� �Ҵ����� ��ü ����
	//	���α׷��� ���� ���߿� �������� �޸𸮸� �Ҵ� �޴� ��
	//	�� �� �޸𸮴� �� �ݳ�(����)�ؾ���, �޸� ������ �߻��ϱ� ����
	Car* pCar = new Car(0, 1, "blue");
	pCar->print();
	return 0;
}