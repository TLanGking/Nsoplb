#include <iostream>
using namespace std;
#include <stack>
//ջ��ֻ�ж��˵�Ԫ�زſ��Ա����ʹ�ã����ջ�������б�����Ϊ
void test01()
{
	//1����
	stack<int> s1;		//Ĭ�Ϲ���
	stack<int> s2(s1);		//��������
	//2��ֵ
	s1 = s2;				//ֻ�еȺŸ�ֵ
	//3���ݴ�ȡ
	s1.push(6);				//��ջ�����Ԫ��
	//s1.pop();				//ɾ��ջ��Ԫ��
	cout << s1.top() << endl;				//����ջ��Ԫ��
	//4��С����
	cout << s1.empty() << endl;
	cout << s1.size() << endl;
}


int main()
{
	test01();
	return 0;
}