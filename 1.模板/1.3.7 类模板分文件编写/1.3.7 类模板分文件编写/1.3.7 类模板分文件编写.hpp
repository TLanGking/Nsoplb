//����ģ������������д��һ���ļ��У�.hpp��
#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Game
{
public:
	Game(T name);
	void printGame();

	T G_name;
};

template <class T>
Game<T>::Game(T name)
{
	this->G_name = name;
}

template <class T>
void Game<T>::printGame()
{
	cout << ".hpp�ļ��е���ģ��ʵ�֣�" << endl;
	cout << "��Ϸ����Ϊ��" << this->G_name << endl;
}