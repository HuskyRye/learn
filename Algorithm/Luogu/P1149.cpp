#include <iostream>
#include <vector>

using namespace std;

vector<int> matches = { 6,2,5,5,4,5,6,3,7,6 };

void match(int n)
{
    int sum = 0;
    while (n != 0) {
        sum += matches[n%10];
        n /= 10;
    }
    matches.push_back(sum);
}

int main()
{
    int n;
    cin >> n;
    n -= 4;
    for (int i = 10; i < 2001; ++i) {
        match(i);
    }
    int sum = 0;
    for (int i = 0; i < 1000; ++i)
        for (int j = 0; j < 1000; ++j)
            if (n == matches[i]+matches[j]+matches[i+j]) {
                ++sum;
            }
    cout << sum << '\n';
    return 0;
}