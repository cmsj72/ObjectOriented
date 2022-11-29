#include<iostream>
#include<string>
using namespace std;

class Car {
	int speed;
	int gear;
	string color;
public:
	Car(int s = 0, int g = 1, string c = "white") : speed(s), gear(s), color(c) {}
	void print() {
		cout << "�ӵ�: " << speed << " ���: " << gear << " ����: " << color << endl;
	}
};

//	�Ű����� c1�� c2�� red�� blue�� ������ ������ ������ ��ü�̱� ������ 
//	swapObjects���� ������ ��ȯ�Ǿ red�� blue���� ��ȭ�� ����
void swapObjects(Car c1, Car c2) {
	Car tmp;
	tmp = c1; c1 = c2; c2 = tmp;
}

//	������ �ּҸ� �����Ͽ� �Ű� ������ �����Ͽ�
//	�����Ͱ� ���޵Ǵ� ��쿡�� ��ü�� ������ ��ȯ
void swapObjects(Car* p1, Car* p2) {
	Car tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//	������ : �������ٰ� �ϳ��� �̸��� �� �ִ� ��
//	�����ڸ� ���Ͽ� ������ ���� �����ϸ� ���� ������ �����ϴ� �Ͱ� ��������(��ü�� ��������)
//	��ü�� ������ �����ϴ� �� ���� ��ü�� �����ڸ� �����ϴ� ���� �� ȿ����
//	�� ��ü�� ũ�Ⱑ ū ��쿡 ��ü�� �����ϴ� �ð��� ���� �ɸ��� ����
void swapObjects2(Car& r1, Car& r2) {
	Car tmp;
	tmp = r1; r1 = r2; r2 = tmp;
}

//	�Լ��ȿ��� ���ǵ� tmp�� ������ ����Ǵ� ���̴�.
Car createCar() {
	Car tmp(0, 1, "metal");
	return tmp;
}

int main() {
	Car red(0, 1, "red");
	Car blue(30, 2, "blue");

	Car metal = createCar();
	Car wood(10, 1, "wood");
	swapObjects(red, blue);
	red.print();
	blue.print();
	swapObjects(&red, &blue);
	swapObjects(metal, wood);

	metal.print();
	wood.print();
	return 0;
}