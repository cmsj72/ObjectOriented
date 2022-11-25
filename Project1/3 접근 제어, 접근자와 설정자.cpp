#include<iostream>
#include<string>
using namespace std;

//	��� ���� �ÿ� �ƹ��͵� ������ ������ default�� ��� ����� private�� �ȴ�.
//	��� ��� ������ �ܺο� �����ϴ� ���� ���� ������ ���信 ����Ǵ� ��,
//	�� ���� ����� Ư���� ��� �Լ��� ����Ͽ� ��� ������ ���� �аų� �����ϴ� ��.
class Employee {
private:
	string name;
	int salary;
	int age;
	int getSalary() { return salary; }

public:
	int getAge() { return age; }
	string getName() { return name; }
};
//	�������
//	�Ϲ������� ����� ���ؼ��� ���� ������ ���� ��� ����. ���� Ư���� ������ ������ private�� ����
//	����� �����ϰ�� ��� ������ public�� ����ϸ� �ȵȴ�. �ܺ� Ŭ�������� public ��� ������ ����ϸ� �ڵ带 �����ϱ� ���������.


//	�����ڿ� �����ڸ� ����ϴ� ����
//	1.���� ����, Ŭ������ �������̽��� ������ �и��Ǹ� ������ �����ϱ� ��������.
//	2.�����ڿ��� �Ű� ������ ���Ͽ� �߸��� ���� �Ѿ���� ���, �̸� ������ ������ �� �ִ�.
//	3.��� �������� �ʿ��� ������ ����Ͽ� ��ȯ�� �� �ִ�.
//	4.�����ڸ��� �����ϸ� �ڵ������� �б⸸ ������ ��� ������ ���� �� �ִ�.
//	  ���� �����ڴ� ��ȯ�ϴ� �������� ������ ������ �� �ֱ� ������, �ܺ� �ڵ尡 ���� ������ ǥ�� ����� �𸣰� �� �� �ִ�.
class Car {
private:
	int speed;
	int gear;
	string color;

public:	
	int getSpeed() {//������
		return speed;
	}
		
	void setSpeed(int s) {//������
		speed = s;
	}

	int getGear() {
		return gear;
	}

	void setGear(int g) {
		gear = g;
	}

	string getColor() {
		return color;
	}

	void setColor(string c) {
		color = c;
	}
};

int main() {
	Employee e;
	//	private�̱� ������ ���� �Ұ���
	e.salary = 300;
	e.age = 26;
	int sa = e.getSalary();

	string s = e.getName();
	int a = e.getAge();

	Car myCar;

	myCar.setSpeed(100);
	myCar.setGear(3);
	myCar.setColor("red");

	cout << "���� �ӵ�: " << myCar.getSpeed() << endl;
	cout << "���� ���: " << myCar.getGear() << endl;
	cout << "���� ����: " << myCar.getColor() << endl;
	return 0;
}