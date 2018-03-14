#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int carpet[10001][4] = { 0 };
    for (int i = 1; i <= n; ++i) {
        cin >> carpet[i][0] >> carpet[i][1] >> carpet[i][2] >> carpet[i][3];
    }
    int x, y;
    cin >> x >> y;
    for (int i = 10000; i > 0; --i) {
        int a = carpet[i][0];
        int b = carpet[i][1];
        if (a<= x &&  b<= y && (a+carpet[i][2]) >= x && (b+carpet[i][3])>=y) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}