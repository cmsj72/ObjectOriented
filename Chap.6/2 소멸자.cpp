#include<iostream>
#include<string>
using namespace std;

//	��ü�� ���󼭴� ��ü�� �Ҹ�Ǵ� �������� ������ �۾��� ���־�� �ϴ� ��찡 �ִ�.
//	�Ҹ��ڴ� ��ü �Ҹ� �ÿ� �ڵ����� ȣ��Ǵ� �Լ��̴�.
//	�����ڿ� ���������� ���� ��ȯ���� �ʴ´�.
//	�ܺο��� ȣ��Ǿ�� �ϹǷ� public ��� �Լ��� ����ȴ�.
//	�Ҹ��ڴ� �Ű� ������ ���� ������ ���� �ߺ� ���ǵ� �Ұ����ϴ�.
//	
//	�Ҹ��ڸ� �������� �ʴ´ٸ� �����ڿ� ���������� ����Ʈ �Ҹ��ڰ� �ڵ����� ���ԵǾ� ȣ��ȴ�.
class Car {
	int speed;
	int gear;
	string color;
public:
	Car(int s, int g, string c);
	~Car() {
		cout << "�Ҹ��� ȣ��" << endl;
	}
};

Car::Car(int s, int g, string c) {
		cout << "������ ȣ��" << endl;
		speed = s;
		gear = g;
		color = c;
}

int main() {
	Car c(0, 1, "yellow");
	return 0;
}