#include <iostream>
using namespace std;



void func(int& a)
{

	cout << "func(int & a) ";
}

void func(const int& a)
{

	cout << "func(const int & a)";
}

int main4() {

	int a = 666;
	int& b = a;

	a = 6;

	b = 999;
	cout << a << endl;
	cout << b << endl;

	func(a);
	func(14);

	return 0;
}