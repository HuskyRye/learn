/*
	Date: 2018.3.13
	Author: 刘臣轩
*/

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    int m;
    cin >> n >> m;
    int temp;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (temp == m)
            ++count;
    }
    cout << count << endl;
    return 0;
}
