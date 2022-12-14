#include<iostream>
using namespace std;

//	자신의 카운트 변수만 증가하고 다른 객체의 카운터 변수들에는 영향X
//class Car {
//	int count;
//public:
//	Car() {
//		count++;
//	}
//};

//	전역 변수는 객체 지향의 원리에 위배
//int count;
//class Car {
//public:
//	Car() {
//		count++;
//	}
//};

//	정적 변수(static variable) : static을 붙여서 선언하는 변수, 클래스마다 하나만 생성
//	즉, 클래스의 모든 객체가 하나의 변수를 공유하는 것
//	카운터 변수를 정적 변수로 선언하고 생성자 안에서 증가시키면 지금까지 생산된 자동차 객체의 개수를 알 수 있다.
//	전역 변수는 클래스 변수라고도 한다.
class Car {
	int speed;
	int gear;
	string color;
	static int count;
public:
	//	정적 상수
	//	선언과 동시에 초기화 가능(단, 정수형만 가능)
	const static int MAX_PASSENGER = 5;
	const static int MAX_SPEED = 300;
	Car(int s = 0, int g = 1, string c = "white") : speed(s), gear(s), color(c) {
		//count = 0;	// 잘못된 초기화
		count++;
	}
	void print() {
		cout << "속도: " << speed << " 기어: " << gear << " 색상: " << color << endl;
	}
	~Car() {
		count--;
	}

	//	정적 멤버 함수도 클래스의 모든 객체들이 공유
	//	클래스의 이름을 통하여 호출
	//	객체를 만들지 않고 호출 가능 "Car::getCount();"
	//	정적 멤버 함수는 객체가 생성되지 않은 상태에서 호출되는 멤버 함수이므로
	//	정적 변수와 지역 변수만 사용 가능(일반 멤버 변수 사용 X)
	//	일반 멤버 함수 호출 역시 오류(일반 멤버 함수도 객체가 생성되어야만 사용 가능하기 때문)
	static int getCount() {
		return count;
	}
};

//	정적 변수의 초기화는 전역 변수와 비슷하게 클래스 외부에서 정의
int Car::count = 0;

//	인스턴스 변수들은 생성자 안에서 초기화 하지만 정적 변수는 클래스의 외부에서 초기화
//	정적 변수는 객체를 만들지 않고서도 사용될 수 있다. 객체가 없으므로 "Car::count"로 접근
//	

int main() {
	Car c1;
	Car c2;
}