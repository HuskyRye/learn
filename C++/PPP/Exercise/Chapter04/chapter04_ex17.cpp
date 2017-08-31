/*
	16.找出一组字符串）最大和最小的数据和 mode，在一组数据中出现次数最多的数称为 mode
*/

#include "std_lib_facilities.h"
#include <map>

int main()
{
    map<string, int> number;
    for (string s; cin >> s; )
        ++number[s];
    cout << "min: " << number.begin()->first << '\n';
    auto p = number.end();
    cout << "max: " << (--p)->first << '\n';
    string node = number.begin()->first;
    for (auto p = number.begin(); p != number.end(); ++p)
        if (p->second > number[node])
            node = p->first;
    cout << "node: " << node << '\n';
}