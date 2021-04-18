#include <iostream>
#include <string>
using namespace std;


template <class T1,class T2>
class Game
{
public:
	T1 G_name;
	T2 G_score;
};

//当派生类继承父类（父类为类模板）时，必须声明父类的类型
class AIGame :public Game<string,int>
{

};
//如果想灵活的指出父类中的类型，子类也需要变成类模板
template <class T1,class T2>
class ITGame :public Game<T1, T2>
{
public:
	ITGame(T1 name,T2 score)
	{
		cout << "ITGame类继承Game类" << endl;
		this->G_name = name;
		this->G_score = score;
	}
	~ITGame()
	{
		cout << this->G_name << "的等级为：" << this->G_score << endl;
	}
};

void test()
{
	ITGame<string, int> g("英雄联盟", 100);

}

int main()
{
	test();
	return 0;
}