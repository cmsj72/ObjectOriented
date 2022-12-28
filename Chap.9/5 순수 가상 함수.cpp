#include<iostream>
#include<string>
using namespace std;


//	���� ���� �Լ� : ����� �����ϰ� ��ü�� ���� �Լ�
//	���� ���� �Լ��� �ϳ��� ������ �ִ� Ŭ������ �߻� Ŭ����(abstract class)�� �Ѵ�.
//	�߻� Ŭ�����δ� ��ü�� ������ �� ����.
//	�߻� Ŭ������ �߻����� ������ ��Ÿ���ų� Ŭ������ Ŭ���� ������ �������̽��� ��Ÿ���� �뵵�� ���
//	�߻� Ŭ������ ��� �Լ��� �������� ����, �� ������ �ڽ� Ŭ��������
//	�߻� Ŭ������ ��ӹ޴� �ڽ� Ŭ������ �ݵ�� ���� �Լ��� �����ؾ� �Ѵ�.
class Shape {
protected:
	int x, y;
public:
	void setOrigin(int x, int y) {
		this->x = x;
		this->y = y;
	}

	virtual void draw() = 0; //	<------ ���� ���� �Լ� ����
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
	//	�߻� �޼ҵ带 ������ ���� ������ ���� �߻�(�߻� Ŭ������ ��ӹ޴� �ڽ� Ŭ������ �ݵ�� �߻� �޼ҵ带 ������ �ؾ���)
	void draw() {
		cout << "Rectangle Draw" << endl;
	}
};

#pragma region ����1
//	�߻� Ŭ������ �߻����� ������ ǥ���� �� �ִ�.
class Animal {
	virtual void move() = 0;
	virtual void eat() = 0;
	virtual void speak() = 0;
};
class Lion : public Animal {
	void move() {
		cout << "������ ����" << endl;
	}
	void eat() {
		cout << "������ eat" << endl;
	}
	void speak() {
		cout << "������ ����ũ" << endl;
	}
};
#pragma endregion

#pragma region ����2
//	�߻� Ŭ������ ��ü�� ���̿� ��ȣ �ۿ��ϱ� ���� �������̽��� �����ϴ� �뵵�� ����� �� �ִ�.
class RemoteControl {
	virtual void turnOn() = 0;
	virtual void turnOff() = 0;
};
class Television : public RemoteControl {
	void turnOn() {};
	void turnOff() {};
};
#pragma endregion




//	Shape�� �߻� Ŭ�����̱� ������ ��ü ������ �� ����.
//	������ ������ ������ ������ �� �ְ�, �� ������ ������ ���Ͽ� �ڽ� Ŭ������ ��ü�� ����ų �� �ִ�.
int main() {
	Shape* ps = new Rectangle();
	ps->draw();
	delete ps;

	return 0;
}