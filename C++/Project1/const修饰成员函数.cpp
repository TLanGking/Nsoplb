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
	//��Ա���������const��ʾ�ó�Ա������  ������
	//������  �����޸� ��Ա������ֵ
private:
	string name;
	//�����Ա��������mutable����  ����  ������  ���˿����޸�
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
	//this->name = str;		//�������  �����޸�
	this->NAME = str2;		//��ȷ   �ó�Ա����Ϊmutable���α���
}

int main2()
{

	//������	��const���εĶ���
	const MyClass2 MY1;

	MY1.ChangeName("666", "666666");
	//������ֻ�� ���� ������ 


	return 0;
}