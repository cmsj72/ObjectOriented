#include<iostream>
#include<string>
using namespace std;

#pragma region ���� �Լ��� �ʿ伺
//	Shape Ŭ������ draw() �Լ��� ������ ȭ�鿡 �׸��� ��� �Լ��̴�.
//	������ ������ �׸��� ����� �翬�� ������ ���� �ٸ���.
//	���� ������ ������ ���� ���� �ٸ� draw()�� ȣ���ϴ� ���� �ڿ�������.
class Shape2 {
public:
	void draw() {}
};
class Rectangle2 : public Shape2 {
public:
	void draw() {}
};
#pragma endregion

#pragma region �����Լ�
//	�θ� Ŭ������ �����ͷ� ȣ���ϴ��� �ڽ� Ŭ������ �����ǵ� �Լ��� ȣ��ǰ� �Ϸ���
//	�θ� Ŭ������ �Լ��� ���� �Լ��� �����ϸ� �ȴ�.
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
#pragma endregion


int main() {
#pragma region ���� �Լ��� �ʿ伺
	Shape2* ps = new Rectangle2();
	ps->draw();
	//	�����ϸ� Shape�� draw()�� ȣ��ȴ�.
	//	ps�� ���� ����Ű�� ���� Rectangle ��ü�̰� draw()�� ������ �Ǿ� ������ Shape �������̱� ������
	//	Shape�� draw()�� ȣ��ȴ�.
#pragma endregion

#pragma region ���� �Լ�
	//	virtual Ű����� ��� �Լ����� ��� ����, ��� �������� ��� �Ұ���
	//	�θ� Ŭ�������� virtual�� �����ϸ� �ڽ� Ŭ���������� virtual Ű���带 ������� �ʴ��� �ڵ����� ���� �Լ��� �ȴ�.
	//	(�ڽ� Ŭ�������� �������ص� �ڵ����� ���� �Լ��� ������ ���� �Լ���� ���� �и��� �ϱ� ���� virtual�� ���� �ִ� ���� ����.	
	// 
	//	���⼭ �������� ���� �߿��� Ư¡�� �� �� �ִ�. 
	//	���� �Լ��� ����ϸ� ps�� ������ ����Ű�� �ִ� ��ü Ÿ���� Rectangle�̱� ������ Shape�� draw()�� ȣ��Ǵ� ���� �ƴ�
	//	Rectangle�� draw()�� ȣ��ȴ�. ��, ������ ������ ������ ����Ű�� ��ü�� ���� ���� �ٸ� ��� �Լ��� �ڵ������� ���õȴ�.
	//	���� ������ �׸� �� ��� ������ �θ� Ŭ������ Shape�� �����ͷ� ����Ű�� �����͸� ���Ͽ� draw() �Լ��� ȣ���ϸ� ������ ����
	//	���� �ٸ� draw()�� �ڵ������� ���õȴ�.
	Shape* ps = new Rectangle();
	ps->draw();
	delete ps;

	Shape* ps1 = new Circle();
	ps1->draw();
	delete ps1;
	return 0;
#pragma endregion

}
