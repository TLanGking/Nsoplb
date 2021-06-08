#include <iostream>
using namespace std;

int main2() {
	int* p = new int(10);
	cout << *p << endl;
	delete p;

	short* p2 = new short(66);
	cout << *p2 << endl;
	delete p2;

	long* p3 = new long(666);
	cout << *p3 << endl;
	delete p3;

	long long* p4 = new long long(6666666666666666666);
	cout << *p4 << endl;
	delete p4;

	char* p5 = new char('q');
	cout << *p5 << endl;
	delete p5;

	float* p6 = new float(0.000008);
	cout << *p6 << endl;
	delete p6;

	double* p7 = new double(0.000000006);
	cout << *p7 << endl;
	delete p7;

	string* p8 = new string("hello warld");
	cout << *p8 << endl;
	delete p8;

	int* p10 = new int[10]{
		1,2,3,4,5,6,7,8,9,10
	};
	for (int i = 0; i < 10; i++)
	{
		cout << p10[i] << '\t';
	}
	cout << endl;
	delete[] p10;

	char* p11 = new char[11]{
		'h'
	};
	for (int i = 0; i < 11; i++) {
		cout << *(p11 + i) << '\t';
	}
	delete[] p11;

	//char * p9[] = new[] char;

	return 0;
}