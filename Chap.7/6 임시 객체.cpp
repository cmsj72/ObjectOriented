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

Car createCar() {
	Car tmp(0, 1, "metal");
	return tmp;
}

int main() {
	string s1 = "Hello";
	string s2 = "World";
	const char* p = (s1 + s2).c_str();//	(1). (s1 + s2)���� �ӽ� ��ü�� �����ȴ�.

	//	(s1 + s2)�� s1 �� s2�� ���� ���ڿ� ��ü(�ӽ� ��ü)�� �����ǰ�
	//	c_str()�� �� �ӽ� ��ü�� ������ �ִ� ���� �迭�� �ּҸ� ��ȯ�Ѵ�
	//	������ �ӽ� ��ü�� (1)�� ������ ������ �Ҹ�Ǳ� ������ p�� ������ �־��� �ּҴ� �߸��� �ּҰ� �ȴ�.
	//	�ذ� ����� �������� ��ü�� �ϳ� �� ����� ��
	string s3 = s1 + s2;
	const char* p = s3.c_str();
	cout << p;

	//	�Լ��� ��ü�� ��ȯ�ϸ� �ӽ� ��ü�� ����
	//	createCar()�� ��ȯ�ϴ� tmp�� ���� �ӽ� ��ü�� ����Ǵ� ��
	createCar().print();

	//	�ӽ� ��ü�� ��������� �������ɡ�����ڸ� ��������� ȣ��

	Car(0, 1, "gray");
	//	�� ������ �ӽ� ��ü�� ���������� ��򰡿� �������� �ʱ� ������ 
	//	�ӽ� ��ü�� ��������� ���� �������� �Ѿ�鼭 �ٷ� �Ҹ�

	const Car& r = Car(0, 1, "gray");
	//	å���� const�� ���µ� ���� ���°� ���� �ֱ��� const�� �ٿ��� �ϴµ�
	//	Car(0, 1, "gray")�� ������ ������ ����� �ӽð�ü(rvalue)�̱� ������
	//	const�� �־�� �ҵ�(const�� ���� ���� �������� �ʱⰪ�� lvalue�� �޾ƾ���)
	
	Car c = Car(0, 1, "gray");
	return 0;
}