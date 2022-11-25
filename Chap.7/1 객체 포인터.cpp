#include<iostream>
#include<string>
using namespace std;

//	동적할당 정적할당 정리 참고 사이트
//	https://colinch4.github.io/2020-01-12/allocation/
class Car {
	int speed;
	int gear;
	string color;
public:
	Car(int s = 0, int g = 1, string c = "white") : speed(s), gear(g), color(c) {

	}

	void print() {
		cout << "속도: " << speed << " 기어: " << gear << " 색상: " << color << endl;
	}
};

int main() {
	//	정적 메모리 할당으로 객체 생성
	//	변수나 함수, 배열 등을 선언함으로써 메모리에 할당할 때, 메모리에게 그 크기를 알려주어
	//	메모리 공간의 필요량을 알려줌
	Car myCar;
	myCar.print();

	//	동적 메모리 할당으로 객체 생성
	//	프로그램이 실행 도중에 동적으로 메모리를 할당 받는 것
	//	다 쓴 메모리는 꼭 반납(해제)해야함, 메모리 누수가 발생하기 때문
	Car* pCar = new Car(0, 1, "blue");
	pCar->print();
	return 0;
}