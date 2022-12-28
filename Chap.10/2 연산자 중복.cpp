#include<iostream>
using namespace std;
//	연산자 중복(operator overloading)
//	여러 가지 연산자들을 클래스 객체에 대해서도 적용할 수 있도록 중복하여 정의하는 것
//	
//	형식
//	반환형 operator연산자(매개 변수 목록){
//
//	}

//	연산자 중복 함수 이름
//	연산자		중복 함수 이름
//	+			operator+()
//	-			operator-()
//	*			operator*()
//	/			operator/()

//	연산자는 클래스의 멤버로 정의하는 것이 원칙
//	하지만 프렌드를 이용하여 클래스의 외부에서 정의될 수도 있다.

//	멤버 함수로만 중복할 수 있는 연산자
//	연산자			설명
//	=				대입 연산자
//	()				함수 호출 연산자
//	[]				배열 원소 참조 연산자
//	->				멤버 참조 연산자

//	중복할 수 없는 연산자
//	연산자			설명
//	::				범위 지정 연산자
//	.				멤버 선택 연산자
//	.*				멤버 포인터 연산자
//	?:				조건 연산자
//	이들 연산자들은 모두 상당히 중요한 역할을 하는 연산자이기 때문에 중복 정의 금지

class Vector {
	//	전역 함수로 연산자 함수 선언 및 프렌드 선언
	friend Vector operator+(const Vector& v1, const Vector& v2);
private:
	double x, y;
public:
	Vector(double xvalue = 0.0, double yvalue = 0.0) : x(xvalue), y(yvalue) {}
	void display() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
	Vector operator+(Vector& v2) {
		Vector v;
		v.x = this->x + v2.x;
		v.y = this->y + v2.y;
		return v;
	}
};

//	+ 연산자 함수 선언
Vector operator+(const Vector& v1, const Vector& v2) {
	Vector v(0.0, 0.0);
	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	return v;
}

int main() {
	Vector v1(10.0, 20.0), v2(30.0, 40.0);
	Vector v3 = v1 + v2;
	v3.display();

	Vector v4(1.0, 2.0), v5(3.0, 4.0);
	Vector v6 = v4.operator+(v5);	//	operator+() 함수 형태로 호출
	v6.display();

	return 0;
}