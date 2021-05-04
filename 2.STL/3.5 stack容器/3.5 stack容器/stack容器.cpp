#include <iostream>
using namespace std;
#include <stack>
//栈中只有顶端的元素才可以被外界使用，因此栈不允许有遍历行为
void test01()
{
	//1构造
	stack<int> s1;		//默认构造
	stack<int> s2(s1);		//拷贝构造
	//2赋值
	s1 = s2;				//只有等号赋值
	//3数据存取
	s1.push(6);				//向栈顶添加元素
	//s1.pop();				//删除栈顶元素
	cout << s1.top() << endl;				//访问栈顶元素
	//4大小操作
	cout << s1.empty() << endl;
	cout << s1.size() << endl;
}


int main()
{
	test01();
	return 0;
}