/*
4.编写一个程序，提示用户输入两个整数值，将这些值保存在 int 变量 val1 和 val2 中。
求这两个值中的最大值、最小值、和、差、乘积和比率，并将结果输出给用户。
*/

#include "std_lib_facilities.h"

int main()
{
	cout << "Please enter two integer values separated by a space: ";
	int val1 = 0;
	int val2 = 0;
	cin >> val1 >> val2;
	cout << "values : " << val1 << " " << val2 << '\n';

	if (val1<val2)
		cout << val1 << " is smallest\n";
	else if (val2<val1)
		cout << val2 << " is smallest\n";
	else
		cout << val1 << " and " << val2 << " are equal\n";

	cout << "sum : " << val1+val2 << '\n';
	cout << "product : " << val1*val2 << '\n';
	if (val2==0)
		cout << "divide by zero\n";
	else
		cout << "ratio (val1/val2): " << val1/val2 << '\n';

	keep_window_open();
	return 0;
}