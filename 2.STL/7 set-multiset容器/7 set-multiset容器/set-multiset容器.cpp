#include <iostream>
using namespace std;
#include <set>

class myCompare
{
public:
	bool operator()(int x, int y)
	{
		return x > y;
	}
};

//set����͸�ֵ
void test01()
{
	//Ĭ�Ϲ���
	set<int> st;
	//��������
	set<int> st2(st);
	//��ֵ���ȺŸ�ֵ��
	st = st2;
}
//set��С�ͽ���
void test02()
{
	set<int> st;
	//��С
	cout << st.size() << endl;		//������С
	cout << st.empty() << endl;		//�ж������Ƿ�Ϊ��
	//����
	set<int> st2;
	st2.swap(st);		//����
	
}
//set�����ɾ��
void test03()
{
	//����
	set<int> st;
	st.insert(1);
	st.insert(3);
	st.insert(2);
	//ɾ��
	st.clear();		//�������
	st.erase(st.begin());		//ɾ��ָ��λ��Ԫ��
	st.erase(st.begin(), st.end());		//ɾ������Ԫ��
	st.erase(1);		//ɾ������������x
}
//set���Һ�ͳ��
void test04()
{
	//����
	set<int> st;
	st.insert(6);
	st.find(6);			//�����ڣ����ظ�Ԫ�ص��������������ڷ���β��������
	//ͳ��
	st.count(6);		//ͳ��������x�ĸ���
}
//set��������
void test05()
{
	set<int, myCompare> st; //���÷º����ı�set�������
}



int main()
{
	//����͸�ֵ
	//test01();
	return 0;
}