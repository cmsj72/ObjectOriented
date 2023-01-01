#include<iostream>
using namespace std;

class Vector {
	friend istream& operator>>(istream& os, Vector& v);
private:
	double x, y;
public:
	Vector(double xvalue = 0.0, double yvalue = 0.0) : x(xvalue), y(yvalue) {}
	void display() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
};

//	입력 연산자인 >>는 출력 연산자와 비슷한 과정을 거쳐 중복 정의하면 된다.
//	주의할 점은 두 번째 매개 변수를 const로 선언하면 안 된다는 것이다.
//	입력 연산자는 입력을 받아 객체에 저장하여야 하기 때문에 const로 선언해서는 안된다.
//	그리고 입력 연산자는 입력 시에 발생되는 오류에 대하여 대비를 하여야 한다.
//	예를 들어 입력된 데이터가 수치가 아닌 문자열이었을 경우에는 오류가 발생하게 되고,
//	이때는 변수v를 초기화 상태로 만들어 주는 것이 좋다. 입력 단계에서 오류가 발생하면 in은
//	0이 아인 값을 반환하게 된다. 따라서 in이 0이 아닌 값을 반환하면 v에 (0,0)으로 초기화한
//	임시 객체를 복사하여 준다.
istream& operator>>(istream& in, Vector& v) {
	in >> v.x >> v.y;
	if (!in)
		v = Vector(0, 0);
	return in;
}