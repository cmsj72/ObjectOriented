#include<iostream>
#include<string>
using namespace std;

//	객체가 생성된 후에는 반드시 객체를 초기화하여야 한다.
//	객체의 초기화에는 멤버 변수의 값을 초기화 뿐만 아니라 객체의 동작에 필요한
//	메모리 공간이나 파일과 같은 여러 가지 자원들을 할당받는 것도 포함
//	생성자를 사용하면 객체 생성과 동시에 초기화가 가능
//	객체가 생성될 때 자동으로 한번만 호출, 클래스 이름과 동일한 이름을 가짐,
//	값을 반환하지 않으며 매개 변수를 받을 수 있고 중복 정의도 가능
// 
//	생성자를 하나도 정의하지 않으면 자동으로 비어있는 디폴트 생성자가 하나 생성됨.
//	몸체가 비어있기 때문에 실행결과에 아무런 영향을 끼치지 않는다.
//
//	생성자는 실제로 객체를 생성하는 멤버 함수는 아니다. 객체가 생성될 때 초기화 하는 멤버 함수이다.
class Car {
private:
	int speed;
	int gear;
	string color;
public:
	//	매개 변수를 가지지 않는 디폴트 생성자(default contructor)
	Car() {
		cout << "디폴트 생성자 호출" << endl;
		speed = 0;
		gear = 1;
		color = "red";
	}
	Car(int speed, int gear, string color);
	Car(int s, int g, string c);
	Car(string c);
};

//	매개 변수를 가지는 생성자
Car::Car(int speed, int gear, string color) {
	cout << "매개 변수가 있는 생성자 호출" << endl;
	this->speed = speed;
	this->gear = gear;
	this->color = color;
}

//	함수이기 때문에 디폴트 매개 변수 사용 가능
Car::Car(int s = 0, int g = 1, string c = "black") {
	speed = s;
	gear = g;
}

//	생성자에서 다른 생성자 호출 가능
Car::Car(string c) {
	Car(0, 0, c);
}

int main() {
	Car c1;								//	1.	디폴트 생성자 호출
	Car c2();							//	2.	c2()라는 함수의 원형 선언, 생성자 호출 아님
	Car c3(100, 3, "white");			//	3.	생성자 호출
	Car c4 = Car(0, 1, "blue");			//	4.	먼저 임시 객체를 만들고 이것을 c4에 복사
	
	//	2. 추가 설명
	//	생성자의 호출처럼 보이지만 컴파일러는 함수의 원형을 선언한 것으로 해석
	//	즉, Car라는 객체를 반환하는 함수 c2()의 원형을 정의한 것으로 간주
	//	like) int sub(); // int를 반환하는 sub()
	return 0;
}