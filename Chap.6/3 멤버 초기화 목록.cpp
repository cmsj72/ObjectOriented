#include<iostream>
#include<string>
using namespace std;

class Car {
	int speed;
	int gear;
	string color;

	//	����� ����ο��� �ʱ�ȭ�ϸ� �޸𸮰� �Ҵ���� �ʾұ� ������ �ʱ�ȭ X, �ʱ�ȭ ��Ͽ��� �ʱ�ȭ
	const int MAX_SPEED;
	//	�������� �������� ���� �ÿ� �����ϴ� ������ �����Ǿ�� �Ѵ�.
	//	�ٸ�, Ŭ���� �ȿ� ����� �������� ��� ������ ȣ�� ������ �ʱ�ȭ�� ����ȴ�.
	string& alias;
public:
	//	������ �Լ� ����� ��ü ���̿� : �� ��� ���(�Ű�����) �� ������ ����Ͽ� ����� �ʱⰪ ����
	Car(int s, int g, string c, string a) : speed(s), gear(g), color(c), MAX_SPEED(300), alias(a) {
		//	���� �� �ϰ� ���� �ʱ�ȭ�� ������ ���⿡
		cout << alias << endl;
	}
};

class Point {
	int x, y;
public:
	Point() {
		x = 0, y = 0;
	}
	Point(int a, int b) : x(a), y(b) {}
};

class Rectangle {
	Point p1, p2, tmp;
public:
	//	Rectangle�� ������ �ȿ��� Point()�� �����ڸ� ȣ���� ���� ����.
	//	�����ڴ� ��ü�� ������ �� �ڵ����θ� ȣ��Ǳ� ������ �Ϲ� �Լ�ó�� ��������� ȣ�� �Ұ���
	//	���� ���Ե� ��ü�� ����Ʈ �����ڸ� �����Ͽ��ٸ� ��� �ʱ�ȭ ����� ����Ͽ� �ʱ�ȭ���� �ʾƵ�
	//	�����Ϸ��� �ڵ����� ����Ʈ �����ڸ� ȣ��. ������ ����Ʈ ���� �ƴ� �ٸ� ������ �ʱ�ȭ�ϴ� ��쿡�� 
	//	�ݵ�� ���� ���� ��� �ʱ�ȭ ����� ����Ͽ��� �Ѵ�.
	Rectangle(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2) {

	}
};

int main() {
	Rectangle r1(10, 10, 100, 100);
}