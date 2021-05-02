#include <iostream>
#include <string>
using namespace std;

template <class T1,class T2>
class Game
{
public:
	Game(T1 name, T2 score)
	{
		this->G_name = name;
		this->G_score = score;
	}
	void printGame()
	{
		cout << this->G_name << "�ĵȼ�Ϊ��" << this->G_score << endl;
	}
	T1 G_name;
	T2 G_score;
};
//��ģ����ȫ�ֺ�������
//1.��ʾָ������
void print1(Game<string,int>& g)
{
	cout << "��һ�ַ�����" << endl;
	cout << g.G_name << "�ĵȼ�Ϊ��" << g.G_score << endl;
}
//2.��ģ�����ģ�廯
template <class T1,class T2>
void print2(Game<T1,T2>& g)
{
	cout << "�ڶ��ַ�����" << endl;
	cout << g.G_name << "�ĵȼ�Ϊ�� " << g.G_score << endl;
	//ͨ��typeid(����).name()�ķ�ʽ��ȡģ����������
	cout << "T1������Ϊ��" << typeid(T1).name() << endl;
	cout << "T2������Ϊ��" << typeid(T2).name() << endl;
}
//3.������ģ�廯
template <class T>
void print3(T& g)
{
	cout << "�����ַ�����" << endl;
	cout << g.G_name << "�ĵȼ�Ϊ��" << g.G_score << endl;
}

void test()
{
	Game<string, int> g1("Ӣ������", 100);
	//g1.printGame();		//���ڽӿ�
	print1(g1);				//��ʾָ������
	print2(g1);				//����ģ�廯
	print3(g1);					//������ģ�廯
}

int main()
{
	test();
	return 0;
}