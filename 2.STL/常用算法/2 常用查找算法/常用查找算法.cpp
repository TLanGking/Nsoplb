#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Game
{
public:
	Game(string name, int score)
	{
		this->G_name = name;
		this->G_score = score;
	}
	bool operator==(const Game& g)
	{
		if (this->G_score == g.G_score && this->G_name == g.G_name)
			return true;
		else
			return false;
	}
	string G_name;
	int G_score;
};

//find����ָ��Ԫ��
void test01()
{
	vector<Game> v1;
	Game m1("Ӣ������", 100);
	Game m2("�����Գ�", 5);
	Game m3("ʹ���ٻ�", 30);

	v1.push_back(m1);
	v1.push_back(m2);
	v1.push_back(m3);

	vector<Game>::iterator it = find(v1.begin(),v1.end(),m1);
	if (it == v1.end())
	{
		cout << "û���ҵ���" << endl;
	}
	else
	{
		cout << "�ҵ���" << endl;
		cout << it->G_name << ' ' << it->G_score << endl;
	}
}

int main()
{
	//find
	test01();
	return 0;
}