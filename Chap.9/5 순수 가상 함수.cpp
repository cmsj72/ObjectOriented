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
	void draw() {
		cout << "Rectangle Draw" << endl;
	}
};


//	Shape�� �߻� Ŭ�����̱� ������ ��ü ������ �� ����.
//	������ ������ ������ ������ �� �ְ�, �� ������ ������ ���Ͽ� �ڽ� Ŭ������ ��ü�� ����ų �� �ִ�.
int main() {
	Shape* ps = new Rectangle();
	ps->draw();
	delete ps;

	return 0;
}