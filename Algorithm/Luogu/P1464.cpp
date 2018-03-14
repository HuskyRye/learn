#include <iostream>

using namespace std;

int answer[21][21][21] = { 1 };

int w(long long int a, long long int b, long long int c)
{
    int res;
    if (a<=0 || b<=0 || c<=0)
        a = b = c = 0;
    else if (a>20 || b>20 || c>20)
        a = b = c = 20;
    if (answer[a][b][c])
        return answer[a][b][c];
    else if (a<b && b<c)
        res =  w(a, b, c-1)+w(a, b-1, c-1)-w(a, b-1, c);
    else
        res =  w(a-1, b, c)+w(a-1, b-1, c)+w(a-1, b, c-1)-w(a-1, b-1, c-1);
    return answer[a][b][c] = res;
}

int main()
{
    long long int a, b, c;
    int result;
    while (cin >> a >> b >> c && !(a == -1 && b == -1 && c == -1)) {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
}