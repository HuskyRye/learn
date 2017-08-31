#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

// find
template<typename In, typename T>
In find(In first, In last, const T& val)
{
    while (first != last && *first != val)
        ++first;
    return first;
}

void f(vector<int>& v, int x)
{
    auto p = ::find(v.begin(), v.end(), x);
    if (p != v.end()) {
        // found
    }
}

void f(list<string>& v, string x)
{
    auto p = ::find(v.begin(), v.end(), x);
    if (p != v.end()) {
        // found
    }
}

// find_if
template<typename In, typename Pred>
In find_if(In first, In last, Pred pred)
{
    while (first != last && !pred(*first))
        ++first;
    return first;
}

bool odd(int x) { return x%2; }
void f(vector<int>& v)
{
    auto p = ::find_if(v.begin(), v.end(), odd);
}

// 函数对象
class Larger_than {
    int v;
public:
    Larger_than(int vv) : v { vv } {}
    bool operator()(int x) const { return v; }
};

void g(vector<int>&v, int x)
{
    auto p = ::find_if(v.begin(), v.end(), Larger_than(x));
}

// 类成员上的断言
struct Record {
    string name;
    char addr[24];
};

vector<Record> v;

// lambda
void f()
{
    std::sort(v.begin(), v.end(), [](const Record& a, const Record& b) { return a.name < b.name; });
    std::sort(v.begin(), v.end(), [](const Record& a, const Record& b) { return strncmp(a.addr, b.addr, 24)<0; });
}

void h(vector<int>&v, int x)
{
    auto p = ::find_if(v.begin(), v.end(), [](double a) { return a>31; });
    auto q = ::find_if(v.begin(), v.end(), [&x](double a) { return a>x; }); // 引用捕获
}

// accumulate
template<typename In, typename T>
T accumulate(In first, In last, T init)
{
    while (first != last) {
        init = init + *first;
        ++first;
    }
    return init;
}

void f(vector<double>& vd, int* p, int n)
{
    double sum = accumulate(vd.begin(), vd.end(), 0.0);
    int sum2 = accumulate(p, p+n, 0);
}

// 泛化 accumulate
template<typename In, typename T, typename BinOp>
T accumulate(In first, In last, T init, BinOp op)
{
    while (first != last) {
        init = op(init, *first);
        ++first;
    }
    return init;
}

void f(vector<double>& a)
{
    double sum = accumulate(a.begin(), a.end(), 1.0, multiplies<double>());
}

// example of accumulate
struct Record2 {
    double unit_price;  // 单价
    int units;          // 数量
};

double price(double v, const Record2& r)
{
    return v + r.unit_price*r.units;
}

void f(const vector<Record2>& vr)
{
    double total = accumulate(vr.begin(), vr.end(), 0.0, price);
    double total2 = accumulate(vr.begin(), vr.end(), 0.0, [](double v, const Record2& r) { return v + r.unit_price*r.units; });
}

// inner product
template<typename In, typename In2, typename T>
T inner_product(In first, In last, In2 first2, T init)
{
    while (first != last) {
        init = init + (*first) * (*first2);
        ++first;
        ++first2;
    }
    return init;
}

template<typename In, typename In2, typename T, typename BinOp, typename BinOp2>
T inner_product(In first, In last, In2 first2, T init, BinOp op, BinOp2 op2)
{
    while (first != last) {
        init = op(init, op2(*first, *first2));
        ++first;
        ++first2;
    }
    return init;
}

int main()
{
    return 0;
}