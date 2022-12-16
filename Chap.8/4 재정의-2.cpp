#include<iostream>
#include<string>
using namespace std;

#pragma region 중복 정의와 재정의의 차이
//	중복 정의	: 같은 이름의 멤버 함수를 여러 개 정의하는 것
//	재정의	: 부모 클래스에 있던 상속 받은 멤버 함수를 다시 정의해서 내용을 변경하는 것
#pragma endregion

#pragma region 재정의된 멤버 함수의 호출 순서
class Animal {
public:
	void sleep() {}
	void eat() {}
	void move() {}
	void sound() {}
};
class Bird : public Animal {
public:
	void sound() {}
};
class Eagle : public Bird {
public:
	void move() {}
	void eat() {}
};
#pragma endregion

#pragma region 부모 클래스의 멤버 함수 호출
class ParentClass {
public:
	void print() {
		cout << "부모 클래스의 print() 멤버 함수" << endl;
	}		
};
class ChildClass : public ParentClass {
	int data;
public:
	void print() {
		ParentClass::print();// 부모 클래스의 함수 호출
		cout << "자식 클래스의 print() 멤버 함수" << endl;
	}
};
#pragma endregion

#pragma region 멤버 변수 재정의
class Car {
public:
	int speed, gear;
	string color;
	Car() : speed(0), gear(10), color("white") {}
	void setSpeed(int s) { speed = s; }
	int getSpeed() { return speed; }
};
class SportsCar : public Car {
public:
	int speed, gear;
	string color;
	SportsCar() : speed(100), gear(3), color("blue") {}
};
#pragma endregion


int main() {
#pragma region 재정의된 멤버 함수의 호출 순서
	Eagle e;
	e.sleep();
	e.eat();
	e.sound();
#pragma endregion

#pragma region 부모 클래스의 멤버 함수 호출
	ChildClass obj;
	obj.print();
	return 0;
#pragma endregion

#pragma region 멤버 변수 재정의
	SportsCar sc;
	cout << "스피드: " << sc.speed << endl;		//	자식 클래스의 speed
	cout << "스피드: " << sc.Car::speed << endl;	//	부모 클래스의 speed
	cout << "스피드: " << sc.getSpeed() << endl;	//	부모 클래스의 speed 반환
	//	SportsCar의 변수 speed가 부모 클래스 Car의 변수 speed를 가리게 된다.
	//	Car의 멤버 함수는 Car안에 정의된 speed를 사용하고 
	//	SportsCar의 함수들은 SportsCar 안에 정의된 speed를 사용하게 되는 것
	//	즉, 어떤 멤버 함수를 사용하느냐에 따라 서로 다른 speed가 사용될 수 있다.
	//	결론적으로 멤버 변수를 재정의하는 것은 절대 피해야 한다.
#pragma endregion

	return 0;
}