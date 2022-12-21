#include<iostream>
using namespace std;

//	다형성(polymorphism)
//	객체들의 타입이 다르면 똑같은 메시지가 전달되더라도 서로 다른 동작을 하는것
//	중요한 것은 메세지를 보내는 측에서는 객체가 어떤 타입인지 알 필요가 없다는 점
//	실행 시간에 객체의 타입에 따라서 자동적으로 적합한 동작이 결정

#pragma region 상향 형변환(up-casting)
class Animal {};
class Dog : public Animal {};
class Cat : public Animal {};
#pragma endregion

#pragma region 하향 형변환(down-casting)
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

#pragma region 함수의 매개 변수
//	형변환 규칙은 함수 호출 시에도 그대로 적용된다.
	//	함수의 매개 변수는 자식 클래스보다는 부모 클래스 타입으로 선언하는 것이 좋다.
	//	예를 들어 도형을 평행 이동하는 함수를 move()로 구현하는 경우, Rectangle과 Circle을 받는 함수를 별도로 작성할 것이 아니라
	//	다음과 같이 함수의 매개 변수를 Shape 클래스 참조로 정의하면 모든 종류의 도형을 전부 매개 변수로 받을 수 있다.
void move(Shape& s, int sx, int sy) {
	s.setOrigin(sx, sy);
}
#pragma endregion


int main() {
#pragma region 상향 형변환(up-casting)
	//	다형성은 객체 포인터를 통해 이루어짐
	Dog dog;
	Animal* pa;
	pa = &dog;
	//	자식 클래스 객체는 부모 클래스 객체를 포함하고 있기 때문에 
	//	자식 클래스는 부모 클래스 객체 이기도 하다.
	//	따라서 부모 클래스 포인터는 자식 클래스 객체를 가리킬 수 있다.
	//	이러한 포인터 타입의 변환을 상향 형변환(up-casting)이라고도 한다.
	//	상향이라 하는 이유는 객체 포인터가 상속 계층도에서 위쪽, 즉 부모 클래스 쪽을 가리킨다는 의미
	//	상향 형변환(업캐스팅)을 하면 자식 클래스 중에서 부모 클래스로부터 상속받은 부분만을 포인터를 통해 사용가능, 나머지는 불가능
#pragma endregion

#pragma region 하향 형변환(down-casting)
	//	상향 형변환의 반대
	//	부모 클래스를 가리키는 포인터가 자식 클래스를 가리키도록 형변환 하는 것
	//	하향이라 하는 이유는 상속 계층도에서 아래 방향, 즉 자식 클래스를 가리키기 때문
	//	하향 형변환 시에는 형변환 연산자를 앞에 지정해야함
	BaseClass* pb = new DerivedClass();
	DerivedClass* pd = (DerivedClass*)pb;

	//	잘못된 하향 형변환
	BaseClass* pb = new BaseClass();
	DerivedClass* pd = (DerivedClass*)pb;
	//	pb가 실제로 가리키는 객체는 BaseClass 타입이다.
	//	이것을 DerivedClass 타입으로 하향 형변환을 하게 되면 BaseClass에는 없는 멤버를 참조할 수도 있다.(이 때 오류발생)
	//	이것을 방지하기 위해서는 dynamic_cast라는 진보된 형변환 연산자를 사용하는 것이 좋다(뒤에서 학습)
#pragma endregion

#pragma region 함수의 매개 변수	
	Rectangle r;
	move(r);
	
	Circle c;
	move(c);
	return 0;
#pragma endregion


	Shape* ps = new Rectangle();	//	상향 형변환
	ps->setOrigin(10, 10);
	ps->draw();
	//ps->setWidth(100);	//	자식 클래스에 선언된 멤버이기 때문에 참조 불가능
	((Rectangle*)ps)->setWidth(100);	// 하향 형변환
	delete ps;
}