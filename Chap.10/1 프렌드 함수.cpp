#include<iostream>
#include<string>
using namespace std;

//	클래스 안에 private로 선언된 멤버들은 내부 데이터를 저장하고 있고,
//	외부에서는 이들 내부 데이터에 접근할 수 없다.
//	하지만 어떤 경우에는 특정한 클래스나 함수가 자신의 내부 데이터에 접근할 수 있도록 만드는 것이 효율적
//	프렌드는 전역 함수일 수도 있고 어떤 클래스의 멤버 함수일 수도 있고 전체 클래스일 수도 있다.
//	하나의 클래스를 프렌드로 지정하면 그 클래스의 모든 멤버 함수는 내부 데이터를 참조할 수 있다.

#pragma region 예제1
class Company {
private:
	int sales, profit;
	friend void sub(Company& c);//	프렌드 선언
public:
	Company() : sales(0), profit(0) {}
};

void sub(Company& c) {
	cout << c.profit << endl;
}
#pragma endregion

#pragma region 예제2
class Employee {
	int salary;
	friend class Manager;
};
class Manager {
	void raiseSalary(Employee& e, int amount) {
		//	friend를 지정함으로써 salary 참조 가능
		//	Employee 클래스가 Manager를 프렌드로 지정하였으므로 
		//	Employee의 모든 멤버는 Manager의 모든 함수에게 사용이 허가
		//	friend가 없다면 오류
		e.salary += amount;
	}
};
#pragma endregion

#pragma region 예제3
class Date {
	friend bool equals(Date d1, Date d2);
private:
	int year, month, day;
public:
	Date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
};
bool equals(Date d1, Date d2) {
	return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
}
#pragma endregion

#pragma region 예제4
class Complex {
private:
	double re, im;
public:
	friend Complex add(Complex a1, Complex a2);
	Complex(double r, double i) { re = r; im = i; }
	Complex(double r) { re = r; im = 0; }
	Complex() { re = im = 0; }
	void Output() {
		cout << re << " + " << im << "i" << endl;
	}
};

Complex add(Complex a1, Complex a2) {
	return Complex(a1.re + a2.re, a1.im + a2.im);
}
#pragma endregion

//	멤버 함수와 프렌드 함수의 선택
//	함수가 수행하는 작업이 오직 하나의 객체에만 관련된다면 멤버 함수로 정의
//	→함수가 수행하는 작업이 두 개 이상의 객체에 관련된다면 프렌드 함수로 정의
//	→함수가 수행하는 작업이 두 개 이상의 객체에 관련되더라도 접근자와 설정자를 사용하면
//	
//	※똑같이 수행 가능하지만 효율성을 생각하면 프렌드 함수로도 정의할 수 있는 것
//	※프렌드 함수나 프렌드 클래스는 객체 지향의 중욯나 원칙인 정보 은닉을 무너뜨리는 것이다.
//	 따라서 필요한 경우에만 선별적으로 사용

int main() {
	Company c1;
	sub(c1);

	Date d1(1960, 5, 23), d2(2002, 7, 23);

	Complex cp1(1, 2), cp2(3, 4);
	Complex cp3 = add(cp1, cp2);
	cp3.Output();
	return 0;
}