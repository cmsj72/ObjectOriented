#include<iostream>
using namespace std;

//	다중 상속(multiple inheritance)
//	하나의 자식 클래스가 두 개 이상의 부모 클래스로부터 멤버를 상속 받는 것
class PassangerCar {
public:
	int seats;
	void set_seats(int n) { seats = n; }
};

class Truck {
public:
	int payload;
	void set_payload(int load) { payload = load; }
};

class Pickup :public PassangerCar, public Truck {
public:
	int tow_capability;
	void set_tow(int capa) { tow_capability = capa; }
};

#pragma region 다중 상속의 문제점
class SuperA {
public:
	int x;
	void sub() {
		cout << "SuperA의 sub()" << endl;
	}
};
class SuperB {
public:
	int x;
	void sub() {
		cout << "SuperB의 sub()" << endl;
	}
};
class Sub : public SuperA, public SuperB{
};
#pragma endregion


int main() {
	Pickup my_car;
	my_car.set_seats(4);
	my_car.set_payload(10000);
	my_car.set_tow(30000);

#pragma region 다중 상속의 문제점
	Sub obj;
	obj.x = 10;	//SuperA와 SuperB에 모두 x가 존재하기 때문에 모호하다
	obj.SuperA::x = 10;	// 다음과 같이 범위지정자를 붙여 호출
	//	결론 : 상당히 이해하기 어렵고 미묘한 문제들을 발생시킬 수 있으니 매우 주의하여 사용
	return 0;
#pragma endregion
	return 0;
}