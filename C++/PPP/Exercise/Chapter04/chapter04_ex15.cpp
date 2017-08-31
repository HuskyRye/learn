/*
	15.编写程序，输入 n，输出前 n 个素数
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
    for (int i = 3; primes.size() < n; i += 2)
        if (is_prime(i))
            primes.push_back(i);
    for (int i = 0; i < primes.size(); ++i)
        cout << primes[i] << ' ';
}