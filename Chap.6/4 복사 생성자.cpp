#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;


class Car {
	int speed;
	int gear;
	string color;

public:
	Car(int s, int g, string c) : speed(s), gear(g), color(c) {
		cout << "생성자 호출" << endl;
	}

	Car(const Car& obj) : speed(obj.speed), gear(obj.gear), color(obj.color) {
		cout << "복사 생성자 호출" << endl;
	}

	void print() {
		cout << "==========" << endl;
		cout << "속도: " << speed << endl;
		cout << "기어: " << gear << endl;
		cout << "색상: " << color << endl;
	}

	int getSpeed() { return speed; }
	int getGear() { return gear; }
	string getColor() { return color; }
};

//	복사 생성자를 명시적으로 정의하지 않아도 디폴트 복사 생성자가 자동으로 생성된다.
//	디폴트 복사 생성자는 객체가 가지고 있는 변수의 값을 복사한다.
class Car2 {
	int speed;
	int gear;
	string color;

public:
	Car2(int s, int g, string c) : speed(s), gear(g), color(c) {
		cout << "생성자 호출" << endl;
	}

	void print() {
		cout << "==========" << endl;cout << "속도: " << speed << endl;cout << "기어: " << gear << endl;cout << "색상: " << color << endl;
	}
};

//	
class Student {
	char* name;
	int number;
public:
	Student(char* p, int n) {
		cout << "메모리 할당" << endl;
		name = new char[strlen(p) + 1];
		strcpy(name, p);
		number = n;
	}
	~Student() {
		cout << "메모리 소멸" << endl;
		delete[] name;
	}
};

void isMoving(Car obj) {
	if (obj.getSpeed() > 0) cout << "움직이고 있습니다" << endl;
	else cout << "정지해 있습니다" << endl;
}

Car createCar() {
	Car obj(0, 1, "white");
	return obj;
}

int main() {
	Car c1(0, 1, "yellow");
	Car c2(c1);
	//	Car c2 = c1;// 다음과 같이 c2를 생성하여도 복사 생성자가 호출된다.
	c1.print();
	c2.print();

	Car2 c3(40, 100, "red");
	Car2 c4(c3);
	c3.print();
	c4.print();

	//	오류 발생 이유 : 디폴트 복사 생성자에서 단순히 한 객체의 멤버의 값을 다른 객체의 멤버로 복사했기 때문
	//	name이라는 포인터 안에 들어있던 주소값만 복사가 되었기 때문, s2를 위한 새로운 공간이 할당되지 않았고
	//	동일한 공간을 s1과 s2가 공유하는 상황(얕은 복사, shallow copy)
	//	지역 변수인 s1이 소멸되면서 이름을 저장한 메모리 공간을 반납하게되고 이 동일한 공간을 다른 지역 변수 s2가
	//	소멸될 때 다시 반납하려고 하기 때문
	//	해결 방법 : 디퐅르 생성자를 사용하지 않고 직접 복사 생성자를 구현(깊은 복사, deep copy)
	char tmp[5] = "Park";
	Student s1(tmp, 201000001);
	Student s2(s1);

	//	isMoving 함수에서 객체를 받아 객체의 정보를 출력, isMoving이 호출되면서 복사 생성자가 호출되면서
	//	인자인 s1 객체의 속성이 obj로 모두 복사가 되는 것
	//	같은 식으로 만약 함수가 반환값으로 객체를 반환하였다면 그 과정에서도 복사 생성자가 호출된다.
	isMoving(c1);

	Car newCar = createCar();
	newCar.print();

	return 0;
}

