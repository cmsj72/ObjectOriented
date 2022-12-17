#include<iostream>
using namespace std;

//	���� ���(multiple inheritance)
//	�ϳ��� �ڽ� Ŭ������ �� �� �̻��� �θ� Ŭ�����κ��� ����� ��� �޴� ��
class PassangerCar {
public:
	int seats;
	void set_seats(int n) { seats = n; }
};

class Truck {
public:
	int payload;
	void set_payload(int load) { payload = load; }
};

class Pickup :public PassangerCar, public Truck {
public:
	int tow_capability;
	void set_tow(int capa) { tow_capability = capa; }
};

#pragma region ���� ����� ������
class SuperA {
public:
	int x;
	void sub() {
		cout << "SuperA�� sub()" << endl;
	}
};
class SuperB {
public:
	int x;
	void sub() {
		cout << "SuperB�� sub()" << endl;
	}
};
class Sub : public SuperA, public SuperB{
};
#pragma endregion


int main() {
	Pickup my_car;
	my_car.set_seats(4);
	my_car.set_payload(10000);
	my_car.set_tow(30000);

#pragma region ���� ����� ������
	Sub obj;
	obj.x = 10;	//SuperA�� SuperB�� ��� x�� �����ϱ� ������ ��ȣ�ϴ�
	obj.SuperA::x = 10;	// ������ ���� ���������ڸ� �ٿ� ȣ��
	//	��� : ����� �����ϱ� ��ư� �̹��� �������� �߻���ų �� ������ �ſ� �����Ͽ� ���
	return 0;
#pragma endregion
	return 0;
}