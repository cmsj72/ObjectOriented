#include<iostream>
#include<string>
using namespace std;

#pragma region �������� ����
//	������(overriding) : �������̵�, �ڽ� Ŭ������ �Ƿῡ ���� ��ӵ� ��� �Լ��� �������Ͽ� ����ϴ� ��
class Car {
public:
	int getHP() {
		return 100;
	}
};

class SportsCar : public Car {
public:
	int getHP() {
		return 300;
	}
};
#pragma endregion

#pragma region �������� ����
//	�����Ǵ� ��� �Լ��� ����� �״�� �ΰ� ��ü���� ��ü�ϴ� �� 
//	�� ��� �κ��� �θ� Ŭ������ ����� �����ؾ���(�Լ� �̸�, ��ȯ��, �Ű� ������ ������ ������ Ÿ��) 
#pragma endregion


int main() {
#pragma region �������� ����
	SportsCar sc;
	cout << "����: " << sc.getHP() << endl;
	//	SportsCar ��ü�� sc�� ���� getHP()�� �����ϸ� �����ǵ� �Լ��� �켱���� �����Ƿ�
	//	SportsCar�� getHP()�� ȣ��ȴ�.
	//	���� �θ� Ŭ������ getHP()�� ȣ���ϰ� ������ ��������� ������ �����ڸ� ����ϸ� �ȴ�.
	//	sc.Car::getHP();
#pragma endregion

	


	return 0;
}