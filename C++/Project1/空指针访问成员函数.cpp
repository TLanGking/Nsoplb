#include <iostream>
using namespace std;

class MyClass1
{
public:
	MyClass1()
	{
		cout << "MyClass的默认构造" << endl;
	}
	~MyClass1()
	{
		cout << "MyClass的析构函数" << endl;
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
	//p->ShowMyClass();		//错误操作
	return 0;
}

