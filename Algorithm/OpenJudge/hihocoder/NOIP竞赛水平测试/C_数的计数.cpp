/*
	Date: 2018.3.13
	Author: 刘臣轩
*/

#include <iostream>

using namespace std;

int res[1001] = { 1, 1 };

int num(int n)
{
    if (res[n] != 0)
        return res[n];
    int result = 1;
    for (int i = 1; i <= n / 2; ++i) {
        result += num(i);
    }
    return res[n] = result;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << num(n) << endl;
    return 0;
}
