#include <iostream>
using namespace std;
#include <vector>			//使用vector容器需要包含头文件
#include <algorithm>

class myPrint
{
public:
	void operator()(char c)
	{
		cout << (int)c << ' ';
	}
	void operator()(int c)
	{
		cout << (int)c << ' ';
	}
};


//vector构造函数
/*
vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end()); //将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem); //构造函数将n个elem拷贝给本身。
vector(const vector &vec); //拷贝构造函数。
*/

void myForeach(const vector<int>& v)
{
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	vector<int> v1;								//1.默认构造
	vector<int> v2(v1.begin(), v1.end());		//2.将区间元素拷贝给自身
	vector<int> v3(10, 6);						//3.用n个x初始化容器
	vector<int> v4(v3);							//4.拷贝构造

	//遍历
	myForeach(v1);
	myForeach(v2);
	myForeach(v3);
	myForeach(v4);
	
}
//vector赋值操作
void test02()
{	
	vector<int> v1;								//1.默认构造
	vector<int> v2(v1.begin(), v1.end());		//2.将区间元素拷贝给自身
	vector<int> v3(10, 6);						//3.用n个x初始化容器
	vector<int> v4(v3);							//4.拷贝构造
	//1.operator=赋值
	v1 = v3;									//等号赋值
	//myForeach(v1);
	//2.assign成员函数赋值
	//v2.assign(v4);		//错误！！！
	v2.assign(v4.begin(), v4.end());		//区间赋值
	v2.assign(6, 6);						//n个x赋值
	myForeach(v2);
}
//vector容量和大小
/*
empty(); //判断容器是否为空

capacity(); //容器的容量

size(); //返回容器中元素的个数

resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。

​ //如果容器变短，则末尾超出容器长度的元素被删除。

resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。

​ //如果容器变短，则末尾超出容器长度的元素被删除
*/
void test03()
{
	//empty()判断容器是否为空
	vector<int> v1;
	//cout << v1.empty() << endl;		//如果容器为空返回真
	
	//capacity()获取容器容量
	//cout << v1.capacity() << endl;
	//size()获取容器大小（容器元素个数）
	vector<char> v2(10, '?');
	cout << v2.size() << endl;
	//resize()重新制定大小，会丢弃多于元素，元素不足默认用0填充
	v2.resize(20);
	for_each(v2.begin(), v2.end(), myPrint());
}
//vector插入和删除
/*
push_back(ele); //尾部插入元素ele
pop_back(); //删除最后一个元素
insert(const_iterator pos, ele); //迭代器指向位置pos插入元素ele
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele
erase(const_iterator pos); //删除迭代器指向的元素
erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
clear(); //删除容器中所有元素
*/
void test04()
{
	//1.插入
	vector<int> v1;
	//尾插
	v1.push_back(rand());
	v1.push_back(rand());
	//未删
	//v1.pop_back();
	//for_each(v1.begin(), v1.end(), myPrint());
	//insert()迭代器插入
	vector<int>::iterator it = v1.begin();
	//v1.insert(it + 1, rand());
	v1.insert(it + 1, 1, 6);
	
	//2.删除
	//erase()迭代器删除或区间删除
	//v1.erase(v1.begin());
	//v1.erase(v1.begin(), v1.end());
	v1.clear();//清空容器
	for_each(v1.begin(), v1.end(), myPrint());
}
//vector数据存取
void test05()
{
	vector<int> v(3, 6);
	//at()访问
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << ' ';
	}
	cout << endl;
	//operator[]访问
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;
	//front(),back()访问首位元素
	vector<int> v2;
	v2.resize(10);
	for (int i = 0; i < 10; i++)
	{
		v2.push_back(i);
	}
	cout << v2.front() << endl;
	cout << v2.back() << endl;
}
//vector互换容器
void test06()
{
	//vector<int> v1(3,6);
	//vector<int> v2(6, 3);
	//cout << "v1:";
	//for_each(v1.begin(), v1.end(), myPrint());
	//
	//cout << "v2:";
	//for_each(v2.begin(), v2.end(), myPrint());

	////容器互换swap()
	//cout << endl;
	//v1.swap(v2);
	//cout << "v1:";
	//for_each(v1.begin(), v1.end(), myPrint());
	//cout << "v2:" ;
	//for_each(v2.begin(), v2.end(), myPrint());


	//收缩内存
	vector<int> v3;
	v3.resize(10000);
	cout << v3.capacity() << endl;
	cout << v3.size() << endl;

	v3.resize(5);
	cout << v3.capacity() << endl;
	cout << v3.size() << endl;
	vector<int>(v3).swap(v3);		//*收缩内存
	cout << v3.capacity() << endl;
	cout << v3.size() << endl;

}
//vector预留空间
void test07()
{
	vector<int> v;
	v.reserve(1000);
	int* p = NULL;
	int num = 0;			//记录重新开辟空间的次数
	for (int i = 0; i < 1000; i++)
	{
		v.push_back(0);
		if (p != &v[0])
		{
			num++;
			p = &v[0];
		}
	}
	cout << num << endl;
}

int main()
{
	//构造
	//test01();
	//赋值
	//test02();
	//容量和大小
	//test03(
	// );
	//插入和删除
	//test04();
	//数据存取
	//test05();
	//互换
	//test06();
	//预留空间
	//test07();
	return 0;
}