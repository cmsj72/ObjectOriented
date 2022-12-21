#include<iostream>
#include<string>
using namespace std;

#pragma region 가상 함수의 필요성
//	Shape 클래스의 draw() 함수는 도형을 화면에 그리는 멤버 함수이다.
//	각각의 도형을 그리는 방법은 당연히 도형에 따라 다르다.
//	따라서 도형의 종류에 따라 서로 다른 draw()를 호출하는 것이 자연스럽다.
class Shape2 {
public:
	void draw() {}
};
class Rectangle2 : public Shape2 {
public:
	void draw() {}
};
#pragma endregion

#pragma region 가상함수
//	부모 클래스의 포인터로 호출하더라도 자식 클래스의 재정의된 함수가 호출되게 하려면
//	부모 클래스의 함수를 가상 함수로 정의하면 된다.
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
#pragma endregion


int main() {
#pragma region 가상 함수의 필요성
	Shape2* ps = new Rectangle2();
	ps->draw();
	//	실행하면 Shape의 draw()가 호출된다.
	//	ps가 실제 가리키는 것은 Rectangle 객체이고 draw()가 재정의 되어 있지만 Shape 포인터이기 때문에
	//	Shape의 draw()가 호출된다.
#pragma endregion

#pragma region 가상 함수
	//	virtual 키워드는 멤버 함수에만 사용 가능, 멤버 변수에는 사용 불가능
	//	부모 클래스에서 virtual로 정의하면 자식 클래스에서는 virtual 키워드를 사용하지 않더라도 자동으로 가상 함수가 된다.
	//	(자식 클래스에서 재정의해도 자동으로 가상 함수가 되지만 가상 함수라는 것을 분명히 하기 위해 virtual을 적어 주는 것이 좋다.	
	// 
	//	여기서 다형성의 가장 중요한 특징을 알 수 있다. 
	//	가상 함수를 사용하면 ps가 실제로 가리키고 있는 객체 타입이 Rectangle이기 때문에 Shape의 draw()가 호출되는 것이 아닌
	//	Rectangle의 draw()가 호출된다. 즉, 포인터 변수가 실제로 가리키는 객체에 따라 서로 다른 멤버 함수가 자동적으로 선택된다.
	//	따라서 도형을 그릴 때 모든 도형을 부모 클래스인 Shape의 포인터로 가리키고 포인터를 통하여 draw() 함수를 호출하면 도형에 따라
	//	서로 다른 draw()가 자동적으로 선택된다.
	Shape* ps = new Rectangle();
	ps->draw();
	delete ps;

	Shape* ps1 = new Circle();
	ps1->draw();
	delete ps1;
	return 0;
#pragma endregion

}
