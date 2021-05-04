#include <iostream>
using namespace std;
#include <queue>
//队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为


void test01()
{
	//构造
	queue<int> q1; // 默认构造
	queue<int> q2(q1); // 拷贝构造
	//赋值
	q1 = q2;
	//数据存取
	q1.push(666);		//队尾插数
	q1.push(66);
	q1.push(6);
	//q1.pop();			//队头删数
	cout << q1.front() << endl; //访问对头元素
	cout << q1.back() << endl;  //访问队尾元素
	//大小操作
	cout << q1.empty() << endl;
	cout << q1.size() << endl;
}

int main()
{
	test01();
	return 0;
}