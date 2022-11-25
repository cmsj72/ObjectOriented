#include<iostream>
using namespace std;

//	C++에서 구조체는 안에 멤버 함수를 정의할 수도 있다.
//	클래스와 다른점 : 구조체는 접근 지정자가 없으면 구조체의 멤버들은 기본적으로 public이 된다.
struct BankAccount {
	int accountNumber;
	int balance;
	double interest_rate;
	double get_interrest(int days) {
		return (balance * interest_rate) * ((double)days / 365.0);
	}
};

int main() {

}