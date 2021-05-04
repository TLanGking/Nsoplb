#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Game
{
public:
	Game(T1 name,T2 score);
	void printGame();
	T1 G_name;
	T2 G_score;
};

//类模板构造函数类外实现
template <class T1,class T2>
Game<T1,T2>::Game(T1 name, T2 score)
{
	this->G_name = name;
	this->G_score = score;
}
//成员函数类外实现
template <class T1,class T2>
void Game<T1, T2>::printGame()
{
	cout << this->G_name << "的等级为：" << this->G_score << endl;
}
//类模板函数类外实现都要加上 模板参数列表
void test()
{
	Game<string, int> g("英雄联盟", 100);
	g.printGame();
}

int main()
{
	test();
	return 0;
}