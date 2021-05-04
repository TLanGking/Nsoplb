/*
案例描述: 实现一个通用的数组类，要求如下：

可以对内置数据类型以及自定义数据类型的数据进行存储
将数组中的数据存储到堆区
构造函数中可以传入数组的容量
提供对应的拷贝构造函数以及operator=防止浅拷贝问题
提供尾插法和尾删法对数组中的数据进行增加和删除
可以通过下标的方式访问数组中的元素
可以获取数组中当前元素个数和数组的容量
*/

#include <iostream>
#include <string>
using namespace std;

#include "1.3.9类模板.hpp"

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
	//内置数据类型
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
	cout << "容量：" << arr1.capacity() << endl;
	cout << "大小：" << arr1.size() << endl;
}


int main()
{
	//test();
	test2();
	return 0;
}