#include <iostream>
using namespace std;

class MyClass1
{
public:
	MyClass1()
	{
		cout << "MyClass��Ĭ�Ϲ���" << endl;
	}
	~MyClass1()
	{
		cout << "MyClass����������" << endl;
	}
	void ShowMyClass1()
	{
		cout << this->name << endl;
	}
private:
	string name;
};


int main1() {
	MyClass1* p =  NULL;
	p->~MyClass1();
	//p->ShowMyClass();		//�������
	return 0;
}

