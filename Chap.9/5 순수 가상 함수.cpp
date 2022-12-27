#include<iostream>
#include<string>
using namespace std;


//	순수 가상 함수 : 헤더만 존재하고 몸체는 없는 함수
//	순수 가상 함수를 하나라도 가지고 있는 클래스를 추상 클래스(abstract class)라 한다.
//	추상 클래스로는 객체를 생성할 수 없다.
//	추상 클래스는 추상적인 개념을 나타내거나 클래스와 클래스 사이의 인터페이스를 나타내는 용도로 사용
//	추상 클래스는 멤버 함수의 원형만을 정의, 그 구현은 자식 클래스에서
//	추상 클래스를 상속받는 자식 클래스는 반드시 가상 함수를 구현해야 한다.
class Shape {
protected:
	int x, y;
public:
	void setOrigin(int x, int y) {
		this->x = x;
		this->y = y;
	}

	virtual void draw() = 0; //	<------ 순수 가상 함수 정의
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


//	Shape는 추상 클래스이기 때문에 객체 생성할 수 없다.
//	하지만 포인터 변수는 생성할 수 있고, 이 포인터 변수를 통하여 자식 클래스의 객체를 가리킬 수 있다.
int main() {
	Shape* ps = new Rectangle();
	ps->draw();
	delete ps;

	return 0;
}