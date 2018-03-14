/*
    Author: 刘臣轩
    Date: 2017.9.2
*/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;   // 堆
    vector<int> cards(n);
    for (int i = 0; i < n; ++i)
        cin >> cards[i];
    int avg = accumulate(cards.begin(), cards.end(), 0)/n;
    for (int i = 0; i < n; ++i)
        cards[i] -= avg;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (cards[i] == 0)
            continue;
        if (i+1 < n)
            cards[i+1] += cards[i];
        ++count;
    }
    cout << count << '\n';
}