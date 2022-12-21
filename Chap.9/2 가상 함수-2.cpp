#include<iostream>
#include<string>
using namespace std;

#pragma region 동적 바인딩
//	함수 호출을 함수의 몸체와 연결하는 것을 바인딩(binding)이라 한다.
//	정적 바인딩(static binding) : 컴파일 단계에서 모든 바인딩이 완료되는 것
//	동적 바인딩(dynamic binding) : 바인딩이 실행 시까지 연기되고 실행 시간에 호출되는 함수(지연 바인딩, late binding)

//	동적 바인딩을 사용하면 객체 지향의 중요한 특징 중의 하나인 다형성을 구현할 수 있다
//	C++에서는 가상 함수가 아니면 모든 함수가 정적 바인딩으로 호출된다.
//	정적 바인딩은 호출 속도가 빠르지만 호출 함수가 컴파일 단계에서 결정되므로 유연성은 떨어진다.
//	가상 함수는 동적 바인딩으로 호출된다.
//	동적 바인딩은 테이블을 사용하여 실제 호출되는 함수를 결정하여야 하므로 처리 속도가 늦어진다.
//	그렇지만 객체의 실제 타입에 맞는 동작을 할 수 있다.
#pragma endregion


class Shape {
protected:
	int x, y;
public:
	void setOrigin(int x, int y) {
		this->x = x;
		this->y = y;
	}
	//	가상 함수 정의
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
	//	재정의
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

//	객체를 함수에 값으로 전달하는 경우에는 가상 함수 기능이 작동X
//	포인터와 참조자를 통해서만 가능
void func(Shape* sp1, Shape& sp2) {
	cout << "함수 내부 입니다." << endl;
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