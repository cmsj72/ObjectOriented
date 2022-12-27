#include<iostream>
using namespace std;

class String {
	char* s;
public:
	String(const char* p) {
		cout << "String() ������" << endl;
		s = new char[strlen(p) + 1];
		strcpy(s, p);
	}
	/*~String() {
		cout << "String() �Ҹ���" << endl;
		delete[] s;
	}*/
	virtual ~String() {
		cout << "String() �Ҹ���" << endl;
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
		cout << "MyString() ������" << endl;
		header = new char[strlen(h) + 1];
		strcpy(header, h);
	}
	~MyString() {
		cout << "MyString() �Ҹ���" << endl;
		delete[] header;
	}
	void display() {
		cout << header;
		String::display();
		cout << header << endl;
	}
};

int main() {
	//	MyString ��ü�� �����Ͽ� String �����ͷ� ����Ų �� ��ü�� �����ϸ�
	//	MyString �Ҹ��ڰ� ȣ����� �ʴ´�.
	//	������ MyString ��ü������ String�����ͷ� ����Ű�� �����Ƿ� �����Ϸ��� String ��ü�� ����
	//	���� ������ String�� �Ҹ��ڸ� ȣ��
	//	String Ŭ������ �Ҹ��ڸ� virtual�� �����ϸ� MyString �Ҹ��ڵ� ȣ��ȴ�.
	String* p = new MyString("----", "Hello World!");
	p->display();
	delete p;
	
	return 0;
}