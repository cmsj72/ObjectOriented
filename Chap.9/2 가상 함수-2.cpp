#include<iostream>
#include<string>
using namespace std;

#pragma region ���� ���ε�
//	�Լ� ȣ���� �Լ��� ��ü�� �����ϴ� ���� ���ε�(binding)�̶� �Ѵ�.
//	���� ���ε�(static binding) : ������ �ܰ迡�� ��� ���ε��� �Ϸ�Ǵ� ��
//	���� ���ε�(dynamic binding) : ���ε��� ���� �ñ��� ����ǰ� ���� �ð��� ȣ��Ǵ� �Լ�(���� ���ε�, late binding)

//	���� ���ε��� ����ϸ� ��ü ������ �߿��� Ư¡ ���� �ϳ��� �������� ������ �� �ִ�
//	C++������ ���� �Լ��� �ƴϸ� ��� �Լ��� ���� ���ε����� ȣ��ȴ�.
//	���� ���ε��� ȣ�� �ӵ��� �������� ȣ�� �Լ��� ������ �ܰ迡�� �����ǹǷ� �������� ��������.
//	���� �Լ��� ���� ���ε����� ȣ��ȴ�.
//	���� ���ε��� ���̺��� ����Ͽ� ���� ȣ��Ǵ� �Լ��� �����Ͽ��� �ϹǷ� ó�� �ӵ��� �ʾ�����.
//	�׷����� ��ü�� ���� Ÿ�Կ� �´� ������ �� �� �ִ�.
#pragma endregion


class Shape {
protected:
	int x, y;
public:
	void setOrigin(int x, int y) {
		this->x = x;
		this->y = y;
	}
	//	���� �Լ� ����
	virtual void draw() {
		cout << "Shape Draw" << endl;
	}
};
class Rectangle : public Shape {
private:
	int width, height;
public:
	void setWidth(int w) {
		width = w;
	}
	void setHeight(int h) {
		height = h;
	}
	//	������
	void draw() {
		cout << "Rectangle Draw" << endl;
	}
};
class Circle : public Shape {
private:
	int radius;
public:
	void setRadius(int r) {
		radius = r;
	}
	void draw() {
		cout << "Circle Draw" << endl;
	}
};

class Triangle : public Shape {
private:
	int base, height;
public:
	void draw() {
		cout << "Triangle Draw" << endl;
	}
};

//	��ü�� �Լ��� ������ �����ϴ� ��쿡�� ���� �Լ� ����� �۵�X
//	�����Ϳ� �����ڸ� ���ؼ��� ����
void func(Shape* sp1, Shape& sp2) {
	cout << "�Լ� ���� �Դϴ�." << endl;
	sp1 = new Rectangle();
	sp1->draw();
	sp2.draw();
}

int main() {
	Shape* arrayOfShapes[5];

	arrayOfShapes[0] = new Rectangle();
	arrayOfShapes[1] = new Triangle();
	arrayOfShapes[2] = new Circle();
	for (int i = 0; i < 3; i++) {
		arrayOfShapes[i]->draw();
	}

	func(arrayOfShapes[3], *arrayOfShapes[2]);
}