#include <iostream>
#include <string>
using namespace std;

template <class T1,class T2>
class Game
{
public:
	Game(T1 name, T2 score)
	{
		this->G_name = name;
		this->G_score = score;
	}
	void printGame()
	{
		cout << this->G_name << "的等级为：" << this->G_score << endl;
	}
	T1 G_name;
	T2 G_score;
};
//类模板做全局函数参数
//1.显示指定类型
void print1(Game<string,int>& g)
{
	cout << "第一种方法：" << endl;
	cout << g.G_name << "的等级为：" << g.G_score << endl;
}
//2.类模板参数模板化
template <class T1,class T2>
void print2(Game<T1,T2>& g)
{
	cout << "第二种方法：" << endl;
	cout << g.G_name << "的等级为： " << g.G_score << endl;
	//通过typeid(类型).name()的方式获取模板类型名称
	cout << "T1的类型为：" << typeid(T1).name() << endl;
	cout << "T2的类型为：" << typeid(T2).name() << endl;
}
//3.整个类模板化
template <class T>
void print3(T& g)
{
	cout << "第三种方法：" << endl;
	cout << g.G_name << "的等级为：" << g.G_score << endl;
}

void test()
{
	Game<string, int> g1("英雄联盟", 100);
	//g1.printGame();		//类内接口
	print1(g1);				//显示指定类型
	print2(g1);				//参数模板化
	print3(g1);					//整个类模板化
}

int main()
{
	test();
	return 0;
}