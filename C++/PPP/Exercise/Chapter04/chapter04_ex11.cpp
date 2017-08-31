/*
	11.编写程序找出 1 到 100 之间的所有素数
	12.修改程序，输入值 max，并找出 1 到 max 的所有素数
*/

#include "std_lib_facilities.h"

vector<int> primes;

bool is_prime(int n)
{
    for (int i = 0; primes[i] <= sqrt(n); ++i)
        if (n % primes[i] == 0)
            return false;
    return true;
}

int main()
{
    primes.push_back(2);
    int n;
    cin >> n;
    for (int i = 3; i < n; i += 2)
        if (is_prime(i))
            primes.push_back(i);
    for (int i = 0; i < primes.size(); ++i)
        cout << primes[i] << ' ';
}