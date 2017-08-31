#include "std_lib_facilities.h"

// 运算符简单介绍
int main1()
{
	cout << "Please enter a floating-point value: ";
	double n;
	cin >> n;
	cout << "n == " << n
		<< "\nn+1 == " << n + 1
		<< "\nthree times n == " << 3 * n
		<< "\ntwice n == " << n + n
		<< "\nn squared == " << n * n
		<< "\nhalf of n == " << n / 2
		<< "\nsquare root of n == " << sqrt(n)
		<< '\n';

	keep_window_open();
	return 0;
}

// 读取两个名字
int main2()
{
	cout << "Please enter your first and second names\n";
	string first;
	string second;
	cin >> first >> second;
	string name = first + ' ' + second;
	cout << "Hello, " << name << '\n';

	return 0;
}

int main()
{
	cout << "Please enter two names\n";
	string first;
	string second;
	cin >> first >> second;
	if (first == second) {
		cout << "that's the same name twice\n";
	}
	else if (first < second) {
		cout << first << " is alphabetically before " << second << '\n';
	}
	else {
		cout << first << " is alphabetically after " << second << '\n';
	}

	return 0;
}