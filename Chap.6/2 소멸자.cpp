#include<iostream>
#include<string>
using namespace std;

//	객체에 따라서는 객체가 소멸되는 시점에서 마무리 작업을 해주어야 하는 경우가 있다.
//	소멸자는 객체 소멸 시에 자동으로 호출되는 함수이다.
//	생성자와 마찬가지로 값을 반환하지 않는다.
//	외부에서 호출되어야 하므로 public 멤버 함수로 선언된다.
//	소멸자는 매개 변수를 받지 않으며 따라서 중복 정의도 불가능하다.
//	
//	소멸자를 정의하지 않는다면 생성자와 마찬가지로 디폴트 소멸자가 자동으로 삽입되어 호출된다.
class Car {
	int speed;
	int gear;
	string color;
public:
	Car(int s, int g, string c);
	~Car() {
		cout << "소멸자 호출" << endl;
	}
};

Car::Car(int s, int g, string c) {
		cout << "생성자 호출" << endl;
		speed = s;
		gear = g;
		color = c;
}

int main() {
	Car c(0, 1, "yellow");
	return 0;
}