//将类模板生命个定义写到一个文件中（.hpp）
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
	cout << ".hpp文件中的类模板实现：" << endl;
	cout << "游戏名称为：" << this->G_name << endl;
}