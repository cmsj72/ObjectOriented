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
		cout << "속도: " << speed << " 기어: " << gear << " 색상: " << color << endl;
	}
};

int main() {
	//	각 배열 원소별로 생성자 호출 가능
	Car objArray[3] = {
		Car(0,1,"white"),
		Car(0,1,"red"),
		Car(0,1,"blue")
	};
	for (int i = 0; i < 3; i++)
		objArray[i].print();

	objArray->print();// objArray[0].print() 와 동일
	(objArray + 1)->print(); // objArray[1].print() 와 동일, + 연산이 -> 연산보다 먼저 실행되야하므로 ()가 있어야함
	for (int i = 0; i < 3; i++)
		(objArray + i)->print();

	Car* p = objArray;
	for (int i = 0; i < 3; i++) {
		p->print();
		p++;
	}

	return 0;
}