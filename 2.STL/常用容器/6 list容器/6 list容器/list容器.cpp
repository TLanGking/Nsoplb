#include <iostream>
using namespace std;
#include <list>
#include <algorithm>

class myPrint
{
public:
	void operator()(int x)
	{
		cout << x << ' ';
	}
};
//list构造函数
void test01()
{
	//默认构造
	list<int> t1;
	//n个x的方式构造
	list<int> t2(3, 1);
	//区间构造
	list<int> t3(t2.begin(), t2.end());
	//拷贝构造
	list<int> t4(t3);

	for_each(t2.begin(), t2.end(), myPrint());
}

//list赋值和交换
void test02()
{
	//赋值assign,等号赋值
	list<int> t1(6, 6);
	list<int> t2;
	//t2 = t1;		//等号赋值
	//t2.assign(t1.begin(), t1.end());		//区间复制
	t2.assign(3, 6);			//n个x的方式赋值
	//for_each(t2.begin(), t2.end(), myPrint());
	//交换

	cout << "交换前" << endl;
	for_each(t1.begin(), t1.end(), myPrint());
	cout << endl;
	for_each(t2.begin(), t2.end(), myPrint());
	cout << endl;
	t1.swap(t2);

	cout << "交换后" << endl;
	for_each(t1.begin(), t1.end(), myPrint());
	cout << endl;
	for_each(t2.begin(), t2.end(), myPrint());
	cout << endl;
}
//list 大小操作
void test03()
{
	list<int> t1(3, 1);
	cout << t1.size() << endl;		//大小
	list<int> t2(4, 2);
	cout << t2.empty() << endl;		//判断是否为空
	//重新指定大小
	t1.resize(6);
	t2.resize(6, 6);

	for_each(t1.begin(), t1.end(), myPrint());
	cout << endl;
	for_each(t2.begin(), t2.end(), myPrint());
	cout << endl;
}
//list 插入和删除
/*
push_back(elem);//在容器尾部加入一个元素
pop_back();//删除容器中最后一个元素
push_front(elem);//在容器开头插入一个元素
pop_front();//从容器开头移除第一个元素

insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。

clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
remove(elem);//删除容器中所有与elem值匹配的元素。
*/
void test04()
{
	list<int> t;
	//首尾 插入和删除
	t.push_back(6);		//尾插
	t.push_front(6);		//头插
	t.pop_back();		//	伪善
	t.pop_front();		//头山

	//插入
	list<int> l(6, 6);
	list<int>::iterator it = t.begin();
	t.insert(it, 6);			//指定位置插入元素
	t.insert(it, 3, 2);			//指定位置插入n个x
	t.insert(it, l.begin(), l.end());		//指定位置插入区间

	//删除
	//t.clear();		//清空容器
	//t.erase(t.begin(), t.end());		//删除区间内元素，返回下个元素的位置
	//t.erase(t.begin());				//删除指定位置的元素，返回下个元素的位置

	
	//*remove删除
	t.remove(6);			//删除容器内所有6
	for_each(t.begin(), t.end(), myPrint());
}
//list 数据存取
void test05()
{
	//只能访问首尾元素
	list<int> t(3, 1);
	cout << t.back() << endl;
	cout << t.front() << endl;
}
//list 反转和排序
class myCompare
{
public:
	bool operator()(int x, int y)
	{
		return x > y;
	}
};

void test06()
{
	//反转reserve
	list<int> t;
	t.push_back(1);
	t.push_back(7);
	t.push_back(3);
	/*for_each(t.begin(), t.end(), myPrint());
	t.reverse();
	for_each(t.begin(), t.end(), myPrint());*/
	//排序
	//t.sort();	///默认升序
	t.sort(myCompare());
	for_each(t.begin(), t.end(), myPrint());

}


int main()
{
	//构造
	//test01();
	//赋值和交换
	//test02();
	//大小
	//test03();
	//插入 和删除
	//test04();
	//数据存取
	//test05();
	//反转和排序
	test06();
	return 0;
}