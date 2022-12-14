#include<iostream>
using namespace std;

class Complex {
private:
	double real;
	double imag;

public:
	Complex();
	Complex(double a, double b);
	~Complex();

	double getReal();
	double getImag();
	Complex add(const Complex& c);
	void print();
};

Complex::Complex()
{
	real = 0;
	imag = 0;
}

Complex::Complex(double a, double b)
{
	real = a;
	imag = b;
}

Complex::~Complex()
{
}

double Complex::getReal()
{
	return(real);
}

double Complex::getImag()
{
	return(imag);
}

Complex Complex::add(const Complex& c)
{
	Complex temp;
	temp.real = this->real + c.real;
	temp.imag = this->imag + c.imag;

	return(temp);
}

void Complex::print()
{
	cout << real << " + " << imag << "i" << endl;
}

int main() {
	Complex x(2, 3), y(4, 6), z;

	cout << "첫 번째 복소수 x: ";
	x.print();

	cout << "두 번째 복소수 y: ";
	y.print();

	z = x.add(y);

	cout << "z = x + y = ";
	z.print();

	return 0;
}