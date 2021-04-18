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
		cout << "ȫ�ֺ�������ʵ�֣�" << endl;
		cout << g.G_name << "�ĵȼ�Ϊ��" << g.G_score << endl;
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