#include<iostream>
#include<string>
using namespace std;

//	멤버 정의 시에 아무것도 붙이지 않으면 default로 모든 멤버가 private가 된다.
//	모든 멤버 변수를 외부에 공개하는 것은 정보 은닉의 개념에 위배되는 것,
//	더 좋은 방법은 특수한 멤버 함수를 사용하여 멤버 변수의 값을 읽거나 설정하는 것.
class Employee {
private:
	string name;
	int salary;
	int age;
	int getSalary() { return salary; }

public:
	int getAge() { return age; }
	string getName() { return name; }
};
//	참고사항
//	일반적으로 멤버에 대해서는 가장 엄격한 접근 제어를 선택. 만약 특별한 이유가 없으면 private를 선택
//	상수를 제외하고는 멤버 변수에 public을 사용하면 안된다. 외부 클래스들이 public 멤버 변수를 사용하면 코드를 변경하기 힘들어진다.


//	접근자와 설정자를 사용하는 이유
//	1.정보 은닉, 클래스의 인터페이스와 구현이 분리되면 구현을 변곁하기 쉬워진다.
//	2.설정자에서 매개 변수를 통하여 잘못된 값이 넘어오는 경우, 이를 사전에 차단할 수 있다.
//	3.멤버 변수값을 필요할 때마다 계산하여 반환할 수 있다.
//	4.접근자만을 제공하면 자동적으로 읽기만 가능한 멤버 변수를 만들 수 있다.
//	  또한 접근자는 반환하는 데이터의 형식을 제어할 수 있기 때문에, 외부 코드가 실제 데이터 표현 방식을 모르게 할 수 있다.
class Car {
private:
	int speed;
	int gear;
	string color;

public:	
	int getSpeed() {//접근자
		return speed;
	}
		
	void setSpeed(int s) {//설정자
		speed = s;
	}

	int getGear() {
		return gear;
	}

	void setGear(int g) {
		gear = g;
	}

	string getColor() {
		return color;
	}

	void setColor(string c) {
		color = c;
	}
};

int main() {
	Employee e;
	//	private이기 때문에 접근 불가능
	e.salary = 300;
	e.age = 26;
	int sa = e.getSalary();

	string s = e.getName();
	int a = e.getAge();

	Car myCar;

	myCar.setSpeed(100);
	myCar.setGear(3);
	myCar.setColor("red");

	cout << "차의 속도: " << myCar.getSpeed() << endl;
	cout << "차의 기어: " << myCar.getGear() << endl;
	cout << "차의 색상: " << myCar.getColor() << endl;
	return 0;
}