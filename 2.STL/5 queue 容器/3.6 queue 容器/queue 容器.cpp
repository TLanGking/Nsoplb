#include <iostream>
using namespace std;
#include <queue>
//������ֻ�ж�ͷ�Ͷ�β�ſ��Ա����ʹ�ã���˶��в������б�����Ϊ


void test01()
{
	//����
	queue<int> q1; // Ĭ�Ϲ���
	queue<int> q2(q1); // ��������
	//��ֵ
	q1 = q2;
	//���ݴ�ȡ
	q1.push(666);		//��β����
	q1.push(66);
	q1.push(6);
	//q1.pop();			//��ͷɾ��
	cout << q1.front() << endl; //���ʶ�ͷԪ��
	cout << q1.back() << endl;  //���ʶ�βԪ��
	//��С����
	cout << q1.empty() << endl;
	cout << q1.size() << endl;
}

int main()
{
	test01();
	return 0;
}