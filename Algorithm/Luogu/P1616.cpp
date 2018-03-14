/*
    Author: 刘臣轩
    Date: 2017.11.11 
*/

#include <iostream>
#include <algorithm>
using namespace std;

int f[100005];
int main() {
    ios::sync_with_stdio(false);
    int t, m;
    cin >> t >> m;
    int a, b;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        for (int j = a; j <= t; ++j)
            f[j] = max(f[j], f[j-a]+b);
    }
    cout << f[t] << endl;
    return 0;
}
