#include<iostream>
#include<string>
using namespace std;

//	��ӿ��� �����ڿ� �Ҹ��� ȣ�� ����
//	������ : �θ� �� �ڽ�
//			�ڽ� Ŭ������ �����ڿ��� �θ� Ŭ������ �����ڸ� ȣ��
//			(Ư���� �������� ������ �θ� Ŭ������ �⺻ ������ ȣ��)
// 
//	�Ҹ��� : �ڽ� �� �θ�

//	�θ� Ŭ������ �����ڸ� �����ϴ� ���
//	�ڽ� Ŭ������ ������() :  �θ� Ŭ������ ������()
//	{
// 
//	}

class Shape {
	int x, y;
public:
	Shape() : x(0), y(0){
		cout << "Shape ������() " << endl;
	}
	Shape(int xValue, int yValue) : x(xValue), y(yValue) {

	}
	~Shape() {
		cout << "Shape �Ҹ���() " << endl;
	}
};

class Rectangle : public Shape {
	int width, height;
public:
	Rectangle() : width(0), height(0){
		cout << "Rectangle ������()" << endl;
	}
	//	�θ� Ŭ������ ������ ȣ��
	Rectangle(int x = 0, int y = 0, int w = 0, int h = 0) : Shape(x, y) {
		width = w;
		height = h;
	}
	//	�θ� Ŭ������ ������ ȣ�� ������ ��� �ʱ�ȭ ����Ʈ�� �ٿ��� �ȴ�.
	Rectangle(int x = 0, int y = 0, int w = 0, int h = 0) : Shape(x, y), width(w), height(h){}
	~Rectangle() {
		cout << "Rectangle �Ҹ���()" << endl;
	}
};

int main() {
	Rectangle r();
	return 0;
}