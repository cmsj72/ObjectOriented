#include<iostream>
#include<string>
using namespace std;

class Car {
private:
	int speed;
	int gear;
	string color;
public:
	int getSpeed();
	void setSpeed(int s);
	void setSpeed(double s);
};
//	중복 정의된 멤버 함수는 매개 변수의 개수와 타입에 의하여 서로 구별된다.
//	but 반환형을 사용하여 구별하지 않는다 → 반환형이 다르다고해서 중복 정의할 수는 없다.

void Car::setSpeed(int s) {
	speed = s;
}

void Car::setSpeed(double s) {
	speed = (int)s;
}

int main() {
	Car myCar;

	myCar.setSpeed(80);
	myCar.setSpeed(100.0);

	cout << "차의 속도: " << myCar.getSpeed() << endl;
	return 0;
}
