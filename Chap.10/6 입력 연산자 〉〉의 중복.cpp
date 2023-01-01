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

//	�Է� �������� >>�� ��� �����ڿ� ����� ������ ���� �ߺ� �����ϸ� �ȴ�.
//	������ ���� �� ��° �Ű� ������ const�� �����ϸ� �� �ȴٴ� ���̴�.
//	�Է� �����ڴ� �Է��� �޾� ��ü�� �����Ͽ��� �ϱ� ������ const�� �����ؼ��� �ȵȴ�.
//	�׸��� �Է� �����ڴ� �Է� �ÿ� �߻��Ǵ� ������ ���Ͽ� ��� �Ͽ��� �Ѵ�.
//	���� ��� �Էµ� �����Ͱ� ��ġ�� �ƴ� ���ڿ��̾��� ��쿡�� ������ �߻��ϰ� �ǰ�,
//	�̶��� ����v�� �ʱ�ȭ ���·� ����� �ִ� ���� ����. �Է� �ܰ迡�� ������ �߻��ϸ� in��
//	0�� ���� ���� ��ȯ�ϰ� �ȴ�. ���� in�� 0�� �ƴ� ���� ��ȯ�ϸ� v�� (0,0)���� �ʱ�ȭ��
//	�ӽ� ��ü�� �����Ͽ� �ش�.
istream& operator>>(istream& in, Vector& v) {
	in >> v.x >> v.y;
	if (!in)
		v = Vector(0, 0);
	return in;
}