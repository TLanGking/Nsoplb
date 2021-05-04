#include <iostream>
using namespace std;
#include <deque>

void myPrint(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}
//deque���캯��
void test01()
{
	//Ĭ�Ϲ���
	deque<int> d1;
	//���乹��
	deque<int> d2(d1.begin(), d1.end());
	//n��x�ķ�ʽ����
	deque<int> d3(3, 6);
	//��������
	deque<int> d4(d3);

	myPrint(d1);
	myPrint(d2);
	myPrint(d3);
	myPrint(d4);
}

//deque��ֵ����
void test02()
{
	//�ȺŸ�ֵ
	deque<int> d(3, 6);
	deque<int> d1 = d;
	//assign��ֵ
	deque<int> d2;
	d2.assign(d1.begin(), d1.end());
	deque<int> d3;
	d3.assign(6, 3);

	myPrint(d);
	myPrint(d1);
	myPrint(d2);
	myPrint(d3);

}
//deque��С����
void test03()
{
	deque<int> d(3, 1);
	if (d.empty())
	{
		cout << "����Ϊ��" << endl;
	}
	else
	{
	cout << d.size() << endl;
	}
	d.resize(6);

	myPrint(d);
	d.resize(12, 10);
	myPrint(d);
	
}
//deque �����ɾ��
void test04()
{
	//ͷ�˺�β�� �����ɾ��
	deque<int> d(6, 6);
	/*cout << d.front() << endl;
	cout << d.back() << endl;
	d.push_front(7);
	d.push_back(7);
	cout << d.front() << endl;
	cout << d.back() << endl;
	myPrint(d);
	d.pop_front();
	d.pop_back();
	myPrint(d);*/
	//ָ��λ�ò����ɾ��
	deque<int>d2(3, 3);
	deque<int>::iterator it = d.begin();
	//deque<int>::iterator iit;
	//iit = d.insert(it + 3, 7);
	//myPrint(d);
	//cout << *iit << endl;
	//d.insert(it, 6, 8);
	d.insert(it,d2.begin(), d2.end());
	myPrint(d);
}
// deque ���ݴ�ȡ
void test05()
{
	deque<int> d(6, 6);
	//[]����
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << ' ';
	}
	cout << endl;
	//at()����
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << ' ';
	}
	cout << endl;
	//front��back������λԪ��
}
//


int main()
{
	//����
	//test01();
	//��ֵ
	//test02();
	//��С
	//test03();
	//�����ɾ��
	//test04();
	//���ݴ�ȡ
	test05();
	return 0;
}