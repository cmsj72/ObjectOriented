#include<iostream>
#include<string>
using namespace std;

#pragma region �ߺ� ���ǿ� �������� ����
//	�ߺ� ����	: ���� �̸��� ��� �Լ��� ���� �� �����ϴ� ��
//	������	: �θ� Ŭ������ �ִ� ��� ���� ��� �Լ��� �ٽ� �����ؼ� ������ �����ϴ� ��
#pragma endregion

#pragma region �����ǵ� ��� �Լ��� ȣ�� ����
class Animal {
public:
	void sleep() {}
	void eat() {}
	void move() {}
	void sound() {}
};
class Bird : public Animal {
public:
	void sound() {}
};
class Eagle : public Bird {
public:
	void move() {}
	void eat() {}
};
#pragma endregion

#pragma region �θ� Ŭ������ ��� �Լ� ȣ��
class ParentClass {
public:
	void print() {
		cout << "�θ� Ŭ������ print() ��� �Լ�" << endl;
	}		
};
class ChildClass : public ParentClass {
	int data;
public:
	void print() {
		ParentClass::print();// �θ� Ŭ������ �Լ� ȣ��
		cout << "�ڽ� Ŭ������ print() ��� �Լ�" << endl;
	}
};
#pragma endregion

#pragma region ��� ���� ������
class Car {
public:
	int speed, gear;
	string color;
	Car() : speed(0), gear(10), color("white") {}
	void setSpeed(int s) { speed = s; }
	int getSpeed() { return speed; }
};
class SportsCar : public Car {
public:
	int speed, gear;
	string color;
	SportsCar() : speed(100), gear(3), color("blue") {}
};
#pragma endregion


int main() {
#pragma region �����ǵ� ��� �Լ��� ȣ�� ����
	Eagle e;
	e.sleep();
	e.eat();
	e.sound();
#pragma endregion

#pragma region �θ� Ŭ������ ��� �Լ� ȣ��
	ChildClass obj;
	obj.print();
	return 0;
#pragma endregion

#pragma region ��� ���� ������
	SportsCar sc;
	cout << "���ǵ�: " << sc.speed << endl;		//	�ڽ� Ŭ������ speed
	cout << "���ǵ�: " << sc.Car::speed << endl;	//	�θ� Ŭ������ speed
	cout << "���ǵ�: " << sc.getSpeed() << endl;	//	�θ� Ŭ������ speed ��ȯ
	//	SportsCar�� ���� speed�� �θ� Ŭ���� Car�� ���� speed�� ������ �ȴ�.
	//	Car�� ��� �Լ��� Car�ȿ� ���ǵ� speed�� ����ϰ� 
	//	SportsCar�� �Լ����� SportsCar �ȿ� ���ǵ� speed�� ����ϰ� �Ǵ� ��
	//	��, � ��� �Լ��� ����ϴ��Ŀ� ���� ���� �ٸ� speed�� ���� �� �ִ�.
	//	��������� ��� ������ �������ϴ� ���� ���� ���ؾ� �Ѵ�.
#pragma endregion

	return 0;
}