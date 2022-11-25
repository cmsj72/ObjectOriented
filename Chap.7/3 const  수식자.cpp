#include<iostream>
#include<string>
using namespace std;

class Car {
	//	값이 변하지 안흔 멤버들은 const를 이용하여 상수로 만드는 것이 바람직하다.
	//	예를 들어 자동차의 시리얼 번호는 자동차 생성시에 결정되고 차후 변경되지 않으므로 상수라고 선언하는 편이 좋다.
	const int serial;
	int speed;
	int gear;
	string color;
public:
	Car(int ser, int s = 0, int g= 1, string c = "white") : serial(ser), speed(s), gear(s), color(c){}
	int getSpeed() {
		return speed;
	}
	int setSpeed(int speed) {
		this->speed = speed;
	}

	//	멤버 함수에 const를 붙이면 이 함수를 통하여 멤버 변수를 변경할 수 없다는 의미
	//	const가 붙는 함수를 상수 멤버 함수라 부른다.
	//	상수 멤버 함수 안에서 상수화되지 않은 함수를 호출하면 오류가 발생
	void displaySpeed() const {
		cout << "자동차의 속도: " << speed << endl;
		//int tmp = getSpeed(); <- 오류 발생
	}

	
};

//	함수의 매개 변수 선언에서 객체 참조자에 const를 붙이는 경우가 많다.
//	참조자에 const가 붙으면 이 참조자를 통해서 멤버 변수의 값을 변경할 수 없으며, 상수화되지 않은 함수도 호출할 수 없다.
void sub(Car& c, const Car& cc) {
	int s1 = c.getSpeed();
	c.setSpeed(100);

	//int s2 = cc.getSpeed();	만약 getSpeed()는 상수 멤버 함수로 정의가 되어있고 setSpeed()는 되어있지 않으면 
	//cc.setSpeed(200);			getSpeed()만 호출 가능
}

int main() {
	Car c1(1, 0, 1, "white");
	Car c2(2, 0, 1, "red");
	Car c3(3, 0, 1, "blue");
	Car c4(4);

	//	객체에 const가 붙는다면 이 객체를 통해서는 멤버 변수의 값을 변경할 수 없다.
	//	멤버 함수의 경우에도 상수 멤버 함수가 아니면 호출할 수 없다.
	const Car c5(5, 0, 1, "yellow");
	//int s = c5.setSpeed(5); 오류 발생, 자동완성 단계에서 표시되지 않음

	return 0;
}