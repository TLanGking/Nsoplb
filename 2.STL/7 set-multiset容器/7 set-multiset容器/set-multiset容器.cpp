#include <iostream>
using namespace std;
#include <set>

class myCompare
{
public:
	bool operator()(int x, int y)
	{
		return x > y;
	}
};

//set构造和赋值
void test01()
{
	//默认构造
	set<int> st;
	//拷贝构造
	set<int> st2(st);
	//赋值（等号赋值）
	st = st2;
}
//set大小和交换
void test02()
{
	set<int> st;
	//大小
	cout << st.size() << endl;		//容器大小
	cout << st.empty() << endl;		//判断容器是否为空
	//交换
	set<int> st2;
	st2.swap(st);		//交换
	
}
//set插入和删除
void test03()
{
	//插入
	set<int> st;
	st.insert(1);
	st.insert(3);
	st.insert(2);
	//删除
	st.clear();		//清空容器
	st.erase(st.begin());		//删除指定位置元素
	st.erase(st.begin(), st.end());		//删除区间元素
	st.erase(1);		//删除容器内所有x
}
//set查找和统计
void test04()
{
	//查找
	set<int> st;
	st.insert(6);
	st.find(6);			//若存在，返回该元素迭代器，若不存在返回尾部迭代器
	//统计
	st.count(6);		//统计容器中x的个数
}
//set容器排序
void test05()
{
	set<int, myCompare> st; //利用仿函数改变set排序规则
}



int main()
{
	//构造和赋值
	//test01();
	return 0;
}