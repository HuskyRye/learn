/*
9.编写一个程序，将拼写的数字（e.g. zero, two）转换成数值（e.g. 0, 2）
针对数字0, 1, 2, 3, 4 完成整个操作，对于其他输入，输出 “not a number I know"
*/

#include "std_lib_facilities.h"

int main()
{
	cout << "Please enter an integer as a text string: ";
	string number;
	int res = -1;
	while (cin>>number) {
		if (number == "zero") res = 0;
		else if (number == "one") res = 1;
		else if (number == "two") res = 2;
		else if (number == "three") res = 3;
		else if (number == "four") res = 4;
		else if (number == "Quit" || number == "quit") return 0;
		if (res != -1)
			cout << "You entered the number " << res << '\n';
		else
			cout << "Not a number I know!\n";
		cout << "Please enter another number or \"Quit\"\n";
		res = -1;
	}
	return 0;
}