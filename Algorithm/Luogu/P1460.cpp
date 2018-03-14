/*
    Author: 刘臣轩
    Date: 2017.10.23
    Source: USACO Traning Gateway
*/

#include <iostream>
using namespace std;

int v;
int g;

int cow[26];
int vitamin[16][26];
bool answer[16];
int Min;

int a[26];
bool b[16];
int n = 0;

void dfs(int depth)
{
    ++n;
    if (n >= Min || depth > g) {
        --n;
        return;
    }

    b[depth] = true;
    bool ok = true;
    for (int i = 1; i <= v; ++i) {
        a[i] += vitamin[depth][i];
        if (a[i] < cow[i])
            ok = false;
    }

    if (ok) {
        for (int i = 1; i <= g; ++i)
            answer[i] = b[i];
        Min = n;

        b[depth] = false;
        for (int i = 1; i <= v; ++i)
            a[i] -= vitamin[depth][i];
        --n;

        return;
    }

    dfs(depth+1);

    b[depth] = false;
    for (int i = 1; i <= v; ++i)
        a[i] -= vitamin[depth][i];
    --n;

    dfs(depth+1);

    return;
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> v;
    for (int i = 1; i <= v; ++i)
        cin >> cow[i];

    cin >> g;
    Min = g+1;
    for (int i = 1; i <= g; ++i)
        for (int j = 1; j <= v; ++j)
            cin >> vitamin[i][j];

    dfs(1);
    cout << Min << ' ';
    for (int i = 1; i <= g; ++i)
        if (answer[i])
            cout << i << ' ';
    return 0;
}
