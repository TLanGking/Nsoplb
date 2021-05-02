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

//��ģ�幹�캯������ʵ��
template <class T1,class T2>
Game<T1,T2>::Game(T1 name, T2 score)
{
	this->G_name = name;
	this->G_score = score;
}
//��Ա��������ʵ��
template <class T1,class T2>
void Game<T1, T2>::printGame()
{
	cout << this->G_name << "�ĵȼ�Ϊ��" << this->G_score << endl;
}
//��ģ�庯������ʵ�ֶ�Ҫ���� ģ������б�
void test()
{
	Game<string, int> g("Ӣ������", 100);
	g.printGame();
}

int main()
{
	test();
	return 0;
}