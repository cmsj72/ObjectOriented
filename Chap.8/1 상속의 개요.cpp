#include<iostream>
#include<string>
using namespace std;

//	상속(inheritance)
//	기존에 존재하는 유사한 클래스로부터 속성과 동작을 이어받고
//	자신에게 필요한 기능을 추가하는 기법
//	부모 클래스 == 슈퍼 클래스 == 베이스 클래스
//	자식 클래스 == 서브 클래스 == 파생된 클래스

//	상속은 is-a 관계
//	ex)
//	자동차는 탈것이다.(Car is a Vehicle)
//	사자,개,고양이는 동물이다.
//	만약 "~은 ~을 가지고 있다"와 같은 has-a(포함) 관계가 성립되면 이 관계는 상속으로 모델링하면 안 된다.
//	ex)
//	도서관은 책을 가지고 있다(Library has a book)
//	거실은 소파를 가지고 있다.
class Car {
public:
	int speed;
	int gear;
	string color;

	void setGear(int newGear) {
		gear = newGear;
	}
	void speedUp(int increament) {
		speed += increament;
	}
	void speedDown(int decrement) {
		speed -= decrement;
	}
};

class SportsCar : public Car {
	bool turbo;
public:
	void setTurbo(bool newValue) {
		turbo = newValue;
	}
};

int main() {
	SportsCar c;
	c.color = "Red";
	c.setGear(3);
	c.speedUp(100);
	c.speedDown(30);
	c.setTurbo(true);
	return 0;
}