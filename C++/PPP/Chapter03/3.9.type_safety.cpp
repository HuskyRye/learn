#include "std_lib_facilities.h"

int main1()
{
	double x;	// x 未初始化，x 的值未定义
	double y = x;
	double z = 2.0 + x;
	return 0;
}

int main2()
{
	int a = 20000;
	char c = a;
	int b = c;
	if (a != b)
		cout << a << " != " << b << '\n';
	else
		cout << "We have large characters\n";
	keep_window_open();
	return 0;
}

int main3()
{
	double d = 0;
	while (cin >> d) {
		int i = d;
		char c = i;
		int i2 = c;
		cout << "d == " << d
			<< "i == " << i
			<< "i2 == " << i2
			<< "char(" << c << ")\n";
	}
	return 0;
}

int main()
{
	double x { 2.7 };
	int y { x };

	int a { 1000 };
	char b { a };

	char b1 { 1000 };
	char b2 { 48 };
}