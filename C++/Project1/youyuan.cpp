#include <iostream>
using namespace std;

//友元 第三种 实现  整个 类  做友元
class Game;

class Friend
{
public:
	void ShowGame(Game * P);
	void ShowGame2(Game& p);
};

class Game
{
	// you'yuan 第一种 实现  全局函数 做 youyuan
	friend void Show(Game& p);
	//对友元 类  声明
	friend class Friend;
	// 第三种  成员函数做 友元
	friend void Friend::ShowGame2(Game & p);
public:
	Game(string name,int grade)
	{
		this->Name = name;
		this->Grade = grade;
	}


private:
	string Name;
	int Grade;
};

void Show(Game& p)			//全局 友元 函数 ，可访问 私有 成员 变量
{
	cout << p.Name << endl;
	cout << p.Grade << endl;
}

void Friend::ShowGame(Game * P)
{
	cout << P->Name << endl;
	cout << P->Grade << endl;

}

void Friend::ShowGame2(Game& p)
{
	cout << p.Name << endl;
	cout << p.Grade << endl;
}


int main()
{
	Game game("使命召唤", 100);
	Friend().ShowGame(&game);

	Friend().ShowGame2(game);

	return 0;
}