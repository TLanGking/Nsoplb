#include <iostream>
using namespace std;
#include <map>

//map构造和赋值
void test01()
{
	//构造
	map<int, string> m; //默认构造
	map<int, string> m2(m);	//拷贝构造	
	//赋值
	m = m2;		//等号赋值
}
//大小和交换
void test02()
{
	map<int, string> m;
	//大小
	if (m.empty())
	{
		cout << "容器为空" << endl;
		cout << m.size() << endl;
	}
	//交换
	map<int, string> m2;
	m2.swap(m);
	
}

//map插入和删除
void test03()
{
	//插入
	map<int, string> m;
	m.insert(pair<int,string>(18, "Tom"));
	//删除
	m.clear();
	m.erase(m.begin());	//删除指定位置的元素
	m.erase(m.begin(), m.end());	//删除区间元素
	m.erase(18);			//删除容器内key值为x的元素
}
//map查找和统计
void test04()
{
	map<int, string> m;
	m.find(1);	//寻找key值为1的元素，找到返回迭代器，找不到返回尾部迭代器
	m.count(1);	//统计容器中key为1的元素个数
	
}
//排序规则
void test05()
{
	//map<int, string, myCompare> m;		//利用仿函数改变map默认排序规则

}

int main()
{
	return 0;
}