#include<iostream>
#include<string>
using namespace std;

//	this�� �ڽ��� ����Ű�� ��ü ������
//	�����Ϸ��� ���� �ڵ����� ����, ��� ������ ����� ���� �Ϲ������� �����Ϸ��� this-> �� �տ� ����
//	��� ������ �̸��� ��� �Լ��� �̸��� ������ ��� �����ϱ� ���� ���� ���
//	���� �Լ��� �Ű� ������ �ڱ� �ڽ��� �Ѱܾ� �� �ʿ䰡 �ִ� ��쳪 �ڱ� �ڽ��� �Լ��� ��ȯ������ ��ȯ�� �� ���
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
		cout << "�г�: " << grade << " �̸�: " << name << " ��ȭ��ȣ: " << phoneNumber << endl;
	}

	void isHigher(Student* p) {
		if (this->getGrade() > p->getGrade())
			this->print();
		else
			p->print();
		cout << "�� �г��� �� ����" << endl;
	}
};

int main() {
	Student s1("��ö��", "01012345678", 1);
	Student s2("������", "01098765432", 3);
	s1.isHigher(&s2);
	return 0;
}