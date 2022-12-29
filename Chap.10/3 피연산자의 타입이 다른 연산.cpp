#include<iostream>
using namespace std;

class Vector {
	friend Vector operator*(Vector& v, double alpha);
	friend Vector operator*(double alpha, Vector& v);
private:
	double x, y;
public:
	Vector(double xvalue = 0.0, double yvalue = 0.0) : x(xvalue), y(yvalue) {}
	void display() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
};

//	교환 법칙은 컴파일러가 자동으로 만들어주는 것이 아니기 때문에
//	사용자가 연산자를 정의할 때는 반드시 매개 변수의 위치가 교환된 연산자 함수를 만들어 주어야 한다.

Vector operator*(Vector& v, double alpha) {
	return Vector(alpha * v.x, alpha * v.y);
}

Vector operator*(double alpha, Vector& v) {
	return Vector(alpha * v.x, alpha * v.y);
}

int main() {
	Vector v(1.0, 2.0);
	Vector w = v * 2.0;
	Vector z = 2.0 * v;
	w.display();
	z.display();
	return 0;
}