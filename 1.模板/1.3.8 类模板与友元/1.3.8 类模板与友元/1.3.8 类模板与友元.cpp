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
		cout << "ȫ�ֺ�������ʵ�֣�" << endl;
		cout << g.G_name << "�ĵȼ�Ϊ��" << g.G_score << endl;
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
	cout << "ȫ�ֺ�������ʵ�֣�" << endl;
	cout << g.G_name << "�ĵȼ�Ϊ��" << g.G_score << endl;
}

void test()
{
	Game<string, int> g("Ӣ������", 100);
	//printGame1(g);			//ȫ����Ԫ��������ʵ��
	printGame2(g);				//ȫ����Ԫ��������ʵ��
}

int main()
{
	test();
	return 0;
}


////2��ȫ�ֺ��������Ԫ  ����ʵ�� - ��������ģ���������·���������ģ�嶨�壬������Ԫ
//template<class T1, class T2> class Person;
//
////��������˺���ģ�壬���Խ�ʵ��д�����棬������Ҫ��ʵ����д�����ǰ���ñ�������ǰ����
////template<class T1, class T2> void printPerson2(Person<T1, T2> & p); 
//
//template<class T1, class T2>
//void printPerson2(Person<T1, T2>& p)
//{
//	cout << "����ʵ�� ---- ������ " << p.m_Name << " ���䣺" << p.m_Age << endl;
//}
//
//template<class T1, class T2>
//class Person
//{
//	//1��ȫ�ֺ��������Ԫ   ����ʵ��
//	friend void printPerson(Person<T1, T2>& p)
//	{
//		cout << "������ " << p.m_Name << " ���䣺" << p.m_Age << endl;
//	}
//
//
//	//ȫ�ֺ��������Ԫ  ����ʵ��
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
////1��ȫ�ֺ���������ʵ��
//void test01()
//{
//	Person <string, int >p("Tom", 20);
//	printPerson(p);
//}
//
//
////2��ȫ�ֺ���������ʵ��
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