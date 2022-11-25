#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;


class Car {
	int speed;
	int gear;
	string color;

public:
	Car(int s, int g, string c) : speed(s), gear(g), color(c) {
		cout << "������ ȣ��" << endl;
	}

	Car(const Car& obj) : speed(obj.speed), gear(obj.gear), color(obj.color) {
		cout << "���� ������ ȣ��" << endl;
	}

	void print() {
		cout << "==========" << endl;
		cout << "�ӵ�: " << speed << endl;
		cout << "���: " << gear << endl;
		cout << "����: " << color << endl;
	}

	int getSpeed() { return speed; }
	int getGear() { return gear; }
	string getColor() { return color; }
};

//	���� �����ڸ� ��������� �������� �ʾƵ� ����Ʈ ���� �����ڰ� �ڵ����� �����ȴ�.
//	����Ʈ ���� �����ڴ� ��ü�� ������ �ִ� ������ ���� �����Ѵ�.
class Car2 {
	int speed;
	int gear;
	string color;

public:
	Car2(int s, int g, string c) : speed(s), gear(g), color(c) {
		cout << "������ ȣ��" << endl;
	}

	void print() {
		cout << "==========" << endl;cout << "�ӵ�: " << speed << endl;cout << "���: " << gear << endl;cout << "����: " << color << endl;
	}
};

//	
class Student {
	char* name;
	int number;
public:
	Student(char* p, int n) {
		cout << "�޸� �Ҵ�" << endl;
		name = new char[strlen(p) + 1];
		strcpy(name, p);
		number = n;
	}
	~Student() {
		cout << "�޸� �Ҹ�" << endl;
		delete[] name;
	}
};

void isMoving(Car obj) {
	if (obj.getSpeed() > 0) cout << "�����̰� �ֽ��ϴ�" << endl;
	else cout << "������ �ֽ��ϴ�" << endl;
}

Car createCar() {
	Car obj(0, 1, "white");
	return obj;
}

int main() {
	Car c1(0, 1, "yellow");
	Car c2(c1);
	//	Car c2 = c1;// ������ ���� c2�� �����Ͽ��� ���� �����ڰ� ȣ��ȴ�.
	c1.print();
	c2.print();

	Car2 c3(40, 100, "red");
	Car2 c4(c3);
	c3.print();
	c4.print();

	//	���� �߻� ���� : ����Ʈ ���� �����ڿ��� �ܼ��� �� ��ü�� ����� ���� �ٸ� ��ü�� ����� �����߱� ����
	//	name�̶�� ������ �ȿ� ����ִ� �ּҰ��� ���簡 �Ǿ��� ����, s2�� ���� ���ο� ������ �Ҵ���� �ʾҰ�
	//	������ ������ s1�� s2�� �����ϴ� ��Ȳ(���� ����, shallow copy)
	//	���� ������ s1�� �Ҹ�Ǹ鼭 �̸��� ������ �޸� ������ �ݳ��ϰԵǰ� �� ������ ������ �ٸ� ���� ���� s2��
	//	�Ҹ�� �� �ٽ� �ݳ��Ϸ��� �ϱ� ����
	//	�ذ� ��� : ��j�� �����ڸ� ������� �ʰ� ���� ���� �����ڸ� ����(���� ����, deep copy)
	char tmp[5] = "Park";
	Student s1(tmp, 201000001);
	Student s2(s1);

	//	isMoving �Լ����� ��ü�� �޾� ��ü�� ������ ���, isMoving�� ȣ��Ǹ鼭 ���� �����ڰ� ȣ��Ǹ鼭
	//	������ s1 ��ü�� �Ӽ��� obj�� ��� ���簡 �Ǵ� ��
	//	���� ������ ���� �Լ��� ��ȯ������ ��ü�� ��ȯ�Ͽ��ٸ� �� ���������� ���� �����ڰ� ȣ��ȴ�.
	isMoving(c1);

	Car newCar = createCar();
	newCar.print();

	return 0;
}

