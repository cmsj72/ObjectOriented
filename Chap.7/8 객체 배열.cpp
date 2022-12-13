#include<iostream>
#include<string>
using namespace std;

class Car {
	int speed;
	int gear;
	string color;
public:
	Car(int s, int g = 1, string c = "white") : speed(s), gear(g), color(c) {}
	void print() {
		cout << "�ӵ�: " << speed << " ���: " << gear << " ����: " << color << endl;
	}
};

int main() {
	//	�� �迭 ���Һ��� ������ ȣ�� ����
	Car objArray[3] = {
		Car(0,1,"white"),
		Car(0,1,"red"),
		Car(0,1,"blue")
	};
	for (int i = 0; i < 3; i++)
		objArray[i].print();

	objArray->print();// objArray[0].print() �� ����
	(objArray + 1)->print(); // objArray[1].print() �� ����, + ������ -> ���꺸�� ���� ����Ǿ��ϹǷ� ()�� �־����
	for (int i = 0; i < 3; i++)
		(objArray + i)->print();

	Car* p = objArray;
	for (int i = 0; i < 3; i++) {
		p->print();
		p++;
	}

	return 0;
}