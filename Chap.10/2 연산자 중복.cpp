#include<iostream>
using namespace std;
//	������ �ߺ�(operator overloading)
//	���� ���� �����ڵ��� Ŭ���� ��ü�� ���ؼ��� ������ �� �ֵ��� �ߺ��Ͽ� �����ϴ� ��
//	
//	����
//	��ȯ�� operator������(�Ű� ���� ���){
//
//	}

//	������ �ߺ� �Լ� �̸�
//	������		�ߺ� �Լ� �̸�
//	+			operator+()
//	-			operator-()
//	*			operator*()
//	/			operator/()

//	�����ڴ� Ŭ������ ����� �����ϴ� ���� ��Ģ
//	������ �����带 �̿��Ͽ� Ŭ������ �ܺο��� ���ǵ� ���� �ִ�.

//	��� �Լ��θ� �ߺ��� �� �ִ� ������
//	������			����
//	=				���� ������
//	()				�Լ� ȣ�� ������
//	[]				�迭 ���� ���� ������
//	->				��� ���� ������

//	�ߺ��� �� ���� ������
//	������			����
//	::				���� ���� ������
//	.				��� ���� ������
//	.*				��� ������ ������
//	?:				���� ������
//	�̵� �����ڵ��� ��� ����� �߿��� ������ �ϴ� �������̱� ������ �ߺ� ���� ����

class Vector {
	//	���� �Լ��� ������ �Լ� ���� �� ������ ����
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

//	+ ������ �Լ� ����
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
	Vector v6 = v4.operator+(v5);	//	operator+() �Լ� ���·� ȣ��
	v6.display();

	return 0;
}