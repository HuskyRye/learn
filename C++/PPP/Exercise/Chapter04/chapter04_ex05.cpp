/*
	5.实现一个简单的计算器程序，实现五种基本运算。提示用户输入三个参数
	例： 输入: 35.6 24.1 +  输出: The sum of 35.6 and 24.1 is 59.7
*/

#include "std_lib_facilities.h"

int main()
{
    cout << "Enter two double values and character (+, -, *, / or %)\n";
    double val1;
    double val2;
    char ch;
    cin >> val1 >> val2 >> ch;
    switch (ch) {
    case '+':
        cout << "The sum of " << val1 << " and " << val2 << " is " << val1+val2 << '\n';
        break;
    case '-':
        cout << "The difference of " << val1 << " and " << val2 << " is " << val1-val2 << "\n";
        break;
    case '*':
        cout << "The product of " << val1 << " and " << val2 << " is " << val1*val2 << "\n";
        break;
    case '/':
        cout << "The ratio of " << val1 << " and " << val2 << " is " << val1/val2 << "\n";
        break;
    case '%':
        cout << "The % of " << val1 << " and " << val2 << " is " << static_cast<int>(val1) % static_cast<int>(val2) << "\n";
        break;
    default:
        cout << "This is not a valid operation (+, -, *, / or %)\n";
        break;
    }
}