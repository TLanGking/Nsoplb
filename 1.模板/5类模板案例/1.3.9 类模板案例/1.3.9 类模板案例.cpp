/*
��������: ʵ��һ��ͨ�õ������࣬Ҫ�����£�

���Զ��������������Լ��Զ����������͵����ݽ��д洢
�������е����ݴ洢������
���캯���п��Դ������������
�ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������
�ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
����ͨ���±�ķ�ʽ���������е�Ԫ��
���Ի�ȡ�����е�ǰԪ�ظ��������������
*/

#include <iostream>
#include <string>
using namespace std;

#include "1.3.9��ģ��.hpp"

class Game
{
public:
	Game(string name,int grade)
	{
		this->G_name = name;
		this->G_grade = grade;
	}
	string G_name;
	int G_grade;
};

void printMyArr(myArr<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void test()
{
	//������������
	/*myArr<int> arr1(sizeof(int)*50);

	arr1.push_back(rand() % 50 * 10);
	arr1.push_back(rand() % 50 * 10);
	arr1.push_back(rand() % 50 * 10);
	arr1.push_back(rand() % 50 * 10);
	arr1.push_back(rand() % 50 * 10);
	arr1.push_back(rand() % 50 * 10);
	arr1.push_back(rand() % 50 * 10);
	arr1.push_back(rand() % 50 * 10);
	arr1.push_back(rand() % 50 * 10);

	printMyArr(arr1);

	myArr<int> arr2 = arr1;
	printMyArr(arr2);
	arr2.pop_back();
	arr2.pop_back();
	arr2.pop_back();
	arr2.pop_back();
	arr2.pop_back();
	arr2.pop_back();
	printMyArr(arr2);*/
}

void test2()
{
	Game g1("LOL", 100);
	
	myArr<Game> arr1(sizeof(g1) * 1);
	arr1.push_back(g1);
	cout << "������" << arr1.capacity() << endl;
	cout << "��С��" << arr1.size() << endl;
}


int main()
{
	//test();
	test2();
	return 0;
}