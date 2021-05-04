#include <iostream>
using namespace std;
#include <list>
#include <algorithm>

class myPrint
{
public:
	void operator()(int x)
	{
		cout << x << ' ';
	}
};
//list���캯��
void test01()
{
	//Ĭ�Ϲ���
	list<int> t1;
	//n��x�ķ�ʽ����
	list<int> t2(3, 1);
	//���乹��
	list<int> t3(t2.begin(), t2.end());
	//��������
	list<int> t4(t3);

	for_each(t2.begin(), t2.end(), myPrint());
}

//list��ֵ�ͽ���
void test02()
{
	//��ֵassign,�ȺŸ�ֵ
	list<int> t1(6, 6);
	list<int> t2;
	//t2 = t1;		//�ȺŸ�ֵ
	//t2.assign(t1.begin(), t1.end());		//���临��
	t2.assign(3, 6);			//n��x�ķ�ʽ��ֵ
	//for_each(t2.begin(), t2.end(), myPrint());
	//����

	cout << "����ǰ" << endl;
	for_each(t1.begin(), t1.end(), myPrint());
	cout << endl;
	for_each(t2.begin(), t2.end(), myPrint());
	cout << endl;
	t1.swap(t2);

	cout << "������" << endl;
	for_each(t1.begin(), t1.end(), myPrint());
	cout << endl;
	for_each(t2.begin(), t2.end(), myPrint());
	cout << endl;
}
//list ��С����
void test03()
{
	list<int> t1(3, 1);
	cout << t1.size() << endl;		//��С
	list<int> t2(4, 2);
	cout << t2.empty() << endl;		//�ж��Ƿ�Ϊ��
	//����ָ����С
	t1.resize(6);
	t2.resize(6, 6);

	for_each(t1.begin(), t1.end(), myPrint());
	cout << endl;
	for_each(t2.begin(), t2.end(), myPrint());
	cout << endl;
}
//list �����ɾ��
/*
push_back(elem);//������β������һ��Ԫ��
pop_back();//ɾ�����������һ��Ԫ��
push_front(elem);//��������ͷ����һ��Ԫ��
pop_front();//��������ͷ�Ƴ���һ��Ԫ��

insert(pos,elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��

clear();//�Ƴ���������������
erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�
*/
void test04()
{
	list<int> t;
	//��β �����ɾ��
	t.push_back(6);		//β��
	t.push_front(6);		//ͷ��
	t.pop_back();		//	α��
	t.pop_front();		//ͷɽ

	//����
	list<int> l(6, 6);
	list<int>::iterator it = t.begin();
	t.insert(it, 6);			//ָ��λ�ò���Ԫ��
	t.insert(it, 3, 2);			//ָ��λ�ò���n��x
	t.insert(it, l.begin(), l.end());		//ָ��λ�ò�������

	//ɾ��
	//t.clear();		//�������
	//t.erase(t.begin(), t.end());		//ɾ��������Ԫ�أ������¸�Ԫ�ص�λ��
	//t.erase(t.begin());				//ɾ��ָ��λ�õ�Ԫ�أ������¸�Ԫ�ص�λ��

	
	//*removeɾ��
	t.remove(6);			//ɾ������������6
	for_each(t.begin(), t.end(), myPrint());
}
//list ���ݴ�ȡ
void test05()
{
	//ֻ�ܷ�����βԪ��
	list<int> t(3, 1);
	cout << t.back() << endl;
	cout << t.front() << endl;
}
//list ��ת������
class myCompare
{
public:
	bool operator()(int x, int y)
	{
		return x > y;
	}
};

void test06()
{
	//��תreserve
	list<int> t;
	t.push_back(1);
	t.push_back(7);
	t.push_back(3);
	/*for_each(t.begin(), t.end(), myPrint());
	t.reverse();
	for_each(t.begin(), t.end(), myPrint());*/
	//����
	//t.sort();	///Ĭ������
	t.sort(myCompare());
	for_each(t.begin(), t.end(), myPrint());

}


int main()
{
	//����
	//test01();
	//��ֵ�ͽ���
	//test02();
	//��С
	//test03();
	//���� ��ɾ��
	//test04();
	//���ݴ�ȡ
	//test05();
	//��ת������
	test06();
	return 0;
}