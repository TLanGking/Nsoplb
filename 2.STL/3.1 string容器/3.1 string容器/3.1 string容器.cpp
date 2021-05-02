#include <iostream>
#include <string>
using namespace std;

//string���캯��
/*
string(); //����һ���յ��ַ��� ����: string str;
string(const char* s); //ʹ���ַ���s��ʼ��
string(const string& str); //ʹ��һ��string�����ʼ����һ��string����
string(int n, char c); //ʹ��n���ַ�c��ʼ��
*/
void test01()
{
	//Ĭ�Ϲ���
	string game1;
	game1 = "Langend of League";
	cout << "game1 = " << game1 << endl;
	//ʹ���ַ���������ʼ��
	string game2("Glory of Kings");
	cout << "game2 = " << game2 << endl;
	//��������
	string game3(game1);
	string game4(game2);
	cout << "game3 = " << game3 << endl;
	cout << "game4 = " << game4 << endl;
	//��n����ͬ�ַ���ʼ��
	string str(10, '?');
	cout << "str = " << str << endl;
}

//string��ֵ����
/*
string& operator=(const char* s); //char*�����ַ��� ��ֵ����ǰ���ַ���
string& operator=(const string &s); //���ַ���s������ǰ���ַ���
string& operator=(char c); //�ַ���ֵ����ǰ���ַ���
string& assign(const char *s); //���ַ���s������ǰ���ַ���
string& assign(const char *s, int n); //���ַ���s��ǰn���ַ�������ǰ���ַ���
string& assign(const string &s); //���ַ���s������ǰ�ַ���
string& assign(int n, char c); //��n���ַ�c������ǰ�ַ���
*/
void test02()
{
	//�ȺŸ�ֵ
	string game1 = "langend of league";
	string game2 = game1;
	string str1;
	str1 = '?';
	cout << "game1 == " << game1 << endl;
	cout << "game2 == " << game2 << endl;
	cout << "str == " << str1 << endl;
	//assign������ֵ
	string game3;
	game3.assign("langend of league");
	string game4;
	game4.assign(game3);
	string str2;
	str2.assign(10,'?');
	//��s2ǰn�� �ַ� ��ֵ�� s1
	string str3;
	str3.assign(str2, 5);
	cout << "game3 == " << game3 << endl;
	cout << "game4 == " << game4 << endl;
	cout << "st2 == " << str2 << endl;
	cout << "st3 == " << str3 << endl;

}
//string�ַ���ƴ��
/*
string& operator+=(const char* str); //����+=������
string& operator+=(const char c); //����+=������
string& operator+=(const string& str); //����+=������

string& append(const char *s); //���ַ���s���ӵ���ǰ�ַ�����β
string& append(const char *s, int n); //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
string& append(const string &s); //ͬoperator+=(const string& str)
string& append(const string &s, int pos, int n);//�ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
*/
void test03()
{
	string game1;
	game1 = "Langend of League";
	string game2("Glory of Kings");
	string game3(game1);
	string game4(game2);
	string str1(10, '?');
	//+=ƴ�ӣ�׷�ӣ�
	string str2 = "I love computer games,such as ";
	str2 += game1;			//׷���ַ�������
	//cout << str2 << endl;
	str2 += ',';			//׷���ַ�
	str2 += "DNF";			//׷���ַ�������
	//cout << str2 << endl;
	//append����׷�ӣ�ƴ�ӣ�
	string str3 = "i like play ";
	str3.append("DNF ");			//�ַ�������ƴ��
	str3.append("LOL LOL", 4);		//�ַ���������ǰn���ַ�ƴ��
	str3.append(game1);				//�ַ�������׷��
	str3.append(game2,0,5);			//�ַ������� �����ַ� ׷��
	cout << str3 << endl;
}
//string���Һ��滻
/*
int find(const string& str, int pos = 0) const; //����str��һ�γ���λ��,��pos��ʼ����
int find(const char* s, int pos = 0) const; //����s��һ�γ���λ��,��pos��ʼ����
int find(const char* s, int pos, int n) const; //��posλ�ò���s��ǰn���ַ���һ��λ��
int find(const char c, int pos = 0) const; //�����ַ�c��һ�γ���λ��

int rfind(const string& str, int pos = npos) const; //����str���һ��λ��,��pos��ʼ����
int rfind(const char* s, int pos = npos) const; //����s���һ�γ���λ��,��pos��ʼ����
int rfind(const char* s, int pos, int n) const; //��pos����s��ǰn���ַ����һ��λ��
int rfind(const char c, int pos = 0) const; //�����ַ�c���һ�γ���λ��

string& replace(int pos, int n, const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
string& replace(int pos, int n,const char* s); //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
*/
void test04()
{
	string game1 = "Langend of League";
	string game2("Glory of Kings");
	string str1(10, '?');
	//find����
	int pos;
	//pos = game1.find("of",0,1);

	//pos = game1.find(game2, 0);
	pos = game1.find('L', 0);

	if (pos >= 0)
	{
		cout << "find success" << endl;
		cout << "pos == " << pos << endl;
	}
	else
	{
		cout << "find unsccess" << endl;
	}
	//find��rfind�÷�һ��
	//��������find��ǰ�����ң�rfind�Ӻ���ǰ��

	//�滻��replace��
	//game1.repalce(0, 7, str1);
	game2.replace(0, 5, "Phone");
	cout << game2 << endl;

}
//string�ַ����Ƚ�
void test05()
{
	string game1 = "Langend of League";
	string game2("Glory of Kings");
	int com = game1.compare("Glory of Kings");
}

//string�ַ���ȡ
void test06()
{
	string game1 = "Langend of League";
	string game2("Glory of Kings");
	//[]����
	for (int i = 0; i < game1.length(); i++)
	{
		 game1[i] = ' ';
		
	}
	for (int i = 0; i < game1.length(); i++)
	{
		cout << game1[i] << ' ';
		
	}

	cout << endl;
	for (int  i = 0; i < game2.length(); i++)
	{
		game2.at(i) = ' ';
	}
	for (int i = 0; i < game2.length(); i++)
	{
		cout << game2.at(i);
	}
	cout << endl;
}
// string�����ɾ��
/*
string& insert(int pos, const char* s); //�����ַ���
string& insert(int pos, const string& str); //�����ַ���
string& insert(int pos, int n, char c); //��ָ��λ�ò���n���ַ�c

string& erase(int pos, int n = npos); //ɾ����Pos��ʼ��n���ַ�
*/
void test07()
{
	string game1 = "Langend of League";
	string game2("Glory of Kings");
	//���루insert��
	game1.insert(7, game2);

	game1.insert(7, ",,");
	game2.insert(5,10,'?');

	cout << game1 << endl;
	cout << game2 << endl;

	//ɾ����erase��
	game1.erase(7,16);

	game2.erase(5, 10);

	cout << game1 << endl;
	cout << game2 << endl;
}

// string�Ӵ�
void test08()
{
	//�ִ������ַ����л�ȡ��Ҫ���Ӵ�
	string game1 = "Langend of League";
	string game2 = game1.substr(0,7);
	cout << game1 << endl;
	cout << game2 << endl;
}
int main()
{
	//����
	//test01();
	//��ֵ
	//test02();
	//ƴ��
	//test03();
	//���Һ��滻
	//test04();
	//�Ƚ�
	//test05();
	//��ȡ
	//test06();
	//�����ɾ��
	//test07();
	//�Ӵ�
	test08();
	return 0;
}