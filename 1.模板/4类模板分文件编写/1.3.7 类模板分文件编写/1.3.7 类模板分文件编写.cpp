#include <iostream>
#include <string>
#include "1.3.7 类模板分文件编写.hpp"
using namespace std;

void test()
{
	Game<string> g("英雄联盟");
	g.printGame();
}

int main()
{
	test();
	return 0;
}