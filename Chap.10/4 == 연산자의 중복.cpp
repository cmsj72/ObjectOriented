#include<iostream>
using namespace std;

//	==과 != 연산자 중복
//	연산자			중복 함수 이름
//	==				operator==()
//	!=				operator!=()

//	==연산자는 두 개의 객체가 동일한 데이터를 가지고 있는지를 체크하는데 사용
//	두 개의 객체가 같은 데이터를 가지고 있는지를 검사하는 함수를 별도로 두는 것보다
//	==연산자를 중복하는 편이 더 좋다.
//	그 이유는 표준 라이브러리를 사용할 때 ==연산자가 정의되어 있으면 find()와 같은 라이브러리 함수를
//	쉽게 사용할 수 있기 때문, ==연산자가 정의되어 있으면 != 연산자도 당연히 정의하는 편이 혼란을 일으키지 않는다.
class Vector {
private:
	double x, y;
public:
	Vector(double xvalue = 0.0, double yvalue = 0.0) : x(xvalue), y(yvalue) {}
	void display() {
		cout << "(" << x << ", " << y << ")" << endl;
	}

	friend bool operator==(const Vector& v1, const Vector& v2);
	friend bool operator!=(const Vector& v1, const Vector& v2);
};

bool operator==(const Vector& v1, const Vector& v2) {
	return v1.x == v2.x && v1.y == v2.y;
}
bool operator!=(const Vector& v1, const Vector& v2) {
	return !(v1 == v2);	// 중복된 == 연산자를 이용
}

int main() {
	Vector v1(1, 2), v2(1, 2);

	cout.setf(cout.boolalpha);
	cout << (v1 == v2) << endl;
	cout << (v1 != v2) << endl;
	return 0;
}