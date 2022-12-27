#include<iostream>
using namespace std;

class String {
	char* s;
public:
	String(const char* p) {
		cout << "String() 생성자" << endl;
		s = new char[strlen(p) + 1];
		strcpy(s, p);
	}
	/*~String() {
		cout << "String() 소멸자" << endl;
		delete[] s;
	}*/
	virtual ~String() {
		cout << "String() 소멸자" << endl;
		delete[] s;
	}
	virtual void display() {
		cout << s;
	}
};

class MyString : public String {
	char* header;
public:
	MyString(const char* h, const char* p) : String(p) {
		cout << "MyString() 생성자" << endl;
		header = new char[strlen(h) + 1];
		strcpy(header, h);
	}
	~MyString() {
		cout << "MyString() 소멸자" << endl;
		delete[] header;
	}
	void display() {
		cout << header;
		String::display();
		cout << header << endl;
	}
};

int main() {
	//	MyString 객체를 생성하여 String 포인터로 가리킨 후 객체를 삭제하면
	//	MyString 소멸자가 호출되지 않는다.
	//	실제로 MyString 객체이지만 String포인터로 가리키고 있으므로 컴파일러는 String 객체로 생각
	//	따라서 삭제시 String의 소멸자만 호출
	//	String 클래스의 소멸자를 virtual로 선언하면 MyString 소멸자도 호출된다.
	String* p = new MyString("----", "Hello World!");
	p->display();
	delete p;
	
	return 0;
}