#include <iostream>
using namespace std;

//��Ԫ ������ ʵ��  ���� ��  ����Ԫ
class Game;

class Friend
{
public:
	void ShowGame(Game * P);
	void ShowGame2(Game& p);
};

class Game
{
	// you'yuan ��һ�� ʵ��  ȫ�ֺ��� �� youyuan
	friend void Show(Game& p);
	//����Ԫ ��  ����
	friend class Friend;
	// ������  ��Ա������ ��Ԫ
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

void Show(Game& p)			//ȫ�� ��Ԫ ���� ���ɷ��� ˽�� ��Ա ����
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
	Game game("ʹ���ٻ�", 100);
	Friend().ShowGame(&game);

	Friend().ShowGame2(game);

	return 0;
}