#include <iostream>
using namespace std;

int main()
{
	//转义字符，通常用来表示显示不出来的Ascll字符

	cout << '\a' << endl;	// \a 警报
	// \b 退格
	cout << "hello" << endl;
	cout << "\bworld" << endl;
	// \f 换页
	cout << "\f";
	// \n 换行   \r 回车
	cout << "\n\r";
	cout << "hello world";
	// \t 水品制表符
	cout << "hello\tworld";
	// \v 垂直制表符
	cout << "\nhello\vworld";
	cout << "\d34";

	return 0;
}