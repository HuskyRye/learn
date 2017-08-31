/*
	13.使用筛法找出 1 到 100 之间的所有素数
	14.修改程序，要求输入 max
*/

#include "std_lib_facilities.h"

int main()
{
    int max;
    cin >> max;
    vector<char> primes(max+1, 1);
    for (int i = 0; i < max; ++i)
        primes[i] = 1;
    for (int i = 2; i <= sqrt(max); ++i)
        if (primes[i])
            for (int j = i*2; j <= max; j += i)
                primes[j] = 0;

    for (int i = 2; i <= max; ++i)
        if (primes[i])
            cout << i << ' ';
}