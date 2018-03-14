#include <iostream>
using namespace std;
int main()
{
    double s, x;
    cin >> s >> x;
    int flag = 0;
    double dis = 7;
    while (s >= -x) {
        if (s <= x && s >= -x) {
            ++flag;
        }
        if (flag == 2 && s <= x && s >= -x) {
            cout << "y\n";
            return 0;
        }
        s -= dis;
        // cout << s << ' ';
        dis *= 0.98;
        // cout << dis << '\n';
    }
    cout << "n\n";
    return 0;
}