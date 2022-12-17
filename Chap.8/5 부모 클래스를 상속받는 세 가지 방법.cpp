#include<iostream>
using namespace std;

class ParentClass {
private:
	int pvt;
protected:
	int ptd;
public:
	int pub;
};

class ChildClass1 : public ParentClass {
};
class ChildClass2 : protected ParentClass {
};
class ChildClass3 :private ParentClass {
};

int main() {
	ChildClass1 obj1;
	ChildClass2 obj2;
	ChildClass3 obj3;

	//	public
	cout << obj1.pvt << endl;	//	�Ұ���
	cout << obj1.ptd << endl;	//	�Ұ���: y�� protected�� �����ȴ�.
	cout << obj1.pub << endl;	//	����: z�� public���� �����ȴ�.

	//	protected
	cout << obj2.pvt << endl;	//	�Ұ���
	cout << obj2.ptd << endl;	//	�Ұ���: y�� protected�� �����ȴ�.
	cout << obj2.pub << endl;	//	�Ұ���: z�� public���� protected�� ����Ǿ���.

	//	private
	cout << obj3.pvt << endl;	//	�Ұ���
	cout << obj3.ptd << endl;	//	�Ұ���: y�� protected���� private�� ����Ǿ���.
	cout << obj3.pub << endl;	//	�Ұ���: z�� public���� private�� ����Ǿ���.

	//	ChildClass1�� public���� �θ� Ŭ������ ��ӹ޾Ҵ�.
	//	���� ��� Ŭ�������� public���� ����Ǿ��ִ� ����z�� ����� �� �ִ�.
	//	ChildClass2�� protected�� �θ� Ŭ������ ��ӹ޾Ҵ�.
	//	�θ�Ŭ������ �ִ� ������ z�� public���� protected�� ���� ������ ����Ǿ���.
	//	���� ChildClass2�� �ܺο����� ����� �� ����.
	
	//	public ����� �ƴϸ� �� ������ �ʴ´�. ������ ������ �˰� �־�� �Ѵ�.��
	return 0;
}