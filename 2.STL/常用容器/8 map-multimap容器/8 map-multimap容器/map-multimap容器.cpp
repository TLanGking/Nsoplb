#include <iostream>
using namespace std;
#include <map>

//map����͸�ֵ
void test01()
{
	//����
	map<int, string> m; //Ĭ�Ϲ���
	map<int, string> m2(m);	//��������	
	//��ֵ
	m = m2;		//�ȺŸ�ֵ
}
//��С�ͽ���
void test02()
{
	map<int, string> m;
	//��С
	if (m.empty())
	{
		cout << "����Ϊ��" << endl;
		cout << m.size() << endl;
	}
	//����
	map<int, string> m2;
	m2.swap(m);
	
}

//map�����ɾ��
void test03()
{
	//����
	map<int, string> m;
	m.insert(pair<int,string>(18, "Tom"));
	//ɾ��
	m.clear();
	m.erase(m.begin());	//ɾ��ָ��λ�õ�Ԫ��
	m.erase(m.begin(), m.end());	//ɾ������Ԫ��
	m.erase(18);			//ɾ��������keyֵΪx��Ԫ��
}
//map���Һ�ͳ��
void test04()
{
	map<int, string> m;
	m.find(1);	//Ѱ��keyֵΪ1��Ԫ�أ��ҵ����ص��������Ҳ�������β��������
	m.count(1);	//ͳ��������keyΪ1��Ԫ�ظ���
	
}
//�������
void test05()
{
	//map<int, string, myCompare> m;		//���÷º����ı�mapĬ���������

}

int main()
{
	return 0;
}