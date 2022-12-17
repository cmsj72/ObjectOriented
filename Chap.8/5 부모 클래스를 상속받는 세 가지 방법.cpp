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
	cout << obj1.pvt << endl;	//	불가능
	cout << obj1.ptd << endl;	//	불가능: y는 protected로 유지된다.
	cout << obj1.pub << endl;	//	가능: z는 public으로 유지된다.

	//	protected
	cout << obj2.pvt << endl;	//	불가능
	cout << obj2.ptd << endl;	//	불가능: y는 protected로 유지된다.
	cout << obj2.pub << endl;	//	불가능: z는 public에서 protected로 변경되었다.

	//	private
	cout << obj3.pvt << endl;	//	불가능
	cout << obj3.ptd << endl;	//	불가능: y는 protected에서 private로 변경되었다.
	cout << obj3.pub << endl;	//	불가능: z는 public에서 private로 변경되었다.

	//	ChildClass1은 public으로 부모 클래스를 상속받았다.
	//	따라서 브모 클래스에서 public으로 선언되어있던 변수z를 사용할 수 있다.
	//	ChildClass2는 protected로 부모 클래스를 상속받았다.
	//	부모클래스에 있던 변수인 z는 public에서 protected로 접근 권한이 변경되었다.
	//	따라서 ChildClass2의 외부에서는 사용할 수 없다.
	
	//	public 상속이 아니면 잘 사용되지 않는다. 하지만 개념은 알고 있어야 한다.ㅉ
	return 0;
}