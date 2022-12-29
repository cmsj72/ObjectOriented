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

//	��ȯ ��Ģ�� �����Ϸ��� �ڵ����� ������ִ� ���� �ƴϱ� ������
//	����ڰ� �����ڸ� ������ ���� �ݵ�� �Ű� ������ ��ġ�� ��ȯ�� ������ �Լ��� ����� �־�� �Ѵ�.

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