#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2> class Game;

template <class T1, class T2>void printGame2(Game<T1, T2>& g);



template <class T1,class T2>
class Game
{
	/*friend void printGame1(Game<T1,T2> &g)
	{
		cout << "全局函数类内实现：" << endl;
		cout << g.G_name << "的等级为：" << g.G_score << endl;
	}*/
	friend void printGame2(Game<T1, T2>& g);

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