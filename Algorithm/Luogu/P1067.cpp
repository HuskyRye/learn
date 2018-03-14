#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a;
    cin >> a;
    if (a == 1)
        ;
    else if (a == -1)
        cout << '-';
    else
        cout << a;
    cout << "x^" << n--;
    for (; n > 0; --n) {
        cin >> a;
        switch (a) {
        case 0:
            continue;
        case 1:
            cout << '+';
            break;
        case -1:
            cout << '-';
            break;
        default:
            cout << showpos<< a;
        }
        if (n == 1)
            cout << 'x';
        else
            cout << "x^" << noshowpos << n;
    }
    cin >> a;
    if (a == 0)
        return 0;
    cout << showpos << a;
    return 0;
}