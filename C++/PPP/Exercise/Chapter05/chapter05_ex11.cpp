/*
    11.输出尽量长的斐波那契数列
*/

#include "std_lib_facilities.h"

int main()
{
    int a = 1;
    int b = 1;
    
    while (b > 0) {
        cout << a << '\n';
        b = b + a;
        a = b - a;
    }
    cout << a << '\n';
}