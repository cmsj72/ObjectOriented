#include<iostream>
using namespace std;

//	cout 은 ostream 클래스의 객체이기 때문에 멤버 함수로 정의하려면
//	ostream 클래스 안에 operator<<() 함수를 정의해야하지만
//	ostream 클래스는 컴파일러가 제공하는 라이브러리에 속하기 때문에 우리가 변경할 수 없다.
//	따라서 전역 함수 형태로 연산자<<를 중복 정의할 수밖에 없다.

class Vector {
	friend ostream& operator<<(ostream& os, const Vector& v);
private:
	double x, y;
public:
	Vector(double xvalue = 0.0, double yvalue = 0.0) : x(xvalue), y(yvalue) {}
	void display() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
};

ostream& operator<<(ostream& os, const Vector& v) {
	os << "(" << v.x << "," << v.y << ")" << endl;
	return os;
}

int main() {
	//	또, 주의할 점은 연산의 결과로 반드시 ostream 참조자를 반환하여야 한다는 점이다.
	//	ostream 참조자를 반환하지 않으면 다음과 같이 <<연산자를 연속적으로 사용되었을 경우에 제대로 작동하지 않는다.
	Vector v(2, 3);
	Vector w(3, 4);
	cout << v << w;
	//	결합 법칙에 의하여 (cout << v) << w; 와 같이 실행되고 이때
	//	(cout << v)가 cout을 반환해야만 cout << w;의 형태가 되어 올바르게 실행된다.

	Vector v1(1.0, 2.0), v2(3.0, 4.0), v3;
	cout << v1 << v2 << v3;
	return 0;

}