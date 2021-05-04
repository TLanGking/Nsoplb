#include <iostream>
#include <string>
using namespace std;

//string构造函数
/*
string(); //创建一个空的字符串 例如: string str;
string(const char* s); //使用字符串s初始化
string(const string& str); //使用一个string对象初始化另一个string对象
string(int n, char c); //使用n个字符c初始化
*/
void test01()
{
	//默认构造
	string game1;
	game1 = "Langend of League";
	cout << "game1 = " << game1 << endl;
	//使用字符串常量初始化
	string game2("Glory of Kings");
	cout << "game2 = " << game2 << endl;
	//拷贝构造
	string game3(game1);
	string game4(game2);
	cout << "game3 = " << game3 << endl;
	cout << "game4 = " << game4 << endl;
	//用n个相同字符初始化
	string str(10, '?');
	cout << "str = " << str << endl;
}

//string赋值操作
/*
string& operator=(const char* s); //char*类型字符串 赋值给当前的字符串
string& operator=(const string &s); //把字符串s赋给当前的字符串
string& operator=(char c); //字符赋值给当前的字符串
string& assign(const char *s); //把字符串s赋给当前的字符串
string& assign(const char *s, int n); //把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s); //把字符串s赋给当前字符串
string& assign(int n, char c); //用n个字符c赋给当前字符串
*/
void test02()
{
	//等号赋值
	string game1 = "langend of league";
	string game2 = game1;
	string str1;
	str1 = '?';
	cout << "game1 == " << game1 << endl;
	cout << "game2 == " << game2 << endl;
	cout << "str == " << str1 << endl;
	//assign函数赋值
	string game3;
	game3.assign("langend of league");
	string game4;
	game4.assign(game3);
	string str2;
	str2.assign(10,'?');
	//把s2前n个 字符 赋值给 s1
	string str3;
	str3.assign(str2, 5);
	cout << "game3 == " << game3 << endl;
	cout << "game4 == " << game4 << endl;
	cout << "st2 == " << str2 << endl;
	cout << "st3 == " << str3 << endl;

}
//string字符串拼接
/*
string& operator+=(const char* str); //重载+=操作符
string& operator+=(const char c); //重载+=操作符
string& operator+=(const string& str); //重载+=操作符

string& append(const char *s); //把字符串s连接到当前字符串结尾
string& append(const char *s, int n); //把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s); //同operator+=(const string& str)
string& append(const string &s, int pos, int n);//字符串s中从pos开始的n个字符连接到字符串结尾
*/
void test03()
{
	string game1;
	game1 = "Langend of League";
	string game2("Glory of Kings");
	string game3(game1);
	string game4(game2);
	string str1(10, '?');
	//+=拼接（追加）
	string str2 = "I love computer games,such as ";
	str2 += game1;			//追加字符串变量
	//cout << str2 << endl;
	str2 += ',';			//追加字符
	str2 += "DNF";			//追加字符串常量
	//cout << str2 << endl;
	//append函数追加（拼接）
	string str3 = "i like play ";
	str3.append("DNF ");			//字符串常量拼接
	str3.append("LOL LOL", 4);		//字符串常量的前n个字符拼接
	str3.append(game1);				//字符串变量追加
	str3.append(game2,0,5);			//字符串变量 区间字符 追加
	cout << str3 << endl;
}
//string查找和替换
/*
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const; //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const; //查找字符c第一次出现位置

int rfind(const string& str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const; //查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const; //从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置

string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n,const char* s); //替换从pos开始的n个字符为字符串s
*/
void test04()
{
	string game1 = "Langend of League";
	string game2("Glory of Kings");
	string str1(10, '?');
	//find查找
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
	//find与rfind用法一致
	//区别在于find从前往后找，rfind从后往前找

	//替换（replace）
	//game1.repalce(0, 7, str1);
	game2.replace(0, 5, "Phone");
	cout << game2 << endl;

}
//string字符串比较
void test05()
{
	string game1 = "Langend of League";
	string game2("Glory of Kings");
	int com = game1.compare("Glory of Kings");
}

//string字符存取
void test06()
{
	string game1 = "Langend of League";
	string game2("Glory of Kings");
	//[]访问
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
// string插入和删除
/*
string& insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c); //在指定位置插入n个字符c

string& erase(int pos, int n = npos); //删除从Pos开始的n个字符
*/
void test07()
{
	string game1 = "Langend of League";
	string game2("Glory of Kings");
	//插入（insert）
	game1.insert(7, game2);

	game1.insert(7, ",,");
	game2.insert(5,10,'?');

	cout << game1 << endl;
	cout << game2 << endl;

	//删除（erase）
	game1.erase(7,16);

	game2.erase(5, 10);

	cout << game1 << endl;
	cout << game2 << endl;
}

// string子串
void test08()
{
	//字串：从字符串中获取想要的子串
	string game1 = "Langend of League";
	string game2 = game1.substr(0,7);
	cout << game1 << endl;
	cout << game2 << endl;
}
int main()
{
	//构造
	//test01();
	//赋值
	//test02();
	//拼接
	//test03();
	//查找和替换
	//test04();
	//比较
	//test05();
	//存取
	//test06();
	//插入和删除
	//test07();
	//子串
	test08();
	return 0;
}