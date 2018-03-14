#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    string s;
    string std = "123456789";
    bool flag = true;
    for (int i = 1; i < 329; ++i) {

        int x = a*i;
        int y = b*i;
        int z = c*i;

        s = to_string(x)+to_string(y)+to_string(z);
        sort(s.begin(), s.end());
        if (std == s) {
            flag = false;
            cout << x << ' ' << y << ' ' << z << '\n';
        }
    }
    if (flag)
        cout << "No!!!" << '\n';
    return 0;
}