#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2> class Game;

template <class T1, class T2>void  printGame2(Game<T1, T2>& g);

template <class T1,class T2>
class Game
{
	/*friend void printGame1(Game<T1,T2> &g)
	{
		cout << "全局函数类内实现：" << endl;
		cout << g.G_name << "的等级为：" << g.G_score << endl;
	}*/
	void friend  printGame2<>(Game<T1, T2>& g);

public:
	Game(T1 name, T2 score)
	{
		this->G_name = name;
		this->G_score = score;
	}

	/*Game(T1 name, T2 score);
	void printGame();*/
private:
	T1 G_name;
	T2 G_score;
};


template <class T1, class T2>
void printGame2(Game<T1, T2>& g)
{
	cout << "全局函数类外实现：" << endl;
	cout << g.G_name << "的等级为：" << g.G_score << endl;
}

void test()
{
	Game<string, int> g("英雄联盟", 100);
	//printGame1(g);			//全局友元函数雷内实现
	printGame2(g);				//全局友元函数类外实现
}

int main()
{
	test();
	return 0;
}


////2、全局函数配合友元  类外实现 - 先做函数模板声明，下方在做函数模板定义，在做友元
//template<class T1, class T2> class Person;
//
////如果声明了函数模板，可以将实现写到后面，否则需要将实现体写到类的前面让编译器提前看到
////template<class T1, class T2> void printPerson2(Person<T1, T2> & p); 
//
//template<class T1, class T2>
//void printPerson2(Person<T1, T2>& p)
//{
//	cout << "类外实现 ---- 姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
//}
//
//template<class T1, class T2>
//class Person
//{
//	//1、全局函数配合友元   类内实现
//	friend void printPerson(Person<T1, T2>& p)
//	{
//		cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
//	}
//
//
//	//全局函数配合友元  类外实现
//	friend void printPerson2<>(Person<T1, T2>& p);
//
//public:
//
//	Person(T1 name, T2 age)
//	{
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//
//
//private:
//	T1 m_Name;
//	T2 m_Age;
//
//};
//
////1、全局函数在类内实现
//void test01()
//{
//	Person <string, int >p("Tom", 20);
//	printPerson(p);
//}
//
//
////2、全局函数在类外实现
//void test02()
//{
//	Person <string, int >p("Jerry", 30);
//	printPerson2(p);
//}
//
//int main() {
//
//	//test01();
//
//	test02();
//
//	system("pause");
//
//	return 0;
//}