#include<iostream>
#include<string>
using namespace std;

#pragma region 재정의의 개념
//	재정의(overriding) : 오버라이딩, 자식 클래스가 피료에 따라 상속된 멤버 함수를 재정의하여 사용하는 것
class Car {
public:
	int getHP() {
		return 100;
	}
};

class SportsCar : public Car {
public:
	int getHP() {
		return 300;
	}
};
#pragma endregion

#pragma region 재정의의 조건
//	재정의는 멤버 함수의 헤더는 그대로 두고 몸체만을 교체하는 것 
//	→ 헤더 부분은 부모 클래스의 헤더와 동일해야함(함수 이름, 반환형, 매개 변수의 개수와 데이터 타입) 
#pragma endregion


int main() {
#pragma region 재정의의 개념
	SportsCar sc;
	cout << "마력: " << sc.getHP() << endl;
	//	SportsCar 객체인 sc를 통해 getHP()에 접근하면 재정의된 함수가 우선권이 있으므로
	//	SportsCar의 getHP()가 호출된다.
	//	만약 부모 클래스의 getHP()를 호출하고 싶으면 명시적으로 범위를 지정자를 사용하면 된다.
	//	sc.Car::getHP();
#pragma endregion

	


	return 0;
}