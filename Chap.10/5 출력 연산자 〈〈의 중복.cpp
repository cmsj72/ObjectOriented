#include<iostream>
using namespace std;

class Vector {
	friend ostream& operator<<(ostream& os, const Vector& v);
};