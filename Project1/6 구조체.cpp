#include<iostream>
using namespace std;

//	C++���� ����ü�� �ȿ� ��� �Լ��� ������ ���� �ִ�.
//	Ŭ������ �ٸ��� : ����ü�� ���� �����ڰ� ������ ����ü�� ������� �⺻������ public�� �ȴ�.
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