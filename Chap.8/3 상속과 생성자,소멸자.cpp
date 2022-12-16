#include<iostream>
#include<string>
using namespace std;

//	상속에서 생성자와 소멸자 호출 순서
//	생성자 : 부모 → 자식
//			자식 클래스의 생성자에서 부모 클래스의 생성자를 호출
//			(특별히 지정하지 않으면 부모 클래스의 기본 생성자 호출)
// 
//	소멸자 : 자식 → 부모

//	부모 클래스의 생성자를 지정하는 방법
//	자식 클래스의 생성자() :  부모 클래스의 생성자()
//	{
// 
//	}

class Shape {
	int x, y;
public:
	Shape() : x(0), y(0){
		cout << "Shape 생성자() " << endl;
	}
	Shape(int xValue, int yValue) : x(xValue), y(yValue) {

	}
	~Shape() {
		cout << "Shape 소멸자() " << endl;
	}
};

class Rectangle : public Shape {
	int width, height;
public:
	Rectangle() : width(0), height(0){
		cout << "Rectangle 생성자()" << endl;
	}
	//	부모 클래스의 생성자 호출
	Rectangle(int x = 0, int y = 0, int w = 0, int h = 0) : Shape(x, y) {
		width = w;
		height = h;
	}
	//	부모 클래스의 생성자 호출 다음에 멤버 초기화 리스트를 붙여도 된다.
	Rectangle(int x = 0, int y = 0, int w = 0, int h = 0) : Shape(x, y), width(w), height(h){}
	~Rectangle() {
		cout << "Rectangle 소멸자()" << endl;
	}
};

int main() {
	Rectangle r();
	return 0;
}