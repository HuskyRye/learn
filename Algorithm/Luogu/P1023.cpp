/*
Author: 刘臣轩
Date: 2017.9.1
*/

#include <iostream>
#include <map>

using namespace std;

int main()
{
    int gov;            // 政府预期价
    cin >> gov;
    map<int, int> m;
    int price, amount;  // 单价和数量
    cin >> price >> amount;
    m[price] = amount;
    int a, b;
    int prev = gov-1;       // 用前后夹击的方式判断是否为最大值
    int succ = gov+1;       // 因为题目保证全都是整数
    while (cin >> a >> b && (a != -1 && b != -1)) {
        int k = (amount-b)/(a-price);       // 斜率
        if (price <= prev && prev <= a)     // 在区间内
            m[prev] = b+(a-prev)*k;         // 斜率求销量
        if (price <= succ && succ <= a)
            m[succ] = b+(a-succ)*k;
        if (price <= gov && gov <= a)
            m[gov] = b+(a-gov)*k;
        amount = b;
        price = a;
    }
    int k;
    cin >> k;
    if (price < prev)
        m[prev] = amount-(prev-price)*k;
    if (price < succ)
        m[succ] = amount-(succ-price)*k;
    if (price < gov)
        m[gov] = amount-(gov-price)*k;

    int min = m.begin()->first;         // 成本价

    for (int i = 0; ; ++i) {            // 补贴
        int a = (prev-min+i)*m[prev];
        int b = (gov-min+i)*m[gov];
        int c = (succ-min+i)*m[succ];
        if (a <= b && b >= c) {         // 是最大
            cout << i << '\n';
            return 0;
        }
        else if (a > b)                 // 不可能是最大了
            break;
    }
    for (int i = -1; ; --i) {           // 收税
        int a = (prev-min+i)*m[prev];
        int b = (gov-min+i)*m[gov];
        int c = (succ-min+i)*m[succ];
        if (a <= b && b >= c) {
            cout << i << '\n';
            return 0;
        }
    }
}
