#include "std_lib_facilities.h"

// 英寸和厘米之间的转换程序
// 后缀 i 和 c 表示输入的单位
int main1()
{
	constexpr double cm_per_inch = 2.54;
	cout << "Please enter a lenght followed by a unit (c or i): \n";
	double length = 1;
	char unit = 0;
	cin >> length >> unit;
	if (unit == 'i')
		cout << length << "in == " << length * cm_per_inch << "cm\n";
	else if (unit == 'c')
		cout << length << "cm == " << length / cm_per_inch << "in\n";
	else
		cout << "Sorry, I don't know a unit called '" << unit << "'\n";
	return 0;
}

int main2()
{
	constexpr double cm_per_inch = 2.54;
	cout << "Please enter a lenght followed by a unit (c or i): \n";
	double length = 1;
	char unit = 0;
	cin >> length >> unit;
	switch (unit) {
	case 'i':
		cout << length << "in == " << length * cm_per_inch << "cm\n";
		break;
	case 'c':
		cout << length << "cm == " << length / cm_per_inch << "in\n";
		break;
	default:
		cout << "Sorry, I don't know a unit called '" << unit << "'\n";
		break;
	}
	return 0;
}

int square(int);

int main3()
{
	int i = 0;
	while (i < 100) {
		cout << i << '\t' << square(i) << '\n';
		++i;
	}
	return 0;
}

int main4()
{
	for (int i = 0; i < 100; ++i)
		cout << i << '\t' << square(i) << '\n';
}

int square(int x)
{
	return x * x;
}