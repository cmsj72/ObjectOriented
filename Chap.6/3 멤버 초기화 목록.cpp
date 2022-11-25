#include<iostream>
#include<string>
using namespace std;

class Car {
	int speed;
	int gear;
	string color;

	//	상수는 선언부에서 초기화하면 메모리가 할당되지 않았기 때문에 초기화 X, 초기화 목록에서 초기화
	const int MAX_SPEED;
	//	참조나는 별명으로 선언 시에 참조하는 변수가 지정되어야 한다.
	//	다만, 클래스 안에 선언된 참조자의 경우 생성자 호출 때까지 초기화가 연기된다.
	string& alias;
public:
	//	생성자 함수 헤더와 몸체 사이에 : 를 찍고 멤버(매개변수) 의 형식을 사용하여 멤버의 초기값 나열
	Car(int s, int g, string c, string a) : speed(s), gear(g), color(c), MAX_SPEED(300), alias(a) {
		//	만약 더 하고 싶은 초기화가 있으면 여기에
		cout << alias << endl;
	}
};

class Point {
	int x, y;
public:
	Point() {
		x = 0, y = 0;
	}
	Point(int a, int b) : x(a), y(b) {}
};

class Rectangle {
	Point p1, p2, tmp;
public:
	//	Rectangle의 생성자 안에서 Point()의 생성자를 호출할 수는 없다.
	//	생성자는 객체가 생성될 때 자동으로만 호출되기 때문에 일반 함수처럼 명시적으로 호출 불가능
	//	만약 포함된 객체가 디폴트 생성자를 정의하였다면 멤버 초기화 목록을 사용하여 초기화하지 않아도
	//	컴파일러가 자동으로 디폴트 생성자를 호출. 하지만 디폴트 값이 아닌 다른 값으로 초기화하는 경우에는 
	//	반드시 위와 같은 멤버 초기화 목록을 사용하여야 한다.
	Rectangle(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2) {

	}
};

int main() {
	Rectangle r1(10, 10, 100, 100);
}