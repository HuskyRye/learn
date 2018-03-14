#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool prime(int n)
{
    int temp = sqrt(n);
    for (int i = 2; i <= temp; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int k;
    for (int i = 2; i < n; ++i)
        for (int j = 2; (k = n-i-j) >= j; ++j) {
                if (prime(i) && prime(j) && prime(k)) {
                    cout << i << ' ' << j << ' ' << k << '\n';
                    return 0;
                }
            }
}