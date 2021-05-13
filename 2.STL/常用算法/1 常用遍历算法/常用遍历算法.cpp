//���ñ����㷨
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class MyClass
{
public:
	MyClass()
	{

	}
	MyClass(string name,int score)
	{
		this->m_name = name;
		this->m_score = score;
	}
	MyClass(const MyClass& m)
	{
		this->m_name = m.m_name;
		this->m_score = m.m_score;
	}
	string m_name;
	int m_score;
};
class myPrint
{
public:
	void operator()(const MyClass& m)
	{
		cout << m.m_name << "�ĵȼ�Ϊ" << m.m_score << endl;
	}
};

//for_each
void test01()
{
	vector<MyClass> v;
	MyClass m1("Ӣ������", 100);
	MyClass m2("�����Գ�", 5);
	MyClass m3("ʹ���ٻ�", 30);

	v.push_back(m1);
	v.push_back(m2);
	v.push_back(m3);
	for_each(v.begin(),v.end(),myPrint() );
}

class mytrans
{
public:
	MyClass& operator()(MyClass& m)
	{
		return m;
	}
};
//transform
void test02()
{
	vector<MyClass> v;
	MyClass m1("Ӣ������", 100);
	MyClass m2("�����Գ�", 5);
	MyClass m3("ʹ���ٻ�", 30);
	v.push_back(m1);
	v.push_back(m2);
	v.push_back(m3);
	
	vector<MyClass> v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(), mytrans());

	for_each(v2.begin(), v2.end(), myPrint());
}

int main()
{
	//for_each
	//test01();
	//transform
	test02();
	return 0;
}