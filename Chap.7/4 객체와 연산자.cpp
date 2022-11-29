#include<iostream>
#include<string>
using namespace std;

class Car {
	int speed;
	int gear;
	string color;
public:
	Car(int s = 0, int g = 1, string c = "white") : speed(s), gear(s), color(c) {}
};

int main() {
	Car c1(0, 1, "white");
	Car c2(0, 1, "red");
	c1 = c2;
	//	c2의 멤버 변수가 c1으로 복사된다.
	//	객체끼리 복사 가능, c2가 가지고 있는 모든 멤버 변수의 값이 c1으로 복사
	//	같은 타입의 객체끼리는 대입 연산이 가능

	//	Car클래스에서 ==연산자를 정의하지 않았기 때문에 컴파일 오류 발생
	//	연산자 중복(operator overloading)을 이용하여 정의할 수 있다(Chap.10)
	if (c1 == c2) {
		cout << "같습니다" << endl;
	}
	else {
		cout << "같지 않습니다" << endl;
	}
	return 0;
}