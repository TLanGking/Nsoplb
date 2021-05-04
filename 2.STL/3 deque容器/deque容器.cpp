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
//deque构造函数
void test01()
{
	//默认构造
	deque<int> d1;
	//区间构造
	deque<int> d2(d1.begin(), d1.end());
	//n个x的方式构造
	deque<int> d3(3, 6);
	//拷贝构造
	deque<int> d4(d3);

	myPrint(d1);
	myPrint(d2);
	myPrint(d3);
	myPrint(d4);
}

//deque赋值操作
void test02()
{
	//等号赋值
	deque<int> d(3, 6);
	deque<int> d1 = d;
	//assign赋值
	deque<int> d2;
	d2.assign(d1.begin(), d1.end());
	deque<int> d3;
	d3.assign(6, 3);

	myPrint(d);
	myPrint(d1);
	myPrint(d2);
	myPrint(d3);

}
//deque大小操作
void test03()
{
	deque<int> d(3, 1);
	if (d.empty())
	{
		cout << "容器为空" << endl;
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
//deque 插入和删除
void test04()
{
	//头端和尾端 插入和删除
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
	//指定位置插入和删除
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
// deque 数据存取
void test05()
{
	deque<int> d(6, 6);
	//[]访问
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << ' ';
	}
	cout << endl;
	//at()访问
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << ' ';
	}
	cout << endl;
	//front，back访问首位元素
}
//


int main()
{
	//构造
	//test01();
	//赋值
	//test02();
	//大小
	//test03();
	//插入和删除
	//test04();
	//数据存取
	test05();
	return 0;
}