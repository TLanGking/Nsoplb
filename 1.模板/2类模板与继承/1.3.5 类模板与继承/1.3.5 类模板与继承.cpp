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

//��������̳и��ࣨ����Ϊ��ģ�壩ʱ�������������������
class AIGame :public Game<string,int>
{

};
//���������ָ�������е����ͣ�����Ҳ��Ҫ�����ģ��
template <class T1,class T2>
class ITGame :public Game<T1, T2>
{
public:
	ITGame(T1 name,T2 score)
	{
		cout << "ITGame��̳�Game��" << endl;
		this->G_name = name;
		this->G_score = score;
	}
	~ITGame()
	{
		cout << this->G_name << "�ĵȼ�Ϊ��" << this->G_score << endl;
	}
};

void test()
{
	ITGame<string, int> g("Ӣ������", 100);

}

int main()
{
	test();
	return 0;
}