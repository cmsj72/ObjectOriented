#include<iostream>
using namespace std;

//	cout �� ostream Ŭ������ ��ü�̱� ������ ��� �Լ��� �����Ϸ���
//	ostream Ŭ���� �ȿ� operator<<() �Լ��� �����ؾ�������
//	ostream Ŭ������ �����Ϸ��� �����ϴ� ���̺귯���� ���ϱ� ������ �츮�� ������ �� ����.
//	���� ���� �Լ� ���·� ������<<�� �ߺ� ������ ���ۿ� ����.

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
	//	��, ������ ���� ������ ����� �ݵ�� ostream �����ڸ� ��ȯ�Ͽ��� �Ѵٴ� ���̴�.
	//	ostream �����ڸ� ��ȯ���� ������ ������ ���� <<�����ڸ� ���������� ���Ǿ��� ��쿡 ����� �۵����� �ʴ´�.
	Vector v(2, 3);
	Vector w(3, 4);
	cout << v << w;
	//	���� ��Ģ�� ���Ͽ� (cout << v) << w; �� ���� ����ǰ� �̶�
	//	(cout << v)�� cout�� ��ȯ�ؾ߸� cout << w;�� ���°� �Ǿ� �ùٸ��� ����ȴ�.

	Vector v1(1.0, 2.0), v2(3.0, 4.0), v3;
	cout << v1 << v2 << v3;
	return 0;

}