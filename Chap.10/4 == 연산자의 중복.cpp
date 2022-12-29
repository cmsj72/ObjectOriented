#include<iostream>
using namespace std;

//	==�� != ������ �ߺ�
//	������			�ߺ� �Լ� �̸�
//	==				operator==()
//	!=				operator!=()

//	==�����ڴ� �� ���� ��ü�� ������ �����͸� ������ �ִ����� üũ�ϴµ� ���
//	�� ���� ��ü�� ���� �����͸� ������ �ִ����� �˻��ϴ� �Լ��� ������ �δ� �ͺ���
//	==�����ڸ� �ߺ��ϴ� ���� �� ����.
//	�� ������ ǥ�� ���̺귯���� ����� �� ==�����ڰ� ���ǵǾ� ������ find()�� ���� ���̺귯�� �Լ���
//	���� ����� �� �ֱ� ����, ==�����ڰ� ���ǵǾ� ������ != �����ڵ� �翬�� �����ϴ� ���� ȥ���� ����Ű�� �ʴ´�.
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
	return !(v1 == v2);	// �ߺ��� == �����ڸ� �̿�
}

int main() {
	Vector v1(1, 2), v2(1, 2);

	cout.setf(cout.boolalpha);
	cout << (v1 == v2) << endl;
	cout << (v1 != v2) << endl;
	return 0;
}