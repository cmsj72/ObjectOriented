#include<iostream>
#include<string>
using namespace std;

//	Ŭ���� �ȿ� private�� ����� ������� ���� �����͸� �����ϰ� �ְ�,
//	�ܺο����� �̵� ���� �����Ϳ� ������ �� ����.
//	������ � ��쿡�� Ư���� Ŭ������ �Լ��� �ڽ��� ���� �����Ϳ� ������ �� �ֵ��� ����� ���� ȿ����
//	������� ���� �Լ��� ���� �ְ� � Ŭ������ ��� �Լ��� ���� �ְ� ��ü Ŭ������ ���� �ִ�.
//	�ϳ��� Ŭ������ ������� �����ϸ� �� Ŭ������ ��� ��� �Լ��� ���� �����͸� ������ �� �ִ�.

#pragma region ����1
class Company {
private:
	int sales, profit;
	friend void sub(Company& c);//	������ ����
public:
	Company() : sales(0), profit(0) {}
};

void sub(Company& c) {
	cout << c.profit << endl;
}
#pragma endregion

#pragma region ����2
class Employee {
	int salary;
	friend class Manager;
};
class Manager {
	void raiseSalary(Employee& e, int amount) {
		//	friend�� ���������ν� salary ���� ����
		//	Employee Ŭ������ Manager�� ������� �����Ͽ����Ƿ� 
		//	Employee�� ��� ����� Manager�� ��� �Լ����� ����� �㰡
		//	friend�� ���ٸ� ����
		e.salary += amount;
	}
};
#pragma endregion

#pragma region ����3
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

#pragma region ����4
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

//	��� �Լ��� ������ �Լ��� ����
//	�Լ��� �����ϴ� �۾��� ���� �ϳ��� ��ü���� ���õȴٸ� ��� �Լ��� ����
//	���Լ��� �����ϴ� �۾��� �� �� �̻��� ��ü�� ���õȴٸ� ������ �Լ��� ����
//	���Լ��� �����ϴ� �۾��� �� �� �̻��� ��ü�� ���õǴ��� �����ڿ� �����ڸ� ����ϸ�
//	
//	�ضȰ��� ���� ���������� ȿ������ �����ϸ� ������ �Լ��ε� ������ �� �ִ� ��
//	�������� �Լ��� ������ Ŭ������ ��ü ������ �ߟG�� ��Ģ�� ���� ������ ���ʶ߸��� ���̴�.
//	 ���� �ʿ��� ��쿡�� ���������� ���

int main() {
	Company c1;
	sub(c1);

	Date d1(1960, 5, 23), d2(2002, 7, 23);

	Complex cp1(1, 2), cp2(3, 4);
	Complex cp3 = add(cp1, cp2);
	cp3.Output();
	return 0;
}