/*
    Author: 刘臣轩
    Date: 2017.9.4
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string s;
    char ch;
    while (cin >> ch && ch != 'E')
        s += ch;
    int w = 0;
    int l = 0;
    // 11
    for (auto x : s)
    {
        switch(x) {
        case 'W':
            ++w;
            break;
        case 'L':
            ++l;
            break;
        }
        if ((w >= 11 || l >= 11) && abs(w-l)>=2) {
            cout << w << ':' << l << '\n';
            w = 0;
            l = 0;
        }
    }
    cout << w << ':' << l << "\n\n";
    w = 0;
    l = 0;
    
    // 21
    for (auto x : s)
    {
        switch(x) {
        case 'W':
            ++w;
            break;
        case 'L':
            ++l;
            break;
        }
        if ((w >= 21 || l >= 21) && abs(w-l)>=2) {
            cout << w << ':' << l << '\n';
            w = 0;
            l = 0;
        }
    }
    cout << w << ':' << l << '\n';
}
