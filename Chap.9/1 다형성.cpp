#include<iostream>
using namespace std;

//	������(polymorphism)
//	��ü���� Ÿ���� �ٸ��� �Ȱ��� �޽����� ���޵Ǵ��� ���� �ٸ� ������ �ϴ°�
//	�߿��� ���� �޼����� ������ �������� ��ü�� � Ÿ������ �� �ʿ䰡 ���ٴ� ��
//	���� �ð��� ��ü�� Ÿ�Կ� ���� �ڵ������� ������ ������ ����

#pragma region ���� ����ȯ(up-casting)
class Animal {};
class Dog : public Animal {};
class Cat : public Animal {};
#pragma endregion

#pragma region ���� ����ȯ(down-casting)
class BaseClass {};
class DerivedClass : public BaseClass {};
#pragma endregion



class Shape {
protected:
	int x, y;
public:
	void draw() {
		cout << "shape Draw" << endl;
	}
	void setOrigin(int x, int y) {
		this->x = x;
		this->y = y;
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

#pragma region �Լ��� �Ű� ����
//	����ȯ ��Ģ�� �Լ� ȣ�� �ÿ��� �״�� ����ȴ�.
	//	�Լ��� �Ű� ������ �ڽ� Ŭ�������ٴ� �θ� Ŭ���� Ÿ������ �����ϴ� ���� ����.
	//	���� ��� ������ ���� �̵��ϴ� �Լ��� move()�� �����ϴ� ���, Rectangle�� Circle�� �޴� �Լ��� ������ �ۼ��� ���� �ƴ϶�
	//	������ ���� �Լ��� �Ű� ������ Shape Ŭ���� ������ �����ϸ� ��� ������ ������ ���� �Ű� ������ ���� �� �ִ�.
void move(Shape& s, int sx, int sy) {
	s.setOrigin(sx, sy);
}
#pragma endregion


int main() {
#pragma region ���� ����ȯ(up-casting)
	//	�������� ��ü �����͸� ���� �̷����
	Dog dog;
	Animal* pa;
	pa = &dog;
	//	�ڽ� Ŭ���� ��ü�� �θ� Ŭ���� ��ü�� �����ϰ� �ֱ� ������ 
	//	�ڽ� Ŭ������ �θ� Ŭ���� ��ü �̱⵵ �ϴ�.
	//	���� �θ� Ŭ���� �����ʹ� �ڽ� Ŭ���� ��ü�� ����ų �� �ִ�.
	//	�̷��� ������ Ÿ���� ��ȯ�� ���� ����ȯ(up-casting)�̶�� �Ѵ�.
	//	�����̶� �ϴ� ������ ��ü �����Ͱ� ��� ���������� ����, �� �θ� Ŭ���� ���� ����Ų�ٴ� �ǹ�
	//	���� ����ȯ(��ĳ����)�� �ϸ� �ڽ� Ŭ���� �߿��� �θ� Ŭ�����κ��� ��ӹ��� �κи��� �����͸� ���� ��밡��, �������� �Ұ���
#pragma endregion

#pragma region ���� ����ȯ(down-casting)
	//	���� ����ȯ�� �ݴ�
	//	�θ� Ŭ������ ����Ű�� �����Ͱ� �ڽ� Ŭ������ ����Ű���� ����ȯ �ϴ� ��
	//	�����̶� �ϴ� ������ ��� ���������� �Ʒ� ����, �� �ڽ� Ŭ������ ����Ű�� ����
	//	���� ����ȯ �ÿ��� ����ȯ �����ڸ� �տ� �����ؾ���
	BaseClass* pb = new DerivedClass();
	DerivedClass* pd = (DerivedClass*)pb;

	//	�߸��� ���� ����ȯ
	BaseClass* pb = new BaseClass();
	DerivedClass* pd = (DerivedClass*)pb;
	//	pb�� ������ ����Ű�� ��ü�� BaseClass Ÿ���̴�.
	//	�̰��� DerivedClass Ÿ������ ���� ����ȯ�� �ϰ� �Ǹ� BaseClass���� ���� ����� ������ ���� �ִ�.(�� �� �����߻�)
	//	�̰��� �����ϱ� ���ؼ��� dynamic_cast��� ������ ����ȯ �����ڸ� ����ϴ� ���� ����(�ڿ��� �н�)
#pragma endregion

#pragma region �Լ��� �Ű� ����	
	Rectangle r;
	move(r);
	
	Circle c;
	move(c);
	return 0;
#pragma endregion


	Shape* ps = new Rectangle();	//	���� ����ȯ
	ps->setOrigin(10, 10);
	ps->draw();
	//ps->setWidth(100);	//	�ڽ� Ŭ������ ����� ����̱� ������ ���� �Ұ���
	((Rectangle*)ps)->setWidth(100);	// ���� ����ȯ
	delete ps;
}