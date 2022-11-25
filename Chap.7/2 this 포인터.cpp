#include<iostream>
#include<string>
using namespace std;

//	this는 자신을 가리키는 객체 포인터
//	컴파일러에 의해 자동으로 생성, 멤버 변수를 사용할 때는 암묵적으로 컴파일러는 this-> 를 앞에 붙임
//	멤버 변수의 이름과 멤버 함수의 이름이 동일한 경우 구분하기 위해 자주 사용
//	가끔 함수의 매개 변수로 자기 자신을 넘겨야 할 필요가 있는 경우나 자기 자신을 함수의 반환값으로 반환할 때 사용
class Student {
	string name;
	string phoneNumber;
	int grade;
public:
	Student(string n, string pN, int g = 1) : name(n), phoneNumber(pN), grade(g){}
	int getGrade() {
		return grade;
	}
	void setGrade(int grade) {
		if (1 <= grade && grade <= 4) {
			this->grade = grade;
		}
		else {
			this->grade = 1;
		}
	}
	void print() {
		cout << "학년: " << grade << " 이름: " << name << " 전화번호: " << phoneNumber << endl;
	}

	void isHigher(Student* p) {
		if (this->getGrade() > p->getGrade())
			this->print();
		else
			p->print();
		cout << "의 학년이 더 높음" << endl;
	}
};

int main() {
	Student s1("박철수", "01012345678", 1);
	Student s2("곽두팔", "01098765432", 3);
	s1.isHigher(&s2);
	return 0;
}