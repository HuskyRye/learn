#include "std_lib_facilities.h"

template<typename Iter>
void print(Iter first, Iter last)
{
    cout << "{ ";
    for (Iter p = first; p != last; ++p)
        cout << *p << ' ';
    cout << "}\n";
}

// Drill 6
template<typename Iter1, typename Iter2>
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    while (f1!=e1) {
        *f2 = *f1;
        ++f1;
        ++f2;
    }
    return f2;
}

int main()
{
    const int size = 10;
    // Drill 1
    array<int, size> a;
    for (int i = 0; i < a.size(); ++i)
        a[i] = i;
    print(a.begin(), a.end());

    // Drill 2
    vector<int> v;
    for (int i = 0; i < size; ++i)
        v.push_back(i);
    print(v.begin(), v.end());

    // Drill 3
    list<int> l;
    for (int i = 0; i < size; ++i)
        l.push_back(i);
    print(l.begin(), l.end());

    // Drill 4
    array<int, size> aa { a };
    print(aa.begin(), aa.end());
    vector<int> vv { v };
    print(vv.begin(), vv.end());
    list<int> ll { l };
    print(ll.begin(), ll.end());

    // Drill 5
    for (int& x : a)
        x += 2;
    for (int& x : v)
        x += 3;
    for (int& x : l)
        x += 5;
    print(a.begin(), a.end());
    print(v.begin(), v.end());
    print(l.begin(), l.end());

    // Drill 7
    ::copy(a.begin(), a.end(), v.begin());
    ::copy(l.begin(), l.end(), a.begin());
    print(a.begin(), a.end());
    print(v.begin(), v.end());
    print(l.begin(), l.end());

    // Drill 8
    auto v_pos = std::find(v.begin(), v.end(), 3);
    if (v_pos != v.end())
        cout << "In v, 3 has index " << v_pos-v.begin() << ".\n";

    auto l_pos = std::find(l.begin(), l.end(), 27);
    if (l_pos != l.end()) {
        int index = 0;
        for (auto p = l.begin(); p != l_pos; ++p)
            ++index;
        cout << "In l, 27 has index " << index << ".\n";
    }
    else
        cout << "27 is not in l.\n";

    return 0;
}