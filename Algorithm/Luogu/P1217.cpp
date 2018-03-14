#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

void is_prime(int n)
{
    int temp = sqrt(n);
    for (int i = 2; i <= temp; ++i)
        if (n % i == 0)
            return;
    cout << n << '\n';
}

int main()
{
    int m, n;
    cin >> m >> n;
    if (m <= 5)
        cout << 5 << '\n';
    if (m <= 7)
        cout << 7 << '\n';
    if (m <= 11)
        cout << 11 << '\n';
    string min = to_string(m);
    string max = to_string(n);
    int min_size = min.size();
    int max_size = max.size();
    int palindrome;
    if ((min_size<=3) && (max_size>=3)) {
        for (int d1 = 1; d1 <= 9; d1 += 2) {
            for (int d2 = 0; d2 <= 9; ++d2) {
                palindrome = 100*d1 + 10*d2 + d1;
                if (palindrome < m)
                    continue;
                if (palindrome > n)
                    return 0;
                is_prime(palindrome);
            }
        }
    }
    if ((min_size<=5) && (max_size>=5)) {
        for (int d1 = 1; d1 <= 9; d1 += 2) {
            for (int d2 = 0; d2 <= 9; ++d2) {
                for (int d3 = 0; d3 <= 9; ++d3) {
                    palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
                    if (palindrome < m)
                        continue;
                    if (palindrome > n)
                        return 0;
                    is_prime(palindrome);
                }
            }
        }
    }
    if ((min_size<=7) && (max_size>=7)) {
        for (int d1 = 1; d1 <= 9; d1 += 2) {
            for (int d2 = 0; d2 <= 9; ++d2) {
                for (int d3 = 0; d3 <= 9; ++d3) {
                    for (int d4 = 0; d4 <= 9; ++d4) {
                        palindrome = 1000000*d1 + 100000*d2 +10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1;
                        if (palindrome < m)
                            continue;
                        if (palindrome > n)
                            return 0;
                        is_prime(palindrome);
                    }
                }
            }
        }
    }
    return 0;
}