#include <iostream>
using namespace std;


class MyClass2
{
public:
	MyClass2()
	{

	}
	MyClass2(string str,string str2);
	~MyClass2();
	void ChangeName (string str, string str2)const;
	//成员函数后面加const表示该成员函数是  常函数
	//常函数  不可修改 成员变量的值
private:
	string name;
	//如果成员函数加上mutable修饰  则在  长函数  中人可以修改
	mutable string NAME;
};

MyClass2::MyClass2(string str, string str2)
{
	this->name = str;
	this->NAME = str2;
}

MyClass2::~MyClass2()
{
}

void MyClass2::ChangeName(string str, string str2) const
{
	//this->name = str;		//错误操作  不可修改
	this->NAME = str2;		//正确   该成员变量为mutable修饰变量
}

int main2()
{

	//常对象	用const修饰的对象
	const MyClass2 MY1;

	MY1.ChangeName("666", "666666");
	//常对象只能 调用 常函数 


	return 0;
}