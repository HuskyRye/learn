/*
	16.找出一组输入数据中最大和最小的数据和 mode，在一组数据中出现次数最多的数称为 mode
*/

#include "std_lib_facilities.h"
#include <map>

int main()
{
    map<int, int> number;
    for (int i; cin >> i; )
        ++number[i];
    cout << "min: " << number.begin()->first << '\n';
    auto p = number.end();
    cout << "max: " << (--p)->first << '\n';
    int node = number.begin()->first;
    for (auto p = number.begin(); p != number.end(); ++p)
        if (p->second > number[node])
            node = p->first;
    cout << "node: " << node << '\n';
}