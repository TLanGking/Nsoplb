#include <iostream>
#include <cmath>
using namespace std;

int main3()
{
	int i = 100;
WHILE:

	if (i == pow((i / 100), 3) + pow((i % 100 / 10), 3) + pow((i % 100 % 10), 3))
		cout << i << endl;
	i++;
	if (i < 1000)
		goto WHILE;

	return 0;
}